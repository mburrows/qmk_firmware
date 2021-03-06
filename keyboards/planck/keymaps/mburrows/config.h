#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "config_common.h"

// One-shot modifier keys
#define OSM_CTL OSM(MOD_LCTL)
#define OSM_ALT OSM(MOD_LALT)
#define OSM_GUI OSM(MOD_LGUI)

// One-shot layer keys
#define OSL_RSE OSL(_RAISE)
#define OSL_LWR OSL(_LOWER)

// Modifier taps
#define S_R   SFT_T(KC_R)
#define S_I   SFT_T(KC_I)
#define A_S   ALT_T(KC_S)
#define A_E   ALT_T(KC_E)
#define C_T   CTL_T(KC_T)
#define C_N   CTL_T(KC_N)
#define H_D   HYPR_T(KC_D)
#define H_H   HYPR_T(KC_H)

// Layer taps
#define NAV_A    LT(_NAV,KC_A)
#define NAV_O    LT(_NAV,KC_O)
#define LWR_BSPC LT(_LOWER,KC_BSPC)
#define RSE_SPC  LT(_RAISE,KC_SPC)

// Get taps and holds working properly
#undef  ONESHOT_TAP_TOGGLE
#define ONESHOT_TAP_TOGGLE 2

#undef  ONESHOT_TIMEOUT
#define ONESHOT_TIMEOUT 1000

#undef  TAPPING_TOGGLE
#define TAPPING_TOGGLE 2

#undef  TAPPING_TERM
#define TAPPING_TERM 300
#define IGNORE_MOD_TAP_INTERRUPT

#define LEADER_TIMEOUT 1000

#endif
