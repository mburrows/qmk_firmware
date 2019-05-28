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
  TD_COPY_PASTE = 0
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_COPY_PASTE]  = ACTION_TAP_DANCE_DOUBLE(LSFT(LCTL(KC_C)),LSFT(LCTL(KC_V)))
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Colemak layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |    `   |   1  |   2  |   3  |   4  |   5  |   {  |           |  }   |   6  |   7  |   8  |   9  |   0  |    =   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |    \   |   Q  |   W  |   F  |   P  |   G  |   [  |           |  ]   |   J  |   L  |   U  |   Y  |   ;  |    -   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Ctrl   |A(NAV)|   R  |   S  |   T  |   D  |------|           |------|   H  |   N  |   E  |   I  |O(NAV)|CtlQuot |
 * |--------+------+------+------+------+------| Del  |           | Tab  |------+------+------+------+------+--------|
 * | Shift( |   Z  |   X  |   C  |   V  |   B  |      |           |      |   K  |   M  |   ,  |   .  |   /  | Shift) |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Lead | Hyp  | Alt  | Gui  |  NUM |                                       |  SYM | Left | Down |  Up  | Right|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |CtlSpc|Cp/Pst|       |CtlAlt|CtlTab|
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      | Gui  | Home |       | PgUp |      |      |
 *                                 |  BS  |  /   |------|       |------| Enter| Space|
 *                                 |      | Esc  | End  |       | PgDn |      |      |
 *                                 `--------------------'       `--------------------'
 */
  [_COLEMAK] = LAYOUT_ergodox(
               // left hand
               KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LCBR,
               KC_BSLS,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_LBRACKET,
               KC_LCTL,  NAV_A,   KC_R,    KC_S,    KC_T,    KC_D,
               KC_LSPO,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_DEL,

               KC_LEAD,  OSM_HYP, OSM_ALT, OSM_GUI, OSL_NUM,

                                                        LCTL(KC_SPC), TD(TD_COPY_PASTE),  
                                                                      CTL_T(KC_HOME),
                                                    KC_BSPC, GUI_ESC, ALT_T(KC_END),
               // right hand
               KC_RCBR,     KC_6, KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
               KC_RBRACKET, KC_J, KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_MINS,
                            KC_H, KC_N,    KC_E,    KC_I,    NAV_O,   CTL_QUOT,
               KC_TAB,      KC_K, KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,

                                  OSL_SYM, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,

               OSM(MOD_LCTL|MOD_LALT), LCTL(KC_TAB),
               CTL_T(KC_PGUP),
               ALT_T(KC_PGDN),         KC_ENT, KC_SPC),

/* Number layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  | F10  |  F11   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |  Up  |   7  |   8  |   9  |   *  |  F12   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------| Down |   4  |   5  |   6  |   +  |   =    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |   1  |   2  |   3  |   /  |        |
 * `--------+------+------+------+------+-------------            `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |   .  |   0  |   -  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
  [_NUM] = LAYOUT_ergodox(
               // left hand
               _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,
               _______, _______, _______, _______, _______, _______, _______,
               _______, _______, _______, _______, _______, _______,
               _______, _______, _______, _______, _______, _______, _______,

               _______, _______, _______, _______, _______,

                                                            _______, _______,
                                                                     _______,
                                                   _______, _______, _______,

               // right hand
               _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
               _______, KC_UP,   KC_7,    KC_8,    KC_9,    KC_ASTR, KC_F12,
                        KC_DOWN, KC_4,    KC_5,    KC_6,    KC_PLUS, KC_EQL,
               _______, _______, KC_1,    KC_2,    KC_3,    KC_SLSH, _______,

                                 _______, KC_DOT,  KC_0,    KC_MINS, _______,


               _______, _______,
               _______,
               _______, _______, _______),

/* Symbol layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  | F10  |  F11   |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |      |   `  |   *  |      |      |  F12   |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   &  |------|           |------| INS  |   -  |   =  |      |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |CPSLCK|   _  |   +  |      |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
  [_SYM] = LAYOUT_ergodox(
               // left hand
               _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,
               _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, _______,
               _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_AMPR,
               _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, _______,

               _______, _______, _______, _______, _______,

                                                            _______, _______,
                                                                     _______,
                                                   _______, _______, _______,

               // right hand
               _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
               _______, _______, KC_GRV,  KC_ASTR, _______, _______, KC_F12,
                        KC_INS,  KC_MINS, KC_EQL,  _______, _______, _______,
               _______, KC_CAPS, KC_UNDS, KC_PLUS, _______, _______, _______,

                                 _______, _______, _______, _______, _______,

               _______, _______,
               _______,
               _______, _______, _______),

/* Navigation layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |CtlTab| Back | MsUp |  Fwd | WhUp |      |           |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |MsLeft| MsDn |MSRght| WhDn |------|           |------| Left | Down |  Up  | Right|      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      | LClk | MClk | RClk |      |      |           |      |      |      |      |      |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | MClk |      |       | Mute | Prev |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | WhUp |       | VolU |      |      |
 *                                 | LClk | RClk |------|       |------| Play | Next |
 *                                 |      |      | WhDn |       | VolD |      |      |
 *                                 `--------------------'       `--------------------'
 */
  [_NAV] = LAYOUT_ergodox(
               // left hand
               _______, _______, _______, _______, _______,  _______, _______,
               _______, CTL_TAB, KC_WBAK, KC_MS_U, KC_WFWD,  KC_WH_U, _______,
               _______, _______, KC_MS_L, KC_MS_D, KC_MS_R,  KC_WH_D,
               _______, _______, KC_BTN1, KC_BTN3, KC_BTN2,  _______, _______,

               _______, _______, _______, _______, _______,

                                                              KC_BTN3, _______,
                                                                       KC_WH_U,
                                                     KC_BTN1, KC_BTN2, KC_WH_D,

               // right hand
               _______, _______, _______, _______, _______, _______, _______,
               _______, _______, _______, _______, _______, _______, _______,
                        KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
               _______, _______, _______, _______, _______, _______, _______,

                                 _______, _______, _______, _______, _______,

               KC_MUTE, KC_MPRV,
               KC_VOLU,
               KC_VOLD, KC_MPLY, KC_MNXT),

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
      SEND_STRING ("{noformat}\n\n{noformat}"SS_TAP(X_UP));
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
