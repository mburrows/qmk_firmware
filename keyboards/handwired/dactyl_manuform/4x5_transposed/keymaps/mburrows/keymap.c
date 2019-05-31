#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _BASE 0
#define _LOWER 1
#define _RAISE 2
#define _NAV 3

// Fillers to make layering more clear

#define ____ KC_TRNS

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

#define KC______ KC_TRNS
#define KC_XXXXX KC_NO
#define KC_LOWER LT(_LOWER, KC_LBRC)
#define KC_RAISE LT(_RAISE, KC_RBRC)
#define KC_NAV_A LT(_NAV,KC_A)
#define KC_NAV_O LT(_NAV,KC_O)
#define KC_S_ESC SFT_T(KC_ESC)
#define KC_G_BSP LGUI_T(KC_BSPC)
#define KC_S_ENT SFT_T(KC_ENT)
#define KC_C_SPC CTL_T(KC_SPC)
#define KC_H_TAB HYPR_T(KC_TAB)
#define KC_H_DEL HYPR_T(KC_DEL)
#define KC_C_PGU CTL_T(KC_PGUP)
#define KC_A_PGD ALT_T(KC_PGDN)
#define KC_C_HME CTL_T(KC_HOME)
#define KC_A_END ALT_T(KC_END)
#define KC_TMUX  LCTL(KC_SPACE)
#define KC_C_ALT OSM(MOD_LCTL | MOD_LALT)
#define KC_HYP   OSM(MOD_HYPR)
#define KC_RST   RESET

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_kc( \
 //,----------------------------------,                             ,----------------------------------,
         Q,     W,     F,     P,     G,                                   J,     L,     U,     Y,  SCLN,\
 //|------+------+------+------+------|                             |------+------+------+------+------|
     NAV_A,     R,     S,     T,     D,                                   H,     N,     E,     I, NAV_O,\
 //|------+------+------+------+------|                             |------+------+------+------+------|
         Z,     X,     C,     V,     B,                                   K,     M,  COMM,   DOT,  SLSH,\
 //|------+------+------+------+------,                             ,------+------+------+------+------,
            C_ALT,   HYP,                                                            TMUX,  LEAD,\
        //'------+------+-------------'                             '-------------+------+------'
                          S_ESC, G_BSP,                               C_SPC, S_ENT,\
                      //'------+------'                             '------+------'
                                    //'------+------' '------+------'
                                        LOWER, C_HME,   C_PGU, RAISE,\
                                    //'------+------' '------+------'
                                        H_DEL, A_END,   A_PGD, H_TAB \
                                    //'------+------' '------+------'
),

[_LOWER] = LAYOUT_kc( \
 //,----------------------------------,                             ,----------------------------------,
         1,     2,     3,     4,     5,                                   6,     7,     8,     9,     0,\
 //|------+------+------+------+------|                             |------+------+------+------+------|
        F1,    F2,    F3,    F4,    F5,                                PLUS,     4,     5,     6,  ASTR,\
 //|------+------+------+------+------|                             |------+------+------+------+------|
        F6,    F7,    F8,    F9,   F10,                                MINS,     1,     2,     3,  SLSH,\
 //|------+------+------+------+------,                             ,------+------+------+------+------,
              F11,   F12,                                                               0,   DOT,\
        //'------+------'-------------'                             '-------------'------+------'
                          _____, _____,                               _____,   EQL,\
                      //'------+------'                             '------+------'
                                    //'------+------' '------+------'
                                        _____, _____,   _____, _____,\
                                    //'------+------' '------+------'
                                        _____, _____,   _____, _____ \
                                    //'------+------' '------+------'
),

[_RAISE] = LAYOUT_kc( \
 //,----------------------------------,                             ,----------------------------------,
      EXLM,    AT,  LCBR,  RCBR,  PIPE,                                 GRV, XXXXX,  ASTR, XXXXX, XXXXX,\
 //|------+------+------+------+------|                             |------+------+------+------+------|
      HASH,   DLR,  LPRN,  RPRN,  AMPR,                                 INS,  MINS,   EQL,  DQUO,  QUOT,\
 //|------+------+------+------+------|                             |------+------+------+------+------|
      PERC,  CIRC,  LBRC,  RBRC,  TILD,                                CAPS,  UNDS,  PLUS,   DOT,  BSLS,\
 //|------+------+------+------+------,                             ,------+------+------+------+------,
            XXXXX, XXXXX,                                                           XXXXX, XXXXX,\
        //'------+------'-------------'                             '-------------'------+------'
                          _____, _____,                               _____, _____,\
                      //'------+------'                             '------+------'
                                    //'------+------' '------+------'
                                        _____, _____,   _____, _____,\
                                    //'------+------' '------+------'
                                        _____, _____,   _____, _____ \
                                    //'------+------' '------+------'
),

[_NAV] = LAYOUT_kc( \
 //,----------------------------------,                             ,----------------------------------,
     XXXXX,  WBAK,  MS_U,  WFWD,  WH_U,                                MPRV,  VOLD,  VOLU,  MNXT,  MPLY,\
 //|------+------+------+------+------|                             |------+------+------+------+------|
     XXXXX,  MS_L,  MS_D,  MS_R,  WH_D,                                LEFT,  DOWN,    UP,  RGHT, XXXXX,\
 //|------+------+------+------+------|                             |------+------+------+------+------|
     XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,                                HOME,  PGDN,  PGUP,   END, XXXXX,\
 //|------+------+------+------+------,                             ,------+------+------+------+------,
            _____, _____,                                                            BRID,  BRIU,\
        //'------+------'-------------'                             '-------------'------+------'
                           BTN2,  BTN1,                               _____, _____,\
                      //'------+------'                             '------+------'
                                    //'------+------' '------+------'
                                         BTN3, _____,   _____, _____,\
                                    //'------+------' '------+------'
                                        _____, _____,     RST, _____ \
                                    //'------+------' '------+------'
)
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}
