#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "config.h"

enum ergodox_layers {
  _COLEMAK = 0,
  _NUM,
  _SYM,
  _NAV
};

enum custom_keycodes {
  TERM_COPY = SAFE_RANGE,
  TERM_PASTE
};

// Tap Dance Declarations
enum {
  TD_COPY_PASTE = 0,
  TD_LBR,
  TD_RBR
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_COPY_PASTE] = ACTION_TAP_DANCE_DOUBLE(LSFT(LCTL(KC_C)),LSFT(LCTL(KC_V)))
};
#define KC_CPPST TD(TD_COPY_PASTE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_COLEMAK] = LAYOUT_ergodox_pretty_kc(
//  ,--------------------------------------------------.           ,--------------------------------------------------.
       HGRV  ,   1  ,   2  ,   3  ,   4  ,   5  , LBRC ,             RBRC ,   6  ,   7  ,   8  ,   9  ,   0  ,  EQL   ,\
//  |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
       BSLS  ,   Q  ,   W  ,   F  ,   P  ,   G  , LCBR ,             RCBR ,   J  ,   L  ,   U  ,   Y  , SCLN ,  MINS  ,\
//  |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
       CESC  , N_A  , S_R  , A_S  , C_T  , H_D  ,                           H_H  , C_N  , A_E  , S_I  , N_O  ,  CQUOT ,\
//  |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
       LSPO  ,   Z  ,   X  ,   C  ,   V  ,   B  , DEL  ,             TAB  ,   K  ,   M  , COMM , DOT  , SLSH ,  RSPC  ,\
//  `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
       LEAD  , OCTL , OALT , OGUI ,  NUM ,                                          SYM , LEFT , DOWN ,  UP  ,  RGHT,\
//    `----------------------------------'                                       `----------------------------------'
//                                         ,-------------.       ,-------------.
                                              JTAG, CPPST,         F13  , F12  ,\
//                                  ,------|------|------|       |------+------+------.
                                                    HOME ,         PGUP ,             \
//                                  |      |      |------|       |------|      |      |
                                      BSPC , G_ESC, END  ,         PGDN , ENT  , SPC  \
//                                  `--------------------'       `--------------------'
),

[_NUM] = LAYOUT_ergodox_pretty_kc(
// ,--------------------------------------------------.           ,--------------------------------------------------.
       _____,  F1  ,  F2  ,  F3  ,  F4  ,  F5  , _____,             _____,  F6  ,  F7  ,  F8  ,  F9  , F10  ,  F11   ,\
// |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
       _____, _____, _____, _____, _____, _____, _____,             _____, _____,   7  ,   8  ,   9  ,   0  ,  F12   ,\
// |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
       _____, _____, _____, _____, _____, _____,                           PLUS ,   4  ,   5  ,   6  , ASTR , _____  ,\
// |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
       _____, _____, _____, _____, _____, _____, _____,             _____, MINS ,   1  ,   2  ,   3  , SLSH , _____  ,\
// `--------+------+------+------+------+-------------            `-------------+------+------+------+------+--------'
       _____, _____, _____, _____, _____,                                         _____,   0  ,  DOT , _____, _____,\
//   `----------------------------------'                                       `----------------------------------'
//                                        ,-------------.       ,-------------.
                                            _____, _____,         _____, _____,\
//                                 ,------|------|------|       |------+------+------.
                                                   _____,         _____,             \
//                                 |      |      |------|       |------|      |      |
                                     _____, _____, _____,         _____, _____,  EQL \
//                                 `--------------------'       `--------------------'
),

[_SYM] = LAYOUT_ergodox_pretty_kc(
// ,---------------------------------------------------.           ,--------------------------------------------------.
        _____,  F1  ,  F2  ,  F3  ,  F4  ,  F5  , _____,             _____,  F6  ,  F7  ,  F8  ,  F9  , F10  ,  F11   ,\
// |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
        _____, EXLM ,  AT  , LCBR , RCBR , PIPE , _____,             _____, _____, GRV  , ASTR , _____, _____,  F12   ,\
// |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
        _____, HASH , DLR  , LPRN , RPRN , AMPR ,                            INS , MINS , EQL  , _____, _____, _____  ,\
// |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
        _____, PERC , CIRC , LBRC , RBRC , TILD , _____,             _____, CAPS , UNDS , PLUS , _____, BSLS , _____  ,\
// `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
        _____, _____, _____, _____, _____,                                         _____, _____, _____, _____, _____,\
//   `-----------------------------------'                                       `----------------------------------'
//                                        ,-------------.       ,-------------.
                                            _____, _____,         _____, _____,\
//                                 ,------|------|------|       |------+------+------.
                                                   _____,         _____,             \
//                                 |      |      |------|       |------|      |      |
                                     _____, _____, _____,         _____, _____, _____\
//                                 `--------------------'       `--------------------'
),

