#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "../../config.h"

#define _______ KC_TRNS

// One-shot modfiers
#define OSM_ALT OSM(MOD_LALT)
#define OSM_GUI OSM(MOD_LGUI)
#define OSM_HYP OSM(MOD_HYPR)
#define OSM_MEH OSM(MOD_MEH)

// One-shot layers
#define OSL_NUM OSL(_NUM)
#define OSL_SYM OSL(_SYM)

// Modifier taps
#define CTL_QUOT MT(MOD_LCTL,KC_QUOT)
#define GUI_ESC  MT(MOD_LGUI,KC_ESC)

// Layer taps
#define NAV_A   LT(_NAV,KC_A)
#define NAV_O   LT(_NAV,KC_O)

// Modifier key combos
#define CTL_TAB LCTL(KC_TAB)
#define SCT_TAB S(LCTL(KC_TAB))

#undef  ONESHOT_TAP_TOGGLE
#define ONESHOT_TAP_TOGGLE 2

#undef  ONESHOT_TIMEOUT
#define ONESHOT_TIMEOUT 1000

#undef  TAPPING_TOGGLE
#define TAPPING_TOGGLE 2

// Get taps and holds working properly
#undef  TAPPING_TERM
#define TAPPING_TERM 300
#define PERMISSIVE_HOLD
#define RETRO_TAPPING

#define LEADER_TIMEOUT 1000

#endif
