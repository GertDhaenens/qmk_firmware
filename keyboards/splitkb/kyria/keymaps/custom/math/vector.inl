//!-----------------------------------------------------------------------
//! @file           : vector.inl
//! @author         : Gert Dhaenens
//! @date           : 01-06-2023 21:01
//!-----------------------------------------------------------------------

//-----------------------------------------------------------------------
Vec2f
vec2f
(
    float const i_x,
    float const i_y
)
{
    Vec2f const r = {
        .x = i_x,
        .y = i_y
    };
    return r;
}

//-----------------------------------------------------------------------
Vec3f
vec3f
(
    float const i_x,
    float const i_y,
    float const i_z
)
{
    Vec3f const r = {
        .x = i_x,
        .y = i_y,
        .z = i_z
    };
    return r;
}

//-----------------------------------------------------------------------
Vec4f
vec4f
(
    float const i_x,
    float const i_y,
    float const i_z,
    float const i_w
)
{
    Vec4f const r = {
        .x = i_x,
        .y = i_y,
        .z = i_z,
        .w = i_w
    };
    return r;
}

//-----------------------------------------------------------------------
Vec2f
vec2f_zero
(
    void
)
{
    Vec2f const r = {
        .x = 0.0f,
        .y = 0.0f
    };
    return r;
}

//-----------------------------------------------------------------------
Vec3f
vec3f_zero
(
    void
)
{
    Vec3f const r = {
        .x = 0.0f,
        .y = 0.0f,
        .z = 0.0f
    };
    return r;
}

//-----------------------------------------------------------------------
Vec4f
vec4f_zero
(
    void
)
{
    Vec4f const r = {
        .x = 0.0f,
        .y = 0.0f,
        .z = 0.0f,
        .w = 0.0f
    };
    return r;
}

//-----------------------------------------------------------------------
Vec2f
vec2f_one
(
    void
)
{
    Vec2f const r = {
        .x = 1.0f,
        .y = 1.0f
    };
    return r;
}

//-----------------------------------------------------------------------
Vec3f
vec3f_one
(
    void
)
{
    Vec3f const r = {
        .x = 1.0f,
        .y = 1.0f,
        .z = 1.0f
    };
    return r;
}

//-----------------------------------------------------------------------
Vec4f
vec4f_one
(
    void
)
{
    Vec4f const r = {
        .x = 1.0f,
        .y = 1.0f,
        .z = 1.0f,
        .w = 1.0f
    };
    return r;
}

//-----------------------------------------------------------------------
Vec2f
vec2f_unit_x
(
    void
)
{
    Vec2f const r = {
        .x = 1.0f,
        .y = 0.0f
    };
    return r;
}

//-----------------------------------------------------------------------
Vec3f
vec3f_unit_x
(
    void
)
{
    Vec3f const r = {
        .x = 1.0f,
        .y = 0.0f,
        .z = 0.0f
    };
    return r;
}

//-----------------------------------------------------------------------
Vec4f
vec4f_unit_x
(
    void
)
{
    Vec4f const r = {
        .x = 1.0f,
        .y = 0.0f,
        .z = 0.0f,
        .w = 0.0f
    };
    return r;
}

//-----------------------------------------------------------------------
Vec2f
vec2f_unit_y
(
    void
)
{
    Vec2f const r = {
        .x = 0.0f,
        .y = 1.0f
    };
    return r;
}

//-----------------------------------------------------------------------
Vec3f
vec3f_unit_y
(
    void
)
{
    Vec3f const r = {
        .x = 0.0f,
        .y = 1.0f,
        .z = 0.0f
    };
    return r;
}

//-----------------------------------------------------------------------
Vec4f
vec4f_unit_y
(
    void
)
{
    Vec4f const r = {
        .x = 0.0f,
        .y = 1.0f,
        .z = 0.0f,
        .w = 0.0f
    };
    return r;
}

//-----------------------------------------------------------------------
Vec3f
vec3f_unit_z
(
    void
)
{
    Vec3f const r = {
        .x = 0.0f,
        .y = 0.0f,
        .z = 1.0f
    };
    return r;
}

//-----------------------------------------------------------------------
Vec4f
vec4f_unit_z
(
    void
)
{
    Vec4f const r = {
        .x = 0.0f,
        .y = 0.0f,
        .z = 1.0f,
        .w = 0.0f
    };
    return r;
}

//-----------------------------------------------------------------------
Vec4f
vec4f_unit_w
(
    void
)
{
    Vec4f const r = {
        .x = 0.0f,
        .y = 0.0f,
        .z = 0.0f,
        .w = 1.0f
    };
    return r;
}

