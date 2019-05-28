#include QMK_KEYBOARD_H
#include "bootloader.h"
#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

extern keymap_config_t keymap_config;
extern uint8_t is_master;

// Layers
#define _COLEMAK 0
#define _LOWER 1
#define _RAISE 2
#define _NAV 3

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

#define KC______ KC_TRNS
#define KC_XXXXX KC_NO
#define KC_LOWER LT(_LOWER, KC_LBRC)
#define KC_RAISE LT(_RAISE, KC_RBRC)
#define KC_RST   RESET
#define KC_H_TAB HYPR_T(KC_TAB)
#define KC_C_ESC CTL_T(KC_ESC)
#define KC_C_ENT CTL_T(KC_ENT)
#define KC_G_BSP LGUI_T(KC_BSPC)
#define KC_CA_BS LCA_T(KC_BSPC)
#define KC_NAV_A LT(_NAV,KC_A)
#define KC_NAV_O LT(_NAV,KC_O)
#define KC_L_ESC LT(_LOWER,KC_ESC)
#define KC_R_ENT LT(_RAISE,KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
      H_TAB,     Q,     W,     F,     P,     G,                      J,     L,     U,     Y,  SCLN,  QUOT,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      C_ESC, NAV_A,     R,     S,     T,     D,                      H,     N,     E,     I, NAV_O, C_ENT,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LSPO,     Z,     X,     C,     V,     B,                      K,     M,  COMM,   DOT,  SLSH,  RSPC,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                   LALT, LOWER, G_BSP,      SPC, RAISE,  LEAD \
                              //`--------------------'  `--------------------'
  ),

  [_LOWER] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
      XXXXX,     1,     2,     3,     4,     5,                      6,     7,     8,     9,     0,  ASTR,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
        F11,    F1,    F2,    F3,    F4,    F5,                    DOT,     4,     5,     6,  MINS,   EQL,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
        F12,    F6,    F7,    F8,    F9,   F10,                      0,     1,     2,     3,  SLSH,  PLUS,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  _____, _____, _____,    _____, _____, _____ \
                              //`--------------------'  `--------------------'
  ),

  [_RAISE] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
        GRV,  EXLM,    AT,  LCBR,  RCBR,  PIPE,                  XXXXX, XXXXX,  ASTR, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       BSLS,  HASH,   DLR,  LPRN,  RPRN,  AMPR,                    INS,  MINS,   EQL,  DQUO,  QUOT, XXXXX,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      XXXXX,  PERC,  CIRC,  LBRC,  RBRC,  TILD,                   CAPS,  UNDS,  PLUS, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  _____, _____,   DEL,    _____, _____, _____ \
                              //`--------------------'  `--------------------'
  ),

  [_NAV] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
        RST, XXXXX,  WBAK,  MS_U,  WFWD,  WH_U,                   MPRV,  VOLD,  VOLU,  MNXT,  MPLY,  BRIU,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      XXXXX, XXXXX,  MS_L,  MS_D,  MS_R,  WH_D,                   LEFT,  DOWN,    UP,  RGHT, XXXXX,  BRID,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,                   HOME,  PGDN,  PGUP,   END, XXXXX, XXXXX,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                   BTN3,  BTN2,  BTN1,    _____, _____, _____ \
                              //`--------------------'  `--------------------'
  )
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

void matrix_init_user(void) {
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
// const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

char matrix_line_str[24];

const char *read_layer_state(void) {
  uint8_t layer = biton32(layer_state);
  
  strcpy(matrix_line_str, "Layer: ");
  
  switch (layer)
  {
    case _COLEMAK:
      strcat(matrix_line_str, "Default");
      break;
    case _LOWER:
      strcat(matrix_line_str, "Lower");
      break;
    case _RAISE:
      strcat(matrix_line_str, "Raise");
      break;
    case _NAV:
      strcat(matrix_line_str, "Navigation");
      break;
    default:
      sprintf(matrix_line_str + strlen(matrix_line_str), "Unknown (%d)", layer);
  }

  return matrix_line_str;
}

char host_led_state_str[24];

const char *read_host_led_state(void)
{
  uint8_t leds = host_keyboard_leds();
  snprintf(host_led_state_str, sizeof(host_led_state_str), "CapsLock:%s",
           (leds & (1 << USB_LED_CAPS_LOCK)) ? "on" : "- ");

  return host_led_state_str;
}

LEADER_EXTERNS();

void matrix_scan_user(void) {
    iota_gfx_task();

    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        // Single key macros
        SEQ_ONE_KEY(KC_2) {
            SEND_STRING (" 2>&1");
        }
        SEQ_ONE_KEY(KC_G) {
            SEND_STRING("grep -E ''"SS_TAP(X_LEFT));
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

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    //matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}
