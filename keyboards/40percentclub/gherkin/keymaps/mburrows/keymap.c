#include "gherkin.h"
#include "quantum.h"

#define _______ KC_TRNS

#define GUI_1 LGUI(KC_1)
#define GUI_2 LGUI(KC_2)
#define GUI_3 LGUI(KC_3)
#define GUI_4 LGUI(KC_4)
#define GUI_5 LGUI(KC_5)
#define GUI_6 LGUI(KC_6)
#define GUI_7 LGUI(KC_7)
#define GUI_8 LGUI(KC_8)
#define GUI_9 LGUI(KC_9)

#define HYP_1 HYPR(KC_1)
#define HYP_2 HYPR(KC_2)
#define HYP_3 HYPR(KC_3)
#define HYP_4 HYPR(KC_4)
#define HYP_5 HYPR(KC_5)
#define HYP_6 HYPR(KC_6)

// Tap dance declarations
enum {
    TD_GUI_1 = 0,
    TD_GUI_2,
    TD_GUI_3,
    TD_GUI_4,
    TD_GUI_5,
    TD_GUI_6,
    TD_GUI_7,
    TD_GUI_8,
    TD_GUI_9,
    TD_BSPC_TAB
};

#define TAPPING_TERM 200

// Tap dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_GUI_1]    = ACTION_TAP_DANCE_DOUBLE(GUI_1, S(GUI_1)),
    [TD_GUI_2]    = ACTION_TAP_DANCE_DOUBLE(GUI_2, S(GUI_2)),
    [TD_GUI_3]    = ACTION_TAP_DANCE_DOUBLE(GUI_3, S(GUI_3)),
    [TD_GUI_4]    = ACTION_TAP_DANCE_DOUBLE(GUI_4, S(GUI_4)),
    [TD_GUI_5]    = ACTION_TAP_DANCE_DOUBLE(GUI_5, S(GUI_5)),
    [TD_GUI_6]    = ACTION_TAP_DANCE_DOUBLE(GUI_6, S(GUI_6)),
    [TD_GUI_7]    = ACTION_TAP_DANCE_DOUBLE(GUI_7, S(GUI_7)),
    [TD_GUI_8]    = ACTION_TAP_DANCE_DOUBLE(GUI_8, S(GUI_8)),
    [TD_GUI_9]    = ACTION_TAP_DANCE_DOUBLE(GUI_9, S(GUI_9)),
    [TD_BSPC_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_BSPC, KC_TAB)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// .-----------------------------------------------------------------------------------------.
// |   G7   |   G8   |   G9   |   H3   |   H6   |        |  BSPC  |   7    |   8    |   9    |
// |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
// |   G4   |   G5   |   G6   |   H2   |   H5   |        |   .    |   4    |   5    |   6    |
// |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
// |   G1   |   G2   |   G3   |   H1   |   H4   |        |   0    |   1    |   2    |   3    |
// '-----------------------------------------------------------------------------------------'

LAYOUT_ortho_3x10(
    TD(TD_GUI_7), TD(TD_GUI_8), TD(TD_GUI_9), HYP_3, HYP_6, _______, TD(TD_BSPC_TAB), KC_7, KC_8, KC_9,
    TD(TD_GUI_4), TD(TD_GUI_5), TD(TD_GUI_6), HYP_2, HYP_5, _______, KC_DOT,          KC_4, KC_5, KC_6,
    TD(TD_GUI_1), TD(TD_GUI_2), TD(TD_GUI_3), HYP_1, HYP_4, _______, KC_0,            KC_1, KC_2, KC_3)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    keyevent_t event = record->event;
    (void)event;

    switch (id) {

    }
    return MACRO_NONE;
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}