//-----------------------------------------------------------------------
Vec2f
vec2f_add
(
    Vec2f const i_a,
    Vec2f const i_b
)
{
    Vec2f const r = {
        .x = i_a.x + i_b.x,
        .y = i_a.y + i_b.y
    };
    return r;
}

//-----------------------------------------------------------------------
Vec3f
vec3f_add
(
    Vec3f const i_a,
    Vec3f const i_b
)
{
    Vec3f const r = {
        .x = i_a.x + i_b.x,
        .y = i_a.y + i_b.y,
        .z = i_a.z + i_b.z
    };
    return r;
}

//-----------------------------------------------------------------------
Vec4f
vec4f_add
(
    Vec4f const i_a,
    Vec4f const i_b
)
{
    Vec4f const r = {
        .x = i_a.x + i_b.x,
        .y = i_a.y + i_b.y,
        .z = i_a.z + i_b.z,
        .w = i_a.w + i_b.w
    };
    return r;
}

//-----------------------------------------------------------------------
Vec2f
vec2f_sub
(
    Vec2f const i_a,
    Vec2f const i_b
)
{
    Vec2f const r = {
        .x = i_a.x - i_b.x,
        .y = i_a.y - i_b.y
    };
    return r;
}

//-----------------------------------------------------------------------
Vec3f
vec3f_sub
(
    Vec3f const i_a,
    Vec3f const i_b
)
{
    Vec3f const r = {
        .x = i_a.x - i_b.x,
        .y = i_a.y - i_b.y,
        .z = i_a.z - i_b.z
    };
    return r;
}

//-----------------------------------------------------------------------
Vec4f
vec4f_sub
(
    Vec4f const i_a,
    Vec4f const i_b
)
{
    Vec4f const r = {
        .x = i_a.x - i_b.x,
        .y = i_a.y - i_b.y,
        .z = i_a.z - i_b.z,
        .w = i_a.w - i_b.w
    };
    return r;
}

//-----------------------------------------------------------------------
Vec2f
vec2f_mul
(
    Vec2f const i_a,
    Vec2f const i_b
)
{
    Vec2f const r = {
        .x = i_a.x * i_b.x,
        .y = i_a.y * i_b.y
    };
    return r;
}

//-----------------------------------------------------------------------
Vec3f
vec3f_mul
(
    Vec3f const i_a,
    Vec3f const i_b
)
{
    Vec3f const r = {
        .x = i_a.x * i_b.x,
        .y = i_a.y * i_b.y,
        .z = i_a.z * i_b.z
    };
    return r;
}

//-----------------------------------------------------------------------
Vec4f
vec4f_mul
(
    Vec4f const i_a,
    Vec4f const i_b
)
{
    Vec4f const r = {
        .x = i_a.x * i_b.x,
        .y = i_a.y * i_b.y,
        .z = i_a.z * i_b.z,
        .w = i_a.w * i_b.w
    };
    return r;
}

//-----------------------------------------------------------------------
Vec2f
vec2f_div
(
    Vec2f const i_a,
    Vec2f const i_b
)
{
    assert( vec2f_all_non_zero( i_b ) );
    Vec2f const r = {
        .x = i_a.x / i_b.x,
        .y = i_a.y / i_b.y
    };
    return r;
}

//-----------------------------------------------------------------------
Vec3f
vec3f_div
(
    Vec3f const i_a,
    Vec3f const i_b
)
{
    assert( vec3f_all_non_zero( i_b ) );
    Vec3f const r = {
        .x = i_a.x / i_b.x,
        .y = i_a.y / i_b.y,
        .z = i_a.z / i_b.z
    };
    return r;
}

//-----------------------------------------------------------------------
Vec4f
vec4f_div
(
    Vec4f const i_a,
    Vec4f const i_b
)
{
    assert( vec4f_all_non_zero( i_b ) );
    Vec4f const r = {
        .x = i_a.x / i_b.x,
        .y = i_a.y / i_b.y,
        .z = i_a.z / i_b.z,
        .w = i_a.w / i_b.w
    };
    return r;
}

//-----------------------------------------------------------------------
float
vec2f_length
(
    Vec2f const i_a
)
{
    return sqrtf( vec2f_length_squared( i_a ) );
}

//-----------------------------------------------------------------------
float
vec3f_length
(
    Vec3f const i_a
)
{
    return sqrtf( vec3f_length_squared( i_a ) );
}

//-----------------------------------------------------------------------
float
vec4f_length
(
    Vec4f const i_a
)
{
    return sqrtf( vec4f_length_squared( i_a ) );
}

