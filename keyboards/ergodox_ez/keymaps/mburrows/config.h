#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "../../config.h"

#define KC______ KC_TRNS

// One-shot modfiers
#define KC_OCTL OSM(MOD_LCTL)
#define KC_OALT OSM(MOD_LALT)
#define KC_OGUI OSM(MOD_LGUI)
#define KC_OHYP OSM(MOD_HYPR)
#define KC_OMEH OSM(MOD_MEH)

// One-shot layers
#define KC_NUM  OSL(_NUM)
#define KC_SYM  OSL(_SYM)

// Modifier taps
#define KC_CQUOT CTL_T(KC_QUOT)
#define KC_CESC  CTL_T(KC_ESC)
#define KC_G_ESC GUI_T(KC_ESC)
#define KC_HGRV  HYPR_T(KC_GRV)
#define KC_S_R   SFT_T(KC_R)
#define KC_S_I   SFT_T(KC_I)
#define KC_A_S   ALT_T(KC_S)
#define KC_A_E   ALT_T(KC_E)
#define KC_C_T   CTL_T(KC_T)
#define KC_C_N   CTL_T(KC_N)
#define KC_H_D   HYPR_T(KC_D)
#define KC_H_H   HYPR_T(KC_H)

// Layer taps
#define KC_N_A  LT(_NAV,KC_A)
#define KC_N_O  LT(_NAV,KC_O)

// Modifier key combos
#define KC_SCP   S(C(KC_P))
#define KC_CURSB S(C(KC_DOWN))

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

#define LEADER_TIMEOUT 1000

/*  ---------- LEFT HAND -----------   ---------- RIGHT HAND ---------- */
#define LAYOUT_ergodox_pretty_kc(                                        \
    L00,L01,L02,L03,L04,L05,L06,           R00,R01,R02,R03,R04,R05,R06,  \
    L10,L11,L12,L13,L14,L15,L16,           R10,R11,R12,R13,R14,R15,R16,  \
    L20,L21,L22,L23,L24,L25,                   R21,R22,R23,R24,R25,R26,  \
    L30,L31,L32,L33,L34,L35,L36,           R30,R31,R32,R33,R34,R35,R36,  \
    L40,L41,L42,L43,L44,                           R42,R43,R44,R45,R46,  \
                            L55,L56,   R50,R51,                          \
                                L54,   R52,                              \
                        L53,L52,L51,   R55,R54,R53 )                     \
                                          \
   /* matrix positions */                 \
    {                                     \
    { KC_##L00, KC_##L10, KC_##L20, KC_##L30, KC_##L40, KC_NO    }, \
    { KC_##L01, KC_##L11, KC_##L21, KC_##L31, KC_##L41, KC_##L51 }, \
    { KC_##L02, KC_##L12, KC_##L22, KC_##L32, KC_##L42, KC_##L52 }, \
    { KC_##L03, KC_##L13, KC_##L23, KC_##L33, KC_##L43, KC_##L53 }, \
    { KC_##L04, KC_##L14, KC_##L24, KC_##L34, KC_##L44, KC_##L54 }, \
    { KC_##L05, KC_##L15, KC_##L25, KC_##L35, KC_NO,    KC_##L55 }, \
    { KC_##L06, KC_##L16, KC_NO,    KC_##L36, KC_NO,    KC_##L56 }, \
                                          \
    { KC_##R00, KC_##R10, KC_NO,    KC_##R30, KC_NO,    KC_##R50 }, \
    { KC_##R01, KC_##R11, KC_##R21, KC_##R31, KC_NO,    KC_##R51 }, \
    { KC_##R02, KC_##R12, KC_##R22, KC_##R32, KC_##R42, KC_##R52 }, \
    { KC_##R03, KC_##R13, KC_##R23, KC_##R33, KC_##R43, KC_##R53 }, \
    { KC_##R04, KC_##R14, KC_##R24, KC_##R34, KC_##R44, KC_##R54 }, \
    { KC_##R05, KC_##R15, KC_##R25, KC_##R35, KC_##R45, KC_##R55 }, \
    { KC_##R06, KC_##R16, KC_##R26, KC_##R36, KC_##R46, KC_NO    }  \
    }

#undef DEBOUNCE
#define DEBOUNCE 15

#endif
