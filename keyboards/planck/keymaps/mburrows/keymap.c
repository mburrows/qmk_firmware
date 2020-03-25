#include "planck.h"
#include "action_layer.h"
#include "config.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _COLEMAK,
  _LOWER,
  _RAISE,
  _NAV
};

enum custom_keycodes {
    MC_00 = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  |  '   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | ESC  | N_A  | S_R  | A_S  | C_T  | H_D  | H_H  | C_N  | A_E  | S_I  | N_O  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Shift(|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Shift)|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Lead | Ctl  | Alt  |  OS  |  Lwr | BSPC | Space|  Rse | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = {
  {  KC_TAB, KC_Q,    KC_W,    KC_F,    KC_P,     KC_G,     KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_QUOT  },
  {  KC_ESC, NAV_A,   S_R,     A_S,     C_T,      H_D,      H_H,     C_N,     A_E,     S_I,     NAV_O,   KC_ENT   },
  { KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,     KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC  },
  { KC_LEAD, OSM_CTL, OSM_ALT, OSM_GUI, LWR_BSPC, KC_BSPC,  KC_SPC,  RSE_SPC, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  }
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |   +  |   4  |   5  |   6  |   *  |   =  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  F12 |  F6  |  F7  |  F8  |  F9  | F10  |   -  |   1  |   2  |   3  |   /  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   0  |   0  |   .  |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  { _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______ },
  { KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_PLUS, KC_4,    KC_5,    KC_6,    KC_ASTR, KC_EQL  },
  { KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_MINS, KC_1,    KC_2,    KC_3,    KC_SLSH, _______ },
  { _______, _______, _______, _______, _______, _______, _______, KC_0,    KC_0,    KC_DOT,  _______, _______ }
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |  `   |   !  |   @  |   {  |   }  |   |  |      |      |   *  |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  \   |   #  |   $  |   (  |   )  |   &  | INS  |   -  |   =  |   "  |   '  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   %  |   ^  |   [  |   ]  |   ~  |CPSLCK|   _  |   +  |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      | DEL  |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  { KC_GRV,  KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, _______, _______, KC_ASTR, _______, _______, _______ },
  { KC_BSLS, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_AMPR, KC_INS,  KC_MINS, KC_EQL,  KC_DQUO, KC_QUOT, _______ },
  { _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_CAPS, KC_UNDS, KC_PLUS, _______, _______, _______ },
  { _______, _______, _______, _______, _______, KC_DEL, _______,  _______, _______, _______, _______, _______ }
},

/* Navigation
 * ,-----------------------------------------------------------------------------------.
 * |RESET |      | Back | MsUp | Fwd  | WhUp |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |MsLeft| MsDn |MsRght| WhDn | Left | Down |  Up  | Right|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      | LClk | MClk | RClk |      | Home | PgDn | PgUp | End  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Next | VolD | VolU | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_NAV] = {
  { RESET,   _______, KC_WBAK, KC_MS_U, KC_WFWD, KC_WH_U, _______, _______, _______, _______, _______, _______ },
  { _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______ },
  { _______, _______, KC_BTN1, KC_BTN3, KC_BTN2, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______ },
  { _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY }
},

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MC_00:
            if (record->event.pressed) {
                SEND_STRING("00");
            }
            break;
    }
    return true;
}

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    // Single key macros
    SEQ_ONE_KEY(KC_W) {
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
      SEND_STRING(SS_LCTRL(" ")"]");
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
      SEND_STRING("git status -sb");
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
      SEND_STRING ("{code}");
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
}