//-----------------------------------------------------------------------
float
vec2f_length_squared
(
    Vec2f const i_a
)
{
    return ( i_a.x * i_a.x + i_a.y * i_a.y );
}

//-----------------------------------------------------------------------
float
vec3f_length_squared
(
    Vec3f const i_a
)
{
    return ( i_a.x * i_a.x + i_a.y * i_a.y + i_a.z * i_a.z );
}

//-----------------------------------------------------------------------
float
vec4f_length_squared
(
    Vec4f const i_a
)
{
    return ( i_a.x * i_a.x + i_a.y * i_a.y + i_a.z * i_a.z + i_a.w * i_a.w );
}

//-----------------------------------------------------------------------
Vec2f
vec2f_normalise
(
    Vec2f const i_a
)
{
    float const length = vec2f_length( i_a );
    assert( length != 0.0f );
    return vec2f_div( i_a, vec2f_splat( length ) );
}

//-----------------------------------------------------------------------
Vec3f
vec3f_normalise
(
    Vec3f const i_a
)
{
    float const length =  vec3f_length( i_a );
    assert( length != 0.0f );
    return vec3f_div( i_a, vec3f_splat( length ) );
}

//-----------------------------------------------------------------------
Vec4f
vec4f_normalise
(
    Vec4f const i_a
)
{
    float const length =  vec4f_length( i_a );
    assert( length != 0.0f );
    return vec4f_div( i_a, vec4f_splat( length ) );
}

//-----------------------------------------------------------------------
Vec2f
vec2f_splat
(
    float const i_a
)
{
    return (Vec2f) {
        .x = i_a,
        .y = i_a,
    };
}

//-----------------------------------------------------------------------
Vec3f
vec3f_splat
(
    float const i_a
)
{
    return (Vec3f) {
        .x = i_a,
        .y = i_a,
        .z = i_a,
    };
}

//-----------------------------------------------------------------------
Vec4f
vec4f_splat
(
    float const i_a
)
{
    return (Vec4f) {
        .x = i_a,
        .y = i_a,
        .z = i_a,
        .w = i_a,
    };
}

//-----------------------------------------------------------------------
float
vec2f_dot
(
    Vec2f const i_a,
    Vec2f const i_b
)
{
    return i_a.x * i_b.x + i_a.y * i_b.y;
}

//-----------------------------------------------------------------------
float
vec3f_dot
(
    Vec3f const i_a,
    Vec3f const i_b
)
{
    return i_a.x * i_b.x + i_a.y * i_b.y + i_a.z * i_b.z;
}

//-----------------------------------------------------------------------
float
vec4f_dot
(
    Vec4f const i_a,
    Vec4f const i_b
)
{
    return i_a.x * i_b.x + i_a.y * i_b.y + i_a.z * i_b.z + i_a.w * i_b.w;
}

//-----------------------------------------------------------------------
Vec3f
vec3f_cross
(
    Vec3f const i_a,
    Vec3f const i_b
)
{
    return (Vec3f) {
        .x = i_a.y * i_b.z - i_a.z * i_b.y,
        .y = i_a.z * i_b.x - i_a.x * i_b.z,
        .z = i_a.x * i_b.y - i_a.y * i_b.x
    };
}

//-----------------------------------------------------------------------
Vec3f
vec3f_reflect
(
    Vec3f const i_incindent,
    Vec3f const i_normal
)
{
    return vec3f_sub( i_incindent, vec3f_mul( vec3f_splat( vec3f_dot( i_incindent, i_normal ) * 2.0f ), i_normal ) );
}

//-----------------------------------------------------------------------
Vec3f
vec3f_refract
(
    Vec3f const i_incindent,
    Vec3f const i_normal,
    float const i_iorRatio
)
{
    float const cosTheta = math_min( vec3f_dot( vec3f_mul( vec3f_splat( -1.0f ), i_incindent ), i_normal ), 1.0f );
    Vec3f const exitPerp = vec3f_mul( vec3f_splat( i_iorRatio ), vec3f_add( i_incindent, vec3f_mul( vec3f_splat( cosTheta ), i_normal ) ) );
    Vec3f const exitPara = vec3f_mul( vec3f_splat( -sqrtf( fabsf( 1.0f - vec3f_length_squared( exitPerp ) ) ) ), i_normal );
    return vec3f_add( exitPerp, exitPara );
}