[_NAV] = LAYOUT_ergodox_pretty_kc(
// ,---------------------------------------------------.           ,--------------------------------------------------.
        _____, _____, _____, _____, _____, _____, _____,             _____, _____, _____, _____, _____, _____,   _____,\
// |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
        _____, _____, WBAK , MS_U , WFWD , WH_U , _____,             _____, _____, _____, _____, _____, _____,   _____,\
// |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
        _____, _____, MS_L , MS_D , MS_R , WH_D ,                           LEFT , DOWN ,  UP  , RGHT , _____,   _____,\
// |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
        _____, _____, BTN1 , BTN3 , BTN2 , _____, _____,             _____, HOME , PGDN , PGUP , END  , _____,   _____,\
// `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
        _____, _____, _____, _____, _____,                                         _____, _____, _____, _____, _____,\
//   `-----------------------------------'                                       `----------------------------------'
//                                        ,-------------.       ,-------------.
                                            BTN3 , _____,         MUTE , MPRV ,\
//                                 ,------|------|------|       |------+------+------.
                                                   WH_U ,         VOLU ,             \
//                                 |      |      |------|       |------| MPLY | MNXT |
                                     BTN1 , BTN2 , WH_D ,         VOLD , _____, _____\
//                                 `--------------------'       `--------------------'
)

};

