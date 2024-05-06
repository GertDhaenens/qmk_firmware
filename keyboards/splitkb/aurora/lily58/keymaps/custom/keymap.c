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

//! @brief The various layers of our keyboard layout
enum layers {
    LAYER_DEFAULT = 0,
    LAYER_SYMBOLS = 1,
    LAYER_FUNCTIONS = 2,
    LAYER_ADJUST = 3,
};

//! @brief The bindings of keys of our various layers
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_DEFAULT] = LAYOUT(
        KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                   KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______,
        KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                   KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSLS,
        LSFT_T(KC_ESC), KC_A, KC_S, KC_D  , KC_F   , KC_G   ,                   KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, RSFT_T(KC_QUOT),
        KC_LCTL, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_DEL , _______, KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RCTL,
                                   KC_LALT, KC_LGUI, MO(2)  , KC_SPACE, KC_SPACE,MO(1) , KC_RGUI, KC_RALT
    ),
    [LAYER_SYMBOLS] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LCBR, KC_RCBR, KC_PIPE,
        _______, KC_TILD, KC_LBRC, KC_RBRC, KC_MINS, KC_PLUS,                   KC_EQL , KC_UNDS, KC_LPRN, KC_RPRN, KC_COLN, KC_DQUO,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LABK, KC_RABK, KC_QUES, _______,
                                   _______, _______, MO(3)  , KC_BSPC, _______, _______, _______, _______
    ),
    [LAYER_FUNCTIONS] = LAYOUT(
        KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,                   KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, KC_END , KC_PGUP, KC_PGDN, KC_HOME,                   KC_LEFT, KC_DOWN, KC_UP  , KC_RIGHT,_______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______, KC_ENT , MO(3)  , _______, _______
    ),
    [LAYER_ADJUST] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______, _______, _______, _______, _______
    )
};

//! @brief The data for our pomudachi in on mode (mouth open)
const uint8_t PROGMEM pomudachi_on[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x09, 0x91, 0x52, 0x54,
    0x78, 0x54, 0x92, 0x11, 0x09, 0x0D, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x7E, 0x81, 0x00, 0x20, 0x0E, 0x2E, 0x00, 0x00, 0x00, 0x40, 0x40, 0x40,
    0x40, 0x40, 0x40, 0x00, 0x00, 0x00, 0x2E, 0x0E, 0x20, 0x00, 0x81, 0x7E, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x02, 0x46, 0xEC, 0xAC, 0xB8, 0x88, 0x78, 0x18, 0x18,
    0x18, 0x18, 0x78, 0x88, 0xB8, 0xAC, 0xEC, 0x46, 0x02, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
};

//! @brief The data for our pomudachi in off mode (mouth closed)
const uint8_t PROGMEM pomudachi_off[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x09, 0x91, 0x52, 0x54,
    0x78, 0x54, 0x92, 0x11, 0x09, 0x0D, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x7E, 0x81, 0x00, 0x20, 0x0E, 0x2E, 0x00, 0x00, 0x00, 0x60, 0xA0, 0x20,
    0x20, 0xA0, 0x60, 0x00, 0x00, 0x00, 0x2E, 0x0E, 0x20, 0x00, 0x81, 0x7E, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x02, 0x46, 0xEC, 0xAC, 0xB8, 0x88, 0x78, 0x18, 0x19,
    0x19, 0x18, 0x78, 0x88, 0xB8, 0xAC, 0xEC, 0x46, 0x02, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
};

//! @brief Our RPC handling function from the slave side of the keyboard
void user_sync_a_slave_handler
(
    uint8_t i_buflen,
    void const* i_data,
    uint8_t o_buflen,
    void* o_data
)
{
    // Cache our key down counter for our visualisation
    uint8_t const* const src_keydown_counter = (uint8_t const*) i_data;
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