//-----------------------------------------------------------------------
float
vec3f_reflectance
(
    Vec3f const i_incindent,
    Vec3f const i_normal,
    float const i_iorRatio
)
{
    // Schlick's approximation
    // https://en.wikipedia.org/wiki/Schlick%27s_approximation
    float const cosTheta = math_min( vec3f_dot( vec3f_mul( vec3f_splat( -1.0f ), i_incindent ), i_normal ), 1.0f );
    float const r0_base = ( 1.0f - i_iorRatio ) / ( 1.0f + i_iorRatio );
    float const r0 = r0_base * r0_base;
    return r0 + ( 1.0f - r0 ) * powf( 1.0f - cosTheta, 5.0f );
}

//-----------------------------------------------------------------------
Vec2f
vec2f_lerp
(
    Vec2f const i_a,
    Vec2f const i_b,
    float const i_t
)
{
    assert( i_t >= 0.0f && i_t <= 1.0f );
    return (Vec2f) {
        .x = math_lerp( i_a.x, i_b.x, i_t ),
        .y = math_lerp( i_a.y, i_b.y, i_t )
    };
}

//-----------------------------------------------------------------------
Vec3f
vec3f_lerp
(
    Vec3f const i_a,
    Vec3f const i_b,
    float const i_t
)
{
    assert( i_t >= 0.0f && i_t <= 1.0f );
    return (Vec3f) {
        .x = math_lerp( i_a.x, i_b.x, i_t ),
        .y = math_lerp( i_a.y, i_b.y, i_t ),
        .z = math_lerp( i_a.z, i_b.z, i_t ),
    };
}

//-----------------------------------------------------------------------
Vec4f
vec4f_lerp
(
    Vec4f const i_a,
    Vec4f const i_b,
    float const i_t
)
{
    assert( i_t >= 0.0f && i_t <= 1.0f );
    return (Vec4f) {
        .x = math_lerp( i_a.x, i_b.x, i_t ),
        .y = math_lerp( i_a.y, i_b.y, i_t ),
        .z = math_lerp( i_a.z, i_b.z, i_t ),
        .w = math_lerp( i_a.w, i_b.w, i_t )
    };
}

//-----------------------------------------------------------------------
Vec2f
vec2f_min
(
    Vec2f const i_a,
    Vec2f const i_b
)
{
    return (Vec2f) {
        .x = math_min( i_a.x, i_b.x ),
        .y = math_min( i_a.y, i_b.y )
    };
}

//-----------------------------------------------------------------------
Vec3f
vec3f_min
(
    Vec3f const i_a,
    Vec3f const i_b
)
{
    return (Vec3f) {
        .x = math_min( i_a.x, i_b.x ),
        .y = math_min( i_a.y, i_b.y ),
        .z = math_min( i_a.z, i_b.z ),
    };
}

//-----------------------------------------------------------------------
Vec4f
vec4f_min
(
    Vec4f const i_a,
    Vec4f const i_b
)
{
    return (Vec4f) {
        .x = math_min( i_a.x, i_b.x ),
        .y = math_min( i_a.y, i_b.y ),
        .z = math_min( i_a.z, i_b.z ),
        .w = math_min( i_a.w, i_b.w ),
    };
}

//-----------------------------------------------------------------------
Vec2f
vec2f_max
(
    Vec2f const i_a,
    Vec2f const i_b
)
{
    return (Vec2f) {
        .x = math_max( i_a.x, i_b.x ),
        .y = math_max( i_a.y, i_b.y ),
    };
}

//-----------------------------------------------------------------------
Vec3f
vec3f_max
(
    Vec3f const i_a,
    Vec3f const i_b
)
{
    return (Vec3f) {
        .x = math_max( i_a.x, i_b.x ),
        .y = math_max( i_a.y, i_b.y ),
        .z = math_max( i_a.z, i_b.z ),
    };
}

//-----------------------------------------------------------------------
Vec4f
vec4f_max
(
    Vec4f const i_a,
    Vec4f const i_b
)
{
    return (Vec4f) {
        .x = math_max( i_a.x, i_b.x ),
        .y = math_max( i_a.y, i_b.y ),
        .z = math_max( i_a.z, i_b.z ),
        .w = math_max( i_a.w, i_b.w ),
    };
}

//-----------------------------------------------------------------------
float
vec2f_distance
(
    Vec2f const i_a,
    Vec2f const i_b
)
{
    return vec2f_length( vec2f_sub( i_b, i_a ) );
}

//-----------------------------------------------------------------------
float
vec3f_distance
(
    Vec3f const i_a,
    Vec3f const i_b
)
{
    return vec3f_length( vec3f_sub( i_b, i_a ) );
}

