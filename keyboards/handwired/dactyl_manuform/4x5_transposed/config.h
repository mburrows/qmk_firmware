/*
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

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x3060
#define DEVICE_VER      0x0001
#define MANUFACTURER    tshort
#define DESCRIPTION     A split keyboard for the cheap makers

/* key matrix size */
// Columns are doubled-up
#define MATRIX_ROWS 5
#define MATRIX_COLS 10

// wiring of each half
#define MATRIX_COL_PINS { F7, B1, B3, B2, B6 }
#define MATRIX_ROW_PINS { C6, D7, E6, B4, B5 }

