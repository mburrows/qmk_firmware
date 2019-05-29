#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _BASE 0
#define _RAISE 1
#define _LOWER 2
#define _NAV 3

// Fillers to make layering more clear

#define ____ KC_TRNS

#define KC_ML KC_MS_LEFT
#define KC_MR KC_MS_RIGHT
#define KC_MU KC_MS_UP
#define KC_MD KC_MS_DOWN
#define KC_MB1 KC_MS_BTN1
#define KC_MB2 KC_MS_BTN1

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
#define KC_C_PGU CTL_T(KC_PGUP)
#define KC_A_PGD ALT_T(KC_PGDN)
#define KC_C_HME CTL_T(KC_HOME)
#define KC_A_END ALT_T(KC_END)
#define KC_MUX   LCTL(KC_SPACE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_kc( \
 //,----------------------------------,                             ,----------------------------------,
         Q,     W,     F,     P,     G,                                   J,     L,     U,     Y,  SCLN,\
 //|------+------+------+------+------|                             |-------------+------+------+------|
     NAV_A,     R,     S,     T,     D,                                   H,     N,     E,     I, NAV_O,\
 //|------+------+------+------+------|                             |------|------+------+------+------|
         Z,     X,     C,     V,     B,                                   K,     M,  COMM,   DOT,  SLSH,\
 //|------+------+------+-------------,                             ,-------------+------+------+------,
             LCBR,  RCBR,                                                             MUX,  LEAD,\
        //'------+------'-------------'                             '-------------'------+------'
                          S_ESC, G_BSP,                               C_SPC, S_ENT,\
                      //'------+------'                             '------+------'
                                    //'------+------' '------+------'
                                        LOWER, C_HME,   C_PGU, RAISE,\
                                    //'------+------' '------+------'
                                          DEL, A_END,   A_PGD,   TAB \
                                    //'------+------' '------+------'
),

/* Raise
 * ,----------------------------------,                             ,----------------------------------,
 * |      |      |  mup |      |      |                             | VOL+ |      |  up  |      | PgUp |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * |      | mleft| mdown|mright|      |                             | MUTE | left | down |right | PgDn |
 * |------+------+------+------+------|                             |------|------+------+------+------|
 * |      |      |      |      |      |                             | VOL- |  /   |  \   |  ?   |  |   |
 * |------+------+------+-------------,                             ,-------------+------+------+------,
 *        |      |      |                                                         | mbtn |mbtn2 |
 *        '------+------'-------------'                             '-------------'------+------'
 *                      |      |      |                             |      |      |
 *                      |      |      |                             |      |      |
 *                      |      |      |                             |      |      |
 *                      '------+------'                             '------+------'
 *                                    '------+------' '------+------'
 *                                    |      |      | |      |      |
 *                                    '------+------' '------+------'
 *                                    |      |      | |      |      |
 *                                    '------+------' '------+------'
 */

[_RAISE] = LAYOUT( \
  ____, ____,  KC_MU, ____,  ____,                          KC_VOLU, ____,    KC_UP,   ____,     KC_PGUP,   \
  ____, KC_ML, KC_MD, KC_MR, ____,                          KC_MUTE, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDOWN, \
  ____, ____,  ____,  ____,  ____,                          KC_VOLD, KC_SLSH, KC_BSLS, KC_QUES,  KC_PIPE,   \
        ____,  ____,                                                          KC_MB1,  KC_MB2,              \
                                   ____, ____,  ____, ____,                                                 \
                                   ____, ____,  ____, ____,                                                 \
                                   ____, ____,  ____, ____                                                  \
),
/* Lower
 * ,----------------------------------,                             ,----------------------------------,
 * | F1   | F2   | F3   | F4   | F5   |                             |  F6  | F7   |  F8  |  F9  |  F10 |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * |  1   |  2   |  3   |  4   |  5   |                             |  6   |  7   |  8   |  9   |  10  |
 * |------+------+------+------+------|                             |------|------+------+------+------|
 * |  !   |  @   |  #   |  $   |  %   |                             |  ^   |  &   |  *   |  (   |  )   |
 * |------+------+------+-------------,                             ,-------------+------+------+------,
 *        | F11  | F12  |                                                         |  -   |  =   |
 *        '------+------'-------------'                             '-------------'------+------'
 *                      |      |      |                             |      |      |
 *                      |      |      |                             |      |      |
 *                      |      |      |                             |      |      |
 *                      '------+------'                             '------+------'
 *                                    '------+------' '------+------'
 *                                    |      |      | |      |      |
 *                                    '------+------' '------+------'
 *                                    |      |      | |      |      |
 *                                    '------+------' '------+------'
 */

[_LOWER] = LAYOUT( \
  KC_F1,   KC_F2,  KC_F3,   KC_F4,  KC_F5,                            KC_F6,   KC_F7,    KC_F8,   KC_F9,   KC_F10,  \
  KC_1,    KC_2,   KC_3,    KC_4,   KC_5,                             KC_6,    KC_7,     KC_8,    KC_9,    KC_0,    \
  KC_EXLM, KC_AT,  KC_HASH, KC_DLR, KC_PERC,                          KC_CIRC, KC_AMPR,  KC_ASTR, KC_LPRN, KC_RPRN, \
           KC_F11, KC_F12,                                                               ____,    ____,             \
                                             ____, ____,  ____, ____,                                               \
                                             ____, ____,  ____, ____,                                               \
                                             ____, ____,  ____, ____                                                \
)
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}