//-----------------------------------------------------------------------
float
vec4f_distance
(
    Vec4f const i_a,
    Vec4f const i_b
)
{
    return vec4f_length( vec4f_sub( i_b, i_a ) );
}

//-----------------------------------------------------------------------
float
vec2f_distance_squared
(
    Vec2f const i_a,
    Vec2f const i_b
)
{
    return vec2f_length_squared( vec2f_sub( i_b, i_a ) );
}

//-----------------------------------------------------------------------
float
vec3f_distance_squared
(
    Vec3f const i_a,
    Vec3f const i_b
)
{
    return vec3f_length_squared( vec3f_sub( i_b, i_a ) );
}

//-----------------------------------------------------------------------
float
vec4f_distance_squared
(
    Vec4f const i_a,
    Vec4f const i_b
)
{
    return vec4f_length_squared( vec4f_sub( i_b, i_a ) );
}

//-----------------------------------------------------------------------
bool
vec2f_all_zero
(
    Vec2f const i_a
)
{
    if( i_a.x == 0.0f
        && i_a.y == 0.0f )
    {
        return true;
    }
    else
    {
        return false;
    }
}

//-----------------------------------------------------------------------
bool
vec3f_all_zero
(
    Vec3f const i_a
)
{
    if( i_a.x == 0.0f
        && i_a.y == 0.0f
        && i_a.z == 0.0f )
    {
        return true;
    }
    else
    {
        return false;
    }
}

//-----------------------------------------------------------------------
bool
vec4f_all_zero
(
    Vec4f const i_a
)
{
    if( i_a.x == 0.0f
        && i_a.y == 0.0f
        && i_a.z == 0.0f
        && i_a.w == 0.0f )
    {
        return true;
    }
    else
    {
        return false;
    }
}

//-----------------------------------------------------------------------
bool
vec2f_all_non_zero
(
    Vec2f const i_a
)
{
    if( i_a.x != 0.0f
        && i_a.y != 0.0f )
    {
        return true;
    }
    else
    {
        return false;
    }
}

//-----------------------------------------------------------------------
bool
vec3f_all_non_zero
(
    Vec3f const i_a
)
{
    if( i_a.x != 0.0f
        && i_a.y != 0.0f
        && i_a.z != 0.0f )
    {
        return true;
    }
    else
    {
        return false;
    }
}

//-----------------------------------------------------------------------
bool
vec4f_all_non_zero
(
    Vec4f const i_a
)
{
    if( i_a.x != 0.0f
        && i_a.y != 0.0f
        && i_a.z != 0.0f
        && i_a.w != 0.0f )
    {
        return true;
    }
    else
    {
        return false;
    }
}

//-----------------------------------------------------------------------
bool
vec2f_all_greater_equal
(
    Vec2f const i_a,
    Vec2f const i_b
)
{
    if( i_a.x >= i_b.x
        && i_a.y >= i_b.y )
    {
        return true;
    }
    else
    {
        return false;
    }
}

//-----------------------------------------------------------------------
bool
vec3f_all_greater_equal
(
    Vec3f const i_a,
    Vec3f const i_b
)
{
    if( i_a.x >= i_b.x
        && i_a.y >= i_b.y
        && i_a.z >= i_b.z )
    {
        return true;
    }
    else
    {
        return false;
    }
}

//-----------------------------------------------------------------------
bool
vec4f_all_greater_equal
(
    Vec4f const i_a,
    Vec4f const i_b
)
{
    if( i_a.x >= i_b.x
        && i_a.y >= i_b.y
        && i_a.z >= i_b.z
        && i_a.w >= i_b.w )
    {
        return true;
    }
    else
    {
        return false;
    }
}

//-----------------------------------------------------------------------
bool
vec2f_all_lesser_equal
(
    Vec2f const i_a,
    Vec2f const i_b
)
{
    if( i_a.x <= i_b.x
        && i_a.y <= i_b.y )
    {
        return true;
    }
    else
    {
        return false;
    }
}

//-----------------------------------------------------------------------
bool
vec3f_all_lesser_equal
(
    Vec3f const i_a,
    Vec3f const i_b
)
{
    if( i_a.x <= i_b.x
        && i_a.y <= i_b.y
        && i_a.z <= i_b.z )
    {
        return true;
    }
    else
    {
        return false;
    }
}

//-----------------------------------------------------------------------
bool
vec4f_all_lesser_equal
(
    Vec4f const i_a,
    Vec4f const i_b
)
{
    if( i_a.x <= i_b.x
        && i_a.y <= i_b.y
        && i_a.z <= i_b.z
        && i_a.w <= i_b.w )
    {
        return true;
    }
    else
    {
        return false;
    }
}
