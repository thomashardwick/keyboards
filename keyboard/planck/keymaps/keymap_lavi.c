#include "keymap_common.h"
#include "backlight.h"
#include "debug.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = { /* Qwerty */
{KC_TAB,        KC_Q,          KC_W,    KC_E,   KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
{KC_MINS,       KC_A,          KC_S,    KC_D,   KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
{KC_LCTL,       KC_Z,          KC_X,    KC_C,   KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT},
{LCTL(KC_LSFT), LCTL(KC_LALT), KC_LGUI, KC_APP, KC_LSFT, KC_SPC,  KC_SPC,  FUNC(1), FUNC(2), KC_RALT, KC_UP,   KC_LALT}
                                                // Space is repeated to accommadate for both spacebar wiring positions
},
[1] = { /* RAISE */
{KC_ESC,  KC_1,    KC_2,    KC_3,      KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL},
{KC_CAPS, KC_LEFT, KC_DOWN, KC_UP,     KC_RGHT, KC_PSCR, KC_SLCK, KC_PAUS, KC_NUHS, KC_LBRC, KC_RBRC, KC_EQL},
{KC_TRNS, KC_HOME, KC_PGUP, KC_PGDOWN, KC_END,  KC_VOLU, KC_VOLD, KC_MUTE, KC_INS,  KC_GRV,  KC_NUBS, KC_TRNS},
{KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, FUNC(3), KC_TRNS, KC_TRNS, KC_TRNS}
},
[2] = { /* LOWER */
{KC_NLCK, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_P7,  KC_P8,    KC_P9,   LCTL(LALT(KC_P7)), LCTL(LALT(KC_P8)), LCTL(LALT(KC_P9)), KC_TRNS},
{KC_TRNS, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_P4,  KC_P5,    KC_P6,   LCTL(LALT(KC_P4)), LCTL(LALT(KC_P5)), LCTL(LALT(KC_P6)), KC_TRNS},
{KC_TRNS, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_P1,  KC_P2,    KC_P3,   LCTL(LALT(KC_P1)), LCTL(LALT(KC_P2)), LCTL(LALT(KC_P3)), KC_TRNS},
{KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, FUNC(3), KC_TRNS,           KC_TRNS,           KC_TRNS,           KC_TRNS}
},
[3] = { /* RESET */
{KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET},
{KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
{KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
{KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}
}
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_MOMENTARY(1),  // to RAISE
    [2] = ACTION_LAYER_MOMENTARY(2),  // to LOWER
    [3] = ACTION_LAYER_MOMENTARY(3)  // to LOWER
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
          backlight_step();
        } else {
          unregister_code(KC_RSFT);
        }
        break;
      }
    return MACRO_NONE;
};
