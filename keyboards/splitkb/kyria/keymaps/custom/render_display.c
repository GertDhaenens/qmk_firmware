#include QMK_KEYBOARD_H

#include "render_display.h"
#include "math/vector.h"
#include "math/matrix.h"

//-----------------------------------------------------------------------
uint8_t pixelBuffer[ RENDER_DISPLAY_WIDTH * RENDER_DISPLAY_HEIGHT / 8u ];
float rotationState;
uint16_t deltaTimer;
Mat4x4f viewProjection;

//-----------------------------------------------------------------------
static inline
uint8_t*
render_display_get_base_ptr
(
    uint8_t const x,
    uint8_t const y
)
{
    uint16_t const mx = x;
    uint16_t const my = y / 8u;
    uint16_t const address = my * RENDER_DISPLAY_WIDTH + mx;

    return pixelBuffer + address;
}

//-----------------------------------------------------------------------
static inline
uint8_t
render_display_get_bit_index
(
    uint8_t const y
)
{
    return y % 8u;
}

//-----------------------------------------------------------------------
static inline
void
render_display_set_pixel
(
    int32_t const x,
    int32_t const y,
    bool const enabled
)
{
    if( x >= 0 && x < RENDER_DISPLAY_WIDTH
        && y >= 0 && y < RENDER_DISPLAY_HEIGHT )
    {
        uint8_t* const basePtr = render_display_get_base_ptr( x, y );
        uint8_t const bitIndex = render_display_get_bit_index( y );
        uint8_t const bitMask = 1u << bitIndex;
        if( enabled )
        {
            *basePtr |= bitMask;
        }
        else
        {
            *basePtr &= ~bitMask;
        }
    }
}

//-----------------------------------------------------------------------
static inline
void
render_display_clear
(
    void
)
{
    memset( pixelBuffer, 0u, RENDER_DISPLAY_WIDTH * RENDER_DISPLAY_HEIGHT / 8u );
}

//-----------------------------------------------------------------------
static inline
void
render_display_draw_line
(
    Vec2f const p0,
    Vec2f const p1
)
{
    int32_t const dx = (int32_t) p1.x - (int32_t) p0.x;
    int32_t const dy = (int32_t) p1.y - (int32_t) p0.y;

    // Vertical line
    if( dx == 0 )
    {
        uint32_t const by = (uint32_t) math_floor( p0.y );
        uint32_t const ey = (uint32_t) math_ceil( p1.y );
        for( uint32_t y = by; y < ey; ++y )
        {
            render_display_set_pixel( p0.x, y, true );
        }
    }
    // Horizontal line
    else if( dy == 0 )
    {
        uint32_t const bx = (uint32_t) math_floor( p0.x );
        uint32_t const ex = (uint32_t) math_ceil( p1.x );
        for( uint32_t x = bx; x < ex; ++x )
        {
            render_display_set_pixel( x, p0.y, true );
        }
    }
    // Diagonal line
    else
    {
        float mx;
        float my;
        if( abs( dx ) > abs( dy ) )
        {
            mx = ( dx < 0.0f ) ? -1.0f : 1.0f;
            my = (float) dy / (float) abs( dx );
        }
        else
        {
            mx = (float) dx / (float) abs( dy );
            my = ( dy < 0.0f ) ? -1.0f : 1.0f;
        }

        float ax = 0.0f;
        float ay = 0.0f;
        while( (int32_t) ( ax + 0.5f ) != dx
            && (int32_t) ( ay + 0.5f ) != dy )
        {
            int32_t const cx = (int32_t) ( (float) p0.x + ax );
            int32_t const cy = (int32_t) ( (float) p0.y + ay );

            render_display_set_pixel( cx, cy, true );

            ax += mx;
            ay += my;
        }
    }
}

//-----------------------------------------------------------------------
void
render_display_init
(
    void
)
{
    // Clear our display
    render_display_clear();

    // Initialise our state
    rotationState = 0.0f;
    deltaTimer = timer_read();

    // Cache some values that don't change
    Mat4x4f const view = mat4x4f_lookat_lh
    (
        vec3f( 0.0f, 0.0f, -2.0f ),
        vec3f( 0.0f, 0.0f, 1.0f ),
        vec3f( 0.0f, 1.0f, 0.0f )
    );
    Mat4x4f const projection = mat4x4f_perspective_lh
    (
        1.0f, // i_aspectRatio
        math_degrees_to_radians( 60.0f ), //i_fovYInRadians
        0.001f, // i_nearPlane
        10.0f // i_farPlane
    );
    viewProjection = mat4x4f_mul( view, projection );
}

