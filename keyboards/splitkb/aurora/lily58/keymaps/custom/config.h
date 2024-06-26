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

#pragma once

//! @brief The various users that we support for RPC
#define SPLIT_TRANSACTION_IDS_USER USER_SYNC_A

//! @brief Set our tapping term to be 200ms
#define TAPPING_TERM 200

//! @brief See https://github.com/qmk/qmk_firmware/blob/master/docs/tap_hold.md
#define PERMISSIVE_HOLD
#define HOLD_ON_OTHER_KEY_PRESS

//! @{
//! @brief Allow the transfer of info between master and slave controller
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_MODS_ENABLE
#define SPLIT_WPM_ENABLE
//! @}
