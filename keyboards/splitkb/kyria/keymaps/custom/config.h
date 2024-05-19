/* Copyright 2022 Thomas Baart <thomas@splitkb.com>
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

#pragma once

// Undefine existing values
#undef RGBLIGHT_LED_COUNT
#undef RGBLED_SPLIT

// Our version only has 12 LED on the board
#define RGBLIGHT_LED_COUNT 12
#define RGBLED_SPLIT { 6, 6 }

// Turn on our underglow by default
#define RGBLIGHT_DEFAULT_ON     true

// Set our default HSV value (lavender)
#define RGBLIGHT_DEFAULT_HUE    216u
#define RGBLIGHT_DEFAULT_SAT    153u
#define RGBLIGHT_DEFAULT_VAL     94u

// Enable Caps Word by double tapping left shift
#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD

// Sync certain state between our two sides
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_WPM_ENABLE

// Set our tapping toggle (for TT commands) to only two taps (default five)
#define TAPPING_TOGGLE 2
