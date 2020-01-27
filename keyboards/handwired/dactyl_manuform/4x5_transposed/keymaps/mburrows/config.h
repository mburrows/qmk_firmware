/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* Use I2C or Serial, not both */

#define USE_SERIAL
// #define USE_I2C

/* Select hand configuration */

// #define MASTER_LEFT
// #define MASTER_RIGHT
#define EE_HANDS

// Get taps and holds working properly
#undef  ONESHOT_TAP_TOGGLE
#define ONESHOT_TAP_TOGGLE 2

#undef  ONESHOT_TIMEOUT
#define ONESHOT_TIMEOUT 1000

#undef  TAPPING_TOGGLE
#define TAPPING_TOGGLE 2

#undef  TAPPING_TERM
#define TAPPING_TERM 300
// #define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT

#define LEADER_TIMEOUT 1000

// Custom keycodes
#define KC______ KC_TRNS
#define KC_XXXXX KC_NO
#define KC_RST   RESET

// One-shot modfiers
#define KC_HYP   OSM(MOD_HYPR)

// Modifier taps
#define KC_G_ESC GUI_T(KC_ESC)
#define KC_S_I   SFT_T(KC_I)
#define KC_S_R   SFT_T(KC_R)
#define KC_S_Z   SFT_T(KC_Z)
#define KC_S_SLS SFT_T(KC_SLSH)
#define KC_A_S   ALT_T(KC_S)
#define KC_A_E   ALT_T(KC_E)
#define KC_C_T   CTL_T(KC_T)
#define KC_C_N   CTL_T(KC_N)
#define KC_H_D   HYPR_T(KC_D)
#define KC_H_H   HYPR_T(KC_H)
#define KC_C_LFT C(KC_LEFT)
#define KC_C_DN  C(KC_DOWN)
#define KC_C_UP  C(KC_UP)
#define KC_C_RGT C(KC_RIGHT)
#define KC_C_RBRC C(KC_RBRC)

// Layer taps
#define KC_LOWER LT(_LOWER, KC_BSPC)
#define KC_RAISE LT(_RAISE, KC_SPC)
#define KC_N_A   LT(_NAV, KC_A)
#define KC_N_O   LT(_NAV, KC_O)
