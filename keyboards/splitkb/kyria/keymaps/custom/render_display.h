#pragma once

//! @brief The width of our image that we are rendering
#define RENDER_DISPLAY_WIDTH     64

//! @brief The height of our image that we are rendering
#define RENDER_DISPLAY_HEIGHT    64

//! @brief Initialise our display buffer
void render_display_init( void );

//! @brief Get the buffer of data to render to the display
char const* render_display_get_buffer( void );
