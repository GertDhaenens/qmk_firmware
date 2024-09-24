/* Copyright 2022 splitkb.com <support@splitkb.com>
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
#include "transactions.h"

//! @brief The counter to indicate how many keys are currently down
uint8_t key_down_counter;

//! @{
//! @brief Extern functions from our base implementations
extern void render_layer_state( void );
extern void render_mod_status_gui_alt( uint8_t modifiers );
extern void render_mod_status_ctrl_shift( uint8_t modifiers );
//! @}

//! @brief The various layers of our keyboard layout
typedef enum {
    _BASE = 0,
    _SYMBOLS = 1,
    _FUNCTIONS = 2,
    _ADJUST = 3,
} layers_e;

//! @brief The various tap dances we support
typedef enum {
    TD_SHIFT = 0,
} tap_dances_e;

//! @brief The various states a tap dance can be in
typedef enum {
    TDPS_NONE,
    TDPS_HOLD,
    TDPS_SINGLE_TAP,
    TDPS_DOUBLE_TAP,
} tap_dance_press_state_e ;

//! @brief The type of action to use
typedef enum {
    TDA_NONE,
    TDA_KEYCODE,
    TDA_LAYER_MO,
    TDA_LAYER_TO,
    TDA_CAPS_WORD,
} tap_dance_action_e;

//! @brief The state of our press and configuration
typedef struct {
    tap_dance_press_state_e pressState;

    tap_dance_action_e holdAction;
    uint16_t holdKeyCode;

    tap_dance_action_e singleTapAction;
    uint16_t singleTapKeyCode;

    tap_dance_action_e doubleTapAction;
    uint16_t doubleTapKeyCode;

    tap_dance_action_e heldAction;
    uint16_t heldKeyCode;

} tap_dance_press_state_t;

#define TAP_DANCE_PRESS_STATE( _HoldAction, _HoldKC, _SingleTapAction, _SingleTapKC, _DoubleTapAction, _DoubleTapKC ) \
    { TDPS_NONE, _HoldAction, _HoldKC, _SingleTapAction, _SingleTapKC, _DoubleTapAction, _DoubleTapKC, TDA_NONE, KC_NO }

//! @brief The active states of our tap dance
static tap_dance_press_state_t tap_dance_states[] = {
    [TD_SHIFT] =    TAP_DANCE_PRESS_STATE( TDA_KEYCODE, KC_LSFT, TDA_KEYCODE, KC_ESC, TDA_CAPS_WORD, KC_NO ),
};

#define ACTION_TAP_DANCE( _TapDance ) \
    { \
        .fn = { NULL, tap_dance_finished, tap_dance_reset }, \
        .user_data = &tap_dance_states[ _TapDance ] \
    }

//! @{
//! @brief Layer Switching
#define L_BASE      TO( _BASE )
#define L_SYMBL     MO( _SYMBOLS )
#define L_FUNCN     MO( _FUNCTIONS )
//! @}

//! @{
//! @brief Mod-tap keys
#define SFT_ESC     TD(TD_SHIFT)
#define SFT_QUO     MT(MOD_RSFT, KC_QUOTE)
//! @}

//! @{
//! @brief Forward declarations of functions
void tap_dance_finished( tap_dance_state_t* state, void* userData );
void tap_dance_reset( tap_dance_state_t* state, void* userData );
//! @}

// clang-format off
tap_dance_action_t tap_dance_actions[] = {
    ACTION_TAP_DANCE( TD_SHIFT ),
};
// clang-format on


//! @brief The bindings of keys of our various layers
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                   KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS,
        KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                   KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSLS,
        SFT_ESC, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                   KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, SFT_QUO,
        KC_LCTL, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_DEL , _______, KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RCTL,
                                   KC_LALT, KC_LGUI, L_SYMBL, KC_SPACE, KC_SPACE, L_FUNCN, KC_RGUI, KC_RALT
    ),
    [_SYMBOLS] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, KC_EQL ,
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, KC_LCBR, KC_RCBR,
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______, KC_ENT , _______, _______, _______
    ),
    [_FUNCTIONS] = LAYOUT(
        KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,                   KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, KC_LBRC, KC_RBRC,
        _______, _______, KC_END , KC_PGUP, KC_PGDN, KC_HOME,                   KC_LEFT, KC_DOWN, KC_UP  , KC_RIGHT,_______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, KC_BSPC, _______, _______, _______, _______
    ),
    [_ADJUST] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______, _______, _______, _______, _______
    )
};

//! @brief The data for our pomudachi in off mode (mouth closed)
char const PROGMEM pomudachi_off[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x09, 0x91, 0x52, 0x54,
    0x78, 0x54, 0x92, 0x11, 0x09, 0x0D, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x7E, 0x81, 0x00, 0x20, 0x0E, 0x2E, 0x00, 0x00, 0x00, 0x40, 0x40, 0x40,
    0x40, 0x40, 0x40, 0x00, 0x00, 0x00, 0x2E, 0x0E, 0x20, 0x00, 0x81, 0x7E, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x02, 0x46, 0xEC, 0xAC, 0xB8, 0x88, 0x78, 0x18, 0x18,
    0x18, 0x18, 0x78, 0x88, 0xB8, 0xAC, 0xEC, 0x46, 0x02, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
};

//! @brief The data for our pomudachi in on mode (mouth open)
char const PROGMEM pomudachi_on[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x09, 0x91, 0x52, 0x54,
    0x78, 0x54, 0x92, 0x11, 0x09, 0x0D, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x7E, 0x81, 0x00, 0x20, 0x0E, 0x2E, 0x00, 0x00, 0x00, 0x60, 0xA0, 0x20,
    0x20, 0xA0, 0x60, 0x00, 0x00, 0x00, 0x2E, 0x0E, 0x20, 0x00, 0x81, 0x7E, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x02, 0x46, 0xEC, 0xAC, 0xB8, 0x88, 0x78, 0x18, 0x19,
    0x19, 0x18, 0x78, 0x88, 0xB8, 0xAC, 0xEC, 0x46, 0x02, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
};

//! @brief Render our pomudachi artwork based on our key counter state
void render_pomudachi( void )
{
    if( key_down_counter > 0u )
    {
        oled_write_raw_P( pomudachi_on, sizeof( pomudachi_on ) );
        oled_set_cursor( 0, 5 );
    }
    else
    {
        oled_write_raw_P( pomudachi_off, sizeof( pomudachi_off ) );
        oled_set_cursor( 0, 5 );
    }
}

//! @brief Render the WPM of our keyboard
void render_wpm( void )
{
    oled_write_ln_P( PSTR( " WPM:" ), false );
    oled_write_P( PSTR( " " ), false );
    oled_write_P( get_u8_str( get_current_wpm(), '0' ), false );
    oled_write_ln_P( PSTR( "" ), false );
}

//! @brief Function to process the key presses
bool process_record_user
(
    uint16_t keycode,
    keyrecord_t* record
)
{
    if( record->event.type == KEY_EVENT )
    {
        if( record->event.pressed )
        {
            ++key_down_counter;
        }
        else
        {
            if( key_down_counter > 0u )
            {
                --key_down_counter;
            }
        }
    }

    return true;
}

//! @brief Function to process the OLED rendering
bool oled_task_user( void ) {

    render_pomudachi();
    render_wpm();
    render_layer_state();
    render_mod_status_gui_alt(get_mods()|get_oneshot_mods());
    render_mod_status_ctrl_shift(get_mods()|get_oneshot_mods());

    // We override the entire oled rendering
    return false;
}

//! @brief Our RPC handling function from the slave side of the keyboard
void user_sync_a_slave_handler
(
    uint8_t in_buflen,
    void const* in_data,
    uint8_t out_buflen,
    void* out_data
)
{
    // Cache our key down counter for our visualisation
    uint8_t const* const src_keydown_counter = (uint8_t const*) in_data;
    key_down_counter = *src_keydown_counter;
}

//! @brief Called after the keyboard firmware has been initialised
void keyboard_post_init_user( void )
{
    // Initialise our data
    key_down_counter = 0u;

    // Setup our RPC pipe
    transaction_register_rpc( USER_SYNC_A, user_sync_a_slave_handler );
}

//! @brief Called every so often to invoke general logic
void housekeeping_task_user( void )
{
    if( is_keyboard_master() )
    {
        transaction_rpc_send( USER_SYNC_A, sizeof( key_down_counter ), &key_down_counter );
    }
}

//! @brief Trigger a tap dance action
void tap_dance_action( tap_dance_press_state_t* state, tap_dance_action_e action, uint16_t keycode )
{
    switch( action )
    {
        case TDA_KEYCODE:
            register_code16( keycode );
            break;
        case TDA_LAYER_MO:
            layer_on( keycode );
            break;
        case TDA_LAYER_TO:
            layer_move( keycode );
            break;
        case TDA_CAPS_WORD:
            caps_word_on();
            break;
        // Do nothing
        case TDA_NONE:
            break;
    }

    state->heldAction = action;
    state->heldKeyCode = keycode;
}

//! @brief Callback for when a tap dance has finished
void tap_dance_finished( tap_dance_state_t* state, void* userData )
{
    tap_dance_press_state_t* const pressState = (tap_dance_press_state_t*) userData;
    if( state->count == 1u )
    {
        if( state->pressed )
        {
            pressState->pressState = TDPS_HOLD;
        }
        else
        {
            pressState->pressState = TDPS_SINGLE_TAP;
        }
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
            tap_dance_action( pressState, pressState->holdAction, pressState->holdKeyCode );
            break;
        case TDPS_SINGLE_TAP:
            tap_dance_action( pressState, pressState->singleTapAction, pressState->singleTapKeyCode );
            break;
        case TDPS_DOUBLE_TAP:
            tap_dance_action( pressState, pressState->doubleTapAction, pressState->doubleTapKeyCode );
            break;
        // Do nothing
        case TDPS_NONE:
            break;
    }
}

//! @brief Callback for when our tap dance has finished
void tap_dance_reset( tap_dance_state_t* state, void* userData )
{
    tap_dance_press_state_t* const pressState = (tap_dance_press_state_t*) userData;

    switch( pressState->heldAction )
    {
        case TDA_KEYCODE:
            unregister_code16( pressState->heldKeyCode );
            break;
        case TDA_LAYER_MO:
            if( !state->pressed )
            {
                layer_off( pressState->heldKeyCode );
            }
            break;
        // Do nothing
        case TDA_LAYER_TO:
        case TDA_CAPS_WORD:
        case TDA_NONE:
            break;
    }

    // Reset the state
    pressState->pressState = TDPS_NONE;
    pressState->heldKeyCode = KC_NO;
    pressState->heldAction = TDA_NONE;
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
            return true;

        // All other keys disable caps word
        default:
            return false;
    }
}
