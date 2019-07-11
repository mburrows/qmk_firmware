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
#define CTL_ESC MT(MOD_LCTL,KC_ESC)
#define CTL_ENT MT(MOD_LCTL,KC_ENT)
#define HYP_TAB HYPR_T(KC_TAB)

// Layer taps
#define NAV_A    LT(_NAV,KC_A)
#define NAV_O    LT(_NAV,KC_O)
#define LWR_BSPC LT(_LOWER,KC_BSPC)
#define RSE_SPC  LT(_RAISE,KC_SPC)
#define RSE_Z    LT(_RAISE,KC_Z)

// Get taps and holds working properly
#undef  ONESHOT_TAP_TOGGLE
#define ONESHOT_TAP_TOGGLE 2

#undef  ONESHOT_TIMEOUT
#define ONESHOT_TIMEOUT 1000

#undef  TAPPING_TOGGLE
#define TAPPING_TOGGLE 2

#undef  TAPPING_TERM
#define TAPPING_TERM 300
#define PERMISSIVE_HOLD
#define RETRO_TAPPING

#define LEADER_TIMEOUT 1000

#endif