/*
void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

void matrix_init_user(void) {
  persistant_default_layer_set(1UL<<_COLEMAK);
}
*/

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    // Single key macros
    SEQ_ONE_KEY(KC_2) {
      SEND_STRING (" 2>&1");
    }
    SEQ_ONE_KEY(KC_F) {
      SEND_STRING ("find . -name ");
    }
    SEQ_ONE_KEY(KC_G) {
      SEND_STRING("grep -E ''"SS_TAP(X_LEFT));
    }
    SEQ_ONE_KEY(KC_I) {
      SEND_STRING(" \\_inline.h");
    }
    SEQ_ONE_KEY(KC_L) {
      SEND_STRING("less ");
    }
    SEQ_ONE_KEY(KC_M) {
      SEND_STRING("mburrows");
    }
    SEQ_ONE_KEY(KC_N) {
      SEND_STRING (" > /dev/null");
    }
    SEQ_ONE_KEY(KC_S) {
      SEND_STRING("\n\nRegards\nMatt\n");
    }
    SEQ_ONE_KEY(KC_T) {
      SEND_STRING("tail -F ");
    }
    SEQ_ONE_KEY(KC_SCLN) {
      SEND_STRING(SS_TAP(X_END)";");
    }
    SEQ_ONE_KEY(KC_C) {
      // shortcut for tmux copy mode
      SEND_STRING(SS_LCTRL(" ")"[");
    }
    SEQ_ONE_KEY(KC_V) {
      // shortcut for tmux paste mode
      SEND_STRING(SS_LCTRL(" ")"p");
    }

    // Pipe macros
    SEQ_TWO_KEYS(KC_P, KC_G) {
      SEND_STRING(" | grep -E ''"SS_TAP(X_LEFT));
    }
    SEQ_TWO_KEYS(KC_P, KC_L) {
      SEND_STRING(" | less");
    }
    SEQ_TWO_KEYS(KC_P, KC_H) {
      SEND_STRING(" | head");
    }
    SEQ_TWO_KEYS(KC_P, KC_T) {
      SEND_STRING(" | tail");
    }

    // Print macros
    SEQ_TWO_KEYS(KC_P, KC_W) {
      SEND_STRING("prt_wire ");
    }
    SEQ_TWO_KEYS(KC_P, KC_F) {
      SEND_STRING("prt_fix --nohb ");
    }
    SEQ_TWO_KEYS(KC_P, KC_M) {
      SEND_STRING("prt_mktdata ");
    }

    // Email macros
    SEQ_ONE_KEY(KC_E) {
      SEND_STRING("maburrow@googlemail.com");
    }
    SEQ_TWO_KEYS(KC_E, KC_H) {
      SEND_STRING("maburrow@googlemail.com");
    }
    SEQ_TWO_KEYS(KC_E, KC_G) {
      SEND_STRING("m@ttburro.ws");
    }
    SEQ_TWO_KEYS(KC_E, KC_W) {
      SEND_STRING("mburrows@cboe.com");
    }

    // Git macros
    SEQ_TWO_KEYS(KC_G, KC_S) {
      SEND_STRING("git status");
    }
    SEQ_TWO_KEYS(KC_G, KC_L) {
      SEND_STRING("git log");
    }
    SEQ_TWO_KEYS(KC_G, KC_C) {
      SEND_STRING("git commit");
    }
    SEQ_TWO_KEYS(KC_G, KC_P) {
      SEND_STRING("git push");
    }
    SEQ_TWO_KEYS(KC_G, KC_F) {
      SEND_STRING("git pull");
    }
    SEQ_TWO_KEYS(KC_G, KC_D) {
      SEND_STRING("git diff -w");
    }
    SEQ_TWO_KEYS(KC_G, KC_1) {
      SEND_STRING("git log --oneline");
    }
    SEQ_TWO_KEYS(KC_G, KC_B) {
      SEND_STRING("git branch ");
    }
    SEQ_TWO_KEYS(KC_G, KC_V) {
      SEND_STRING("git svnup");
    }
    SEQ_TWO_KEYS(KC_G, KC_G) {
      SEND_STRING("git grep -n --break ''"SS_TAP(X_LEFT));
    }
    SEQ_TWO_KEYS(KC_G, KC_U) {
      SEND_STRING("git add -u");
    }
    SEQ_TWO_KEYS(KC_G, KC_M) {
      SEND_STRING("git log --author=mburrows");
    }
    SEQ_TWO_KEYS(KC_G, KC_R) {
      SEND_STRING("git rebase ");
    }
    SEQ_TWO_KEYS(KC_G, KC_O) {
      SEND_STRING("git checkout ");
    }
    SEQ_TWO_KEYS(KC_G, KC_Y) {
      SEND_STRING("git commit --amend -C HEAD ");
    }

    // Wire macros
    SEQ_TWO_KEYS(KC_W, KC_T) {
      SEND_STRING("wtail ");
    }
    SEQ_TWO_KEYS(KC_W, KC_H) {
      SEND_STRING("whead ");
    }
    SEQ_TWO_KEYS(KC_W, KC_G) {
      SEND_STRING("wgrep --line-buffered -P ");
    }
    SEQ_TWO_KEYS(KC_W, KC_R) {
      SEND_STRING("wrange -r");
    }
    SEQ_TWO_KEYS(KC_W, KC_S) {
      SEND_STRING("wgrep --survey ");
    }

    // Jira macros
    SEQ_TWO_KEYS(KC_J, KC_I) {
      SEND_STRING("{issue:EUCPP-}"SS_TAP(X_LEFT));
    }
    SEQ_TWO_KEYS(KC_J, KC_N) {
      SEND_STRING ("{noformat}");
    }
    SEQ_TWO_KEYS(KC_J, KC_C) {
      SEND_STRING ("{code:sql}\n\n{code}"SS_TAP(X_UP));
    }
    SEQ_TWO_KEYS(KC_J, KC_B) {
      SEND_STRING ("https://jira.bats.com/browse/EUCPP-");
    }

    // SQL macros
    SEQ_TWO_KEYS(KC_S, KC_S) {
      SEND_STRING ("select * from ");
    }
    SEQ_TWO_KEYS(KC_S, KC_I) {
      SEND_STRING ("insert into ");
    }
    SEQ_TWO_KEYS(KC_S, KC_P) {
      SEND_STRING ("select * from proc_param('');" SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT));
    }
    SEQ_TWO_KEYS(KC_S, KC_D) {
      SEND_STRING ("select * from symbol_daily where effective_date=current_date and symbol_name='';" SS_TAP(X_LEFT) SS_TAP(X_LEFT));
    }
    SEQ_TWO_KEYS(KC_S, KC_R) {
      SEND_STRING ("current_date between begin_dt and end_dt");
    }
  }

  uint8_t layer = biton32(layer_state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
  case 1:
    ergodox_right_led_1_on();
    break;
  case 2:
    ergodox_right_led_2_on();
    break;
  case 3:
    ergodox_right_led_3_on();
    break;
  case 4:
    ergodox_right_led_1_on();
    ergodox_right_led_2_on();
    break;
  case 5:
    ergodox_right_led_1_on();
    ergodox_right_led_3_on();
    break;
  case 6:
    ergodox_right_led_2_on();
    ergodox_right_led_3_on();
    break;
  case 7:
    ergodox_right_led_1_on();
    ergodox_right_led_2_on();
    ergodox_right_led_3_on();
    break;
  default:
    break;
  }
};
