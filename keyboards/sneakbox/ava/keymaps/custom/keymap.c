/* Copyright 2024 Gert Dhaenens <dhaenens.gert@hotmail.com>
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

//! @brief The layers that our keyboard supports
typedef enum {
    L_BASE = 0,
    L_FUNC,
} layers_e;

//! @brief The various tap dances we support
typedef enum {
    TD_ESC = 0,
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
    [TD_ESC] =    TAP_DANCE_PRESS_STATE( TDA_LAYER_MO, L_FUNC, TDA_KEYCODE, KC_ESC, TDA_CAPS_WORD, KC_NO ),
};

//! @brief Utility to define a tap dance function
#define ACTION_TAP_DANCE( _TapDance ) \
    { \
        .fn = { NULL, tap_dance_finished, tap_dance_reset }, \
        .user_data = &tap_dance_states[ _TapDance ] \
    }

//! @{
//! @brief Utility defines
#define T_ESC       LT( L_FUNC, KC_ESC )
#define T_LCTRL     OSM( MOD_LCTL )
//! @}

//! @{
//! @brief Forward declarations of functions
void tap_dance_finished( tap_dance_state_t* state, void* userData );
void tap_dance_reset( tap_dance_state_t* state, void* userData );
//! @}

// clang-format off
tap_dance_action_t tap_dance_actions[] = {
    ACTION_TAP_DANCE( TD_ESC ),
};
// clang-format on

/* Keymappings */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[L_BASE] = LAYOUT_alice_split_bs(
        KC_ESC , KC_GRV , KC_1   , KC_2  , KC_3   , KC_4   , KC_5  , KC_6  , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_BSPC, KC_BSPC,
        KC_PSCR, KC_TAB , KC_Q   , KC_W  , KC_E   , KC_R   , KC_T  , KC_Y  , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSLS,
        KC_INS , T_ESC  , KC_A   , KC_S  , KC_D   , KC_F   , KC_G  , KC_H  , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, KC_ENT ,
        KC_PAUS, KC_LSFT, KC_Z   , KC_X  , KC_C   , KC_V   , KC_B  , KC_B  , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_UP  , KC_RSFT,
                 T_LCTRL, KC_LGUI,                  KC_LALT, KC_SPC, KC_SPC, KC_RALT,                            KC_LEFT, KC_DOWN, KC_RGHT
	),
	[L_FUNC] = LAYOUT_alice_split_bs(
        KC_TRNS, KC_TRNS, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_DEL , KC_DEL,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MRWD, KC_VOLD, KC_VOLU, KC_MFFD, KC_MPLY, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END , KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS,
        QK_BOOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
};

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

