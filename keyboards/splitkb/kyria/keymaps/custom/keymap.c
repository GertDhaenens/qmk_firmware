/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#include "render_display.h"

//! @brief The layers that our keyboard supports
typedef enum {
    _BASE = 0,
    _SYMBOLS,
    _NUMBERS,
    _NUMBERS_PERM,
    _NAVIGATE,
    _NAVIGATE_PERM,
    _FUNCTION,
    _MEDIA,
} layers_e;

//! @brief The various tap dances we support
typedef enum {
    TD_NUMBERS = 0,
    TD_NAVIGATE,
} tap_dances_e;

//! @brief The various states a tap dance can be in
typedef enum {
    TDPS_NONE,
    TDPS_HOLD,
    TDPS_DOUBLE_TAP,
} tap_dance_press_state_e ;

typedef struct {
    tap_dance_press_state_e pressState;
    uint8_t holdLayer;
    uint8_t permLayer;
} tap_dance_press_state_t;

//! @brief The active states of our tap dance
static tap_dance_press_state_t tap_dance_states[] = {
    { TDPS_NONE, _NUMBERS, _NUMBERS_PERM },
    { TDPS_NONE, _NAVIGATE, _NAVIGATE_PERM },
};

#define ACTION_TAP_DANCE_LAYER( _TapDance ) \
    { \
        .fn = { NULL, tap_dance_finished, tap_dance_reset }, \
        .user_data = &tap_dance_states[ _TapDance ] \
    }

//! @{
//! @brief Layer Switching
#define L_BASE      TO( _BASE )
#define L_SYMBL     MO( _SYMBOLS )
#define L_NUMBR     TD( TD_NUMBERS )
#define L_NAVIG     TD( TD_NAVIGATE )
#define L_FUNCN     MO( _FUNCTION )
#define L_MEDIA     MO( _MEDIA )
//! @}

//! @{
//! @brief Mod-tap keys
#define CTL_ESC     MT(MOD_LCTL, KC_ESC)
#define CTL_QUO     MT(MOD_RCTL, KC_QUOTE)
//! @}

//! @{
//! @brief Forward declarations of functions
void tap_dance_finished( tap_dance_state_t* state, void* userData );
void tap_dance_reset( tap_dance_state_t* state, void* userData );
//! @}

// clang-format off
tap_dance_action_t tap_dance_actions[] = {
    ACTION_TAP_DANCE_LAYER( TD_NUMBERS ),
    ACTION_TAP_DANCE_LAYER( TD_NAVIGATE ),
};
// clang-format on

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |   Z  |   X  |   C  |   V  |   B  |      |      |  |      |      |   N  |   M  |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      | SPC  |  | SPC  | SYMB |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_BASE] = LAYOUT(
        KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                                     KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC,
        CTL_ESC, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                                     KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, CTL_QUO,
        KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , L_MEDIA, _______, KC_DEL , L_FUNCN, KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
                                   KC_LALT, KC_LGUI, L_NUMBR, KC_SPC , L_NAVIG, KC_ENT , KC_SPC , L_SYMBL, KC_RGUI, KC_RALT
    ),
