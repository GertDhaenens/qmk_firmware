#include QMK_KEYBOARD_H

#include "render_display.h"

//-----------------------------------------------------------------------
char pixel_buffer[ RENDER_DISPLAY_WIDTH * RENDER_DISPLAY_HEIGHT / 8u ];

//-----------------------------------------------------------------------
void
render_display_init
(
    void
)
{
    for( uint16_t y = 0u; y < RENDER_DISPLAY_HEIGHT; y += 8u )
    {
        for( uint16_t x = 0u; x < RENDER_DISPLAY_WIDTH; x += 1u )
        {
            uint16_t const mx = x;
            uint16_t const my = y / 8u;
            uint16_t const address = my * RENDER_DISPLAY_WIDTH + mx;

            char const pattern = ( x & 1u ) ? 0xAA : 0x55;

            pixel_buffer[ address ] = pattern;
        }
    }
}

//-----------------------------------------------------------------------
char const*
render_display_get_buffer
(
    void
)
{
    return pixel_buffer;
}