//-----------------------------------------------------------------------
char const*
render_display_get_buffer
(
    void
)
{
    return (char const*) pixelBuffer;
}

//-----------------------------------------------------------------------
void
render_display_update
(
    void
)
{
    // Only update our buffer if our wpm is greater than zero
    // if it's zero, our animation doesn't change so there's no point updating it
    uint8_t const wpm = get_current_wpm();
    if( wpm == 0u )
    {
        return;
    }

    // Clear our existing display
    render_display_clear();

    // Advance our state
    uint16_t const deltaTime = timer_elapsed(deltaTimer);
    float const deltaTimeInSec = (float) deltaTime / 1000.0f;
    deltaTimer = timer_read();
    float const speedPerWPM = 0.1f;
    rotationState += speedPerWPM * deltaTimeInSec * (float) wpm;

    // Calculate our rotation matrix
    Mat3x3f const rotation = mat3x3f_rotate_x( rotationState );

    // Calculate our 8 corner points in NDC coordinates
    //    4----------5
    //   /|        / |
    //  / |       /  |
    // 0---------1   |
    // |  6------|---7
    // | /       | /
    // |/        |/
    // 2---------3
    float const s = 0.5f;
    Vec3f const cornerPoints[] =
    {
        mat4x4f_transform_position( viewProjection, mat3x3f_mul_vec( vec3f( -s, +s, -s ), rotation ) ),
        mat4x4f_transform_position( viewProjection, mat3x3f_mul_vec( vec3f( +s, +s, -s ), rotation ) ),
        mat4x4f_transform_position( viewProjection, mat3x3f_mul_vec( vec3f( -s, -s, -s ), rotation ) ),
        mat4x4f_transform_position( viewProjection, mat3x3f_mul_vec( vec3f( +s, -s, -s ), rotation ) ),
        mat4x4f_transform_position( viewProjection, mat3x3f_mul_vec( vec3f( -s, +s, +s ), rotation ) ),
        mat4x4f_transform_position( viewProjection, mat3x3f_mul_vec( vec3f( +s, +s, +s ), rotation ) ),
        mat4x4f_transform_position( viewProjection, mat3x3f_mul_vec( vec3f( -s, -s, +s ), rotation ) ),
        mat4x4f_transform_position( viewProjection, mat3x3f_mul_vec( vec3f( +s, -s, +s ), rotation ) ),
    };

    // Calculate our pixel coordinates based on our NDC positions
    Vec2f const resolution = {
        .x = (float) RENDER_DISPLAY_WIDTH,
        .y = (float) RENDER_DISPLAY_HEIGHT,
    };
    Vec2f pixelCoords[8u];
    for( uint32_t i = 0u; i < 8u; ++i )
    {
        pixelCoords[i] = (Vec2f) {
            .x = ( ( cornerPoints[i].x + 1.0f ) * 0.5f ) * resolution.x,
            .y = ( 1.0f - ( ( cornerPoints[i].y + 1.0f ) * 0.5f ) ) * resolution.y,
        };
    }

    struct Edge
    {
        uint8_t p0;
        uint8_t p1;
    };
    struct Edge const edges[] = {
        { 0u, 1u },
        { 2u, 3u },
        { 0u, 2u },
        { 1u, 3u },

        { 4u, 5u },
        { 6u, 7u },
        { 4u, 6u },
        { 5u, 7u },

        { 0u, 4u },
        { 1u, 5u },
        { 2u, 6u },
        { 3u, 7u },
    };

    for( uint32_t i = 0u; i < ARRAY_SIZE( edges ); ++i )
    {
        // Calculate our line edge
        Vec2f p0 = pixelCoords[ edges[i].p0 ];
        Vec2f p1 = pixelCoords[ edges[i].p1 ];

        // Draw our line
        render_display_draw_line( p0, p1 );
    }
}
