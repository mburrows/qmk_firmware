#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _BASE 0
#define _LOWER 1
#define _RAISE 2
#define _NAV 3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_kc( \
 //,----------------------------------,                             ,----------------------------------,
         Q,     W,     F,     P,     G,                                   J,     L,     U,     Y,  SCLN,\
 //|------+------+------+------+------|                             |------+------+------+------+------|
       N_A,   S_R,   A_S,   C_T,   H_D,                                 H_H,   C_N,   A_E,   S_I,   N_O,\
 //|------+------+------+------+------|                             |------+------+------+------+------|
       S_Z,     X,     C,     V,     B,                                   K,     M,  COMM,   DOT, S_SLS,\
 //|------+------+------+------+------,                             ,------+------+------+------+------,
             LEAD,   F13,                                                             F12,C_RBRC,\
        //'------+------+-------------'                             '-------------+------+------'
                          LOWER,  BSPC,                                 SPC, RAISE,\
                      //'------+------'                             '------+------'
                                    //'------+------' '------+------'
                                        G_ESC,   DEL,     TAB,   ENT,\
                                    //'------+------' '------+------'
                                         HOME,   END,    PGDN,  PGUP \
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
       RST,  WBAK,  MS_U,  WFWD,  WH_U,                               C_LFT,  C_DN,  C_UP, C_RGT, XXXXX,\
 //|------+------+------+------+------|                             |------+------+------+------+------|
     XXXXX,  MS_L,  MS_D,  MS_R,  WH_D,                                LEFT,  DOWN,    UP,  RGHT, XXXXX,\
 //|------+------+------+------+------|                             |------+------+------+------+------|
     XXXXX,  BTN1,  BTN3,  BTN2, XXXXX,                                HOME,  PGDN,  PGUP,   END, XXXXX,\
 //|------+------+------+------+------,                             ,------+------+------+------+------,
            _____, _____,                                                            BRID,  BRIU,\
        //'------+------'-------------'                             '-------------'------+------'
                           BTN2,  BTN1,                                MPLY,  MNXT,\
                      //'------+------'                             '------+------'
                                    //'------+------' '------+------'
                                         BTN3, _____,    VOLU,  MPRV,\
                                    //'------+------' '------+------'
                                        _____, _____,    VOLD, _____ \
                                    //'------+------' '------+------'
)
};

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
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
            SEND_STRING("find . -name ");
        }
        SEQ_ONE_KEY(KC_G) {
            SEND_STRING("grep -E ''"SS_TAP(X_LEFT));
        }
        SEQ_ONE_KEY(KC_I) {
          SEND_STRING(" \\_inline.h");
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
        SEQ_TWO_KEYS(KC_G, KC_Q) {
            SEND_STRING("git log --oneline");
        }
        SEQ_TWO_KEYS(KC_G, KC_B) {
            SEND_STRING("git branch ");
        }
        SEQ_TWO_KEYS(KC_G, KC_V) {
            SEND_STRING("git svn");
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
        SEQ_TWO_KEYS(KC_J, KC_B) {
            SEND_STRING ("https://jira.bats.com/browse/EUCPP-");
        }

        // SQL macros
        SEQ_TWO_KEYS(KC_S, KC_S) {
            SEND_STRING ("select * from ");
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