/*
 * Symbols Layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SYMBOLS] = LAYOUT(
      KC_TILD, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,                                     KC_CIRC, KC_AMPR, KC_ASTR, KC_LBRC, KC_RBRC, KC_PIPE,
      _______, _______, _______, _______, _______, _______,                                     KC_EQL , KC_UNDS, KC_LPRN, KC_RPRN, KC_COLN, KC_DQUO,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LABK, KC_RABK, KC_QUES, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
/*
 * Numbers Layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NUMBERS] = LAYOUT(
      KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                                     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSLS,
      _______, _______, _______, _______, _______, _______,                                     KC_PLUS, KC_MINS, KC_LCBR, KC_RCBR, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_NUMBERS_PERM] = LAYOUT(
      _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                                     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSPC,
      L_BASE , _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
/*
 * Navigation Layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NAVIGATE] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, KC_DEL ,
      _______, _______, _______, _______, _______, _______,                                     KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [_NAVIGATE_PERM] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, KC_DEL ,
      L_BASE , _______, _______, _______, _______, _______,                                     KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
/*
 * Function Layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_FUNCTION] = LAYOUT(
      _______, _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  ,                                     _______, _______, _______, _______, _______, _______,
      L_BASE , _______, KC_F5  , KC_F6  , KC_F7  , KC_F8  ,                                     _______, _______, _______, _______, _______, _______,
      _______, _______, KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
/*
 * Media Layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_MEDIA] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     KC_MUTE, _______, KC_MPLY, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                                     KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

//! @brief Callback for when the keyboard has finished initialising
void keyboard_post_init_user( void )
{
    // Set the initial values for all of our leds
    rgblight_sethsv( RGBLIGHT_DEFAULT_HUE, RGBLIGHT_DEFAULT_SAT, RGBLIGHT_DEFAULT_VAL );

    // Flush our led state
    rgblight_set();

    // Initialise our rendering display
    render_display_init();
}

//! @brief Write a label and number to the screen
void oled_write_label_u8( char const* label, uint8_t value )
{
    oled_write_P( label, false );
    oled_write_P( PSTR( ":" ), false );
    oled_write_P( PSTR( get_u8_str( value, '0' ) ), false );
    oled_write_P( PSTR( "\n" ), false );
}

//! @brief The callback for rendering the OLED
bool oled_task_user( void )
{
    // Update our rendering before we render it to our oled
    render_display_update();

    // Clear all previous rendering
    oled_clear();

    // Calculate our offsets based on if we're left or right split
    // The left split wants to render our image on the left and text on the right
    // While the right split wants to render our text on the left and image on the right
    uint8_t const textColumnCount = ( RENDER_DISPLAY_WIDTH + OLED_FONT_WIDTH - 1 ) / OLED_FONT_WIDTH;
    uint8_t const imageOffset = ( is_keyboard_left() ) ? 0u : ( textColumnCount * OLED_FONT_WIDTH );
    uint8_t const columnOffset = ( is_keyboard_left() ) ? textColumnCount : 2u;

    // We manually keep track of our line and set the cursor in order to not overwrite our image
    // We start a couple of lines down in order to make it look a bit nicer
    uint16_t lineOffset = 2u;

    // Layer
    oled_set_cursor( columnOffset, lineOffset++ );
    oled_write_P(PSTR("Layer: "), false);
    oled_set_cursor( columnOffset, lineOffset++ );
    switch (get_highest_layer(layer_state | default_layer_state))
    {
        case _BASE:
            oled_write_P(PSTR("Base"), false);
            break;
        case _SYMBOLS:
            oled_write_P(PSTR("Symbols"), false);
            break;
        case _NUMBERS:
        case _NUMBERS_PERM:
            oled_write_P(PSTR("Numbers"), false);
            break;
        case _NAVIGATE:
        case _NAVIGATE_PERM:
            oled_write_P(PSTR("Navigate"), false);
            break;
        case _FUNCTION:
            oled_write_P(PSTR("Function"), false);
            break;
        case _MEDIA:
            oled_write_P(PSTR("Media"), false);
            break;
    }

    // WPM
    oled_set_cursor( columnOffset, lineOffset++ );
    oled_write_label_u8( PSTR( "WPM" ), get_current_wpm() );

    // Manually render our image after our labels since some of them render blank lines
    // This image is 64x64 on our 128x64 display so takes up the entire left side
    // The memory in the buffer is aligned in the same way as our display, so we can
    // safely send the data to our oled driver one line at a time
    char const* const imageMemory = render_display_get_buffer();
    for( uint16_t y = 0u; y < OLED_DISPLAY_HEIGHT; y += 8u )
    {
        uint16_t const srcLineAddress = y * RENDER_DISPLAY_WIDTH / 8u;
        uint16_t const destLineAddress = y * OLED_DISPLAY_WIDTH / 8u;

        for( uint16_t x = 0u; x < RENDER_DISPLAY_WIDTH; ++x )
        {
            uint16_t const srcAddress = srcLineAddress + x;
            uint16_t const destAddress = imageOffset + destLineAddress + x;

            oled_write_raw_byte( imageMemory[ srcAddress ], destAddress );
        }
    }

    // We override the default OLED rendering
    return false;
}

//! @brief Callback for when a tap dance has finished
void tap_dance_finished( tap_dance_state_t* state, void* userData )
{
    tap_dance_press_state_t* const pressState = (tap_dance_press_state_t*) userData;
    if( state->count == 1u )
    {
        pressState->pressState = TDPS_HOLD;
    }
    else if( state->count == 2u )
    {
        pressState->pressState = TDPS_DOUBLE_TAP;
    }
    else
    {
        pressState->pressState = TDPS_NONE;
    }

    switch( pressState->pressState )
    {
        case TDPS_HOLD:
            layer_on( pressState->holdLayer );
            break;
        case TDPS_DOUBLE_TAP:
            layer_move( pressState->permLayer );
            break;
        case TDPS_NONE:
            // Do nothing
            break;
    }
}

//! @brief Callback for when our tap dance has finished
void tap_dance_reset( tap_dance_state_t* state, void* userData )
{
    tap_dance_press_state_t* const pressState = (tap_dance_press_state_t*) userData;

    // If it was a single tap - turn off the layer
    if( pressState->pressState == TDPS_HOLD )
    {
        layer_off( pressState->holdLayer );
    }

    // Reset the state
    pressState->pressState = TDPS_NONE;
}

//! @brief Callback for when we switch layers
layer_state_t layer_state_set_user( layer_state_t state )
{
    // Switch our RGB to indicate that we are in a permanent layer
    if( layer_state_cmp( state, _NUMBERS_PERM ) || layer_state_cmp( state, _NAVIGATE_PERM ) )
    {
        rgblight_sethsv( HSV_WHITE );
    }
    // Else just use the default colour
    else
    {
        rgblight_sethsv( RGBLIGHT_DEFAULT_HUE, RGBLIGHT_DEFAULT_SAT, RGBLIGHT_DEFAULT_VAL );
    }

    return state;
}

//! @brief Callback for caps word functionality
bool caps_word_press_user( uint16_t keycode )
{
    // Return true to keep caps word enabled,
    // Return false to disable caps word
    // If a key should be modified, use `add_weak_mods`

    switch (keycode)
    {
        // Keys to be shifted
        case KC_A ... KC_Z:
        case KC_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));
            return true;

        // Keys to not shift but keep caps word enabled
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case L_NUMBR:
            return true;

        // All other keys disable caps word
        default:
            return false;
    }
}
