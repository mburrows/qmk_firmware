#pragma once

#include "dactyl_manuform.h"

#include "quantum.h"


#ifdef USE_I2C
#include <stddef.h>
#ifdef __AVR__
	#include <avr/io.h>
	#include <avr/interrupt.h>
#endif
#endif

#define LAYOUT_kc( \
	L00, L01, L02, L03, L04,                     R00, R01, R02, R03, R04, \
	L10, L11, L12, L13, L14,                     R10, R11, R12, R13, R14, \
	L20, L21, L22, L23, L24,                     R20, R21, R22, R23, R24, \
	     L31, L32,                                         R32, R33,      \
                 L33, L34,                     R30, R31,                \
                           L44, L42, R42, R40,                          \
                           L43, L41, R43, R41                           \
	) \
	{ \
            { KC_##L00, KC_##L10, KC_##L20, KC_NO,    KC_NO    }, \
            { KC_##L01, KC_##L11, KC_##L21, KC_##L31, KC_##L41 }, \
            { KC_##L02, KC_##L12, KC_##L22, KC_##L32, KC_##L42 }, \
            { KC_##L03, KC_##L13, KC_##L23, KC_##L33, KC_##L43 }, \
            { KC_##L04, KC_##L14, KC_##L24, KC_##L34, KC_##L44 }, \
            \
            { KC_##R04, KC_##R14, KC_##R24, KC_NO,    KC_NO    }, \
            { KC_##R03, KC_##R13, KC_##R23, KC_##R33, KC_##R43 }, \
            { KC_##R02, KC_##R12, KC_##R22, KC_##R32, KC_##R42 }, \
            { KC_##R01, KC_##R11, KC_##R21, KC_##R31, KC_##R41 }, \
            { KC_##R00, KC_##R10, KC_##R20, KC_##R30, KC_##R40 }  \
	}
