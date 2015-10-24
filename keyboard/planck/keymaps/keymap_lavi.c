#include "keymap_common.h"
#include "backlight.h"
#include "debug.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = { /* Qwerty */
{KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
{KC_MINS, KC_A,    KC_S,    KC_D,   KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
{KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT},
{KC_LCTL, KC_LALT, KC_LGUI, KC_APP, FUNC(2), KC_SPC,  KC_SPC,  FUNC(1), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
                                                // Space is repeated to accommadate for both spacebar wiring positions
},
[1] = { /* RAISE */
{KC_ESC,  KC_1,    KC_2,    KC_3,       KC_4,       KC_5,    KC_6,    KC_7,       KC_8,    KC_9,    KC_0,    KC_DEL},
{KC_EQL,  S(KC_1), S(KC_2), S(KC_3),    S(KC_4),    S(KC_5), S(KC_6), S(KC_7),    S(KC_8), S(KC_9), S(KC_0), S(KC_EQL)},
{KC_TRNS, KC_LBRC, KC_RBRC, S(KC_LBRC), S(KC_RBRC), KC_GRV,  KC_TRNS, S(KC_NUHS), S(KC_NUBS), KC_NUHS, KC_NUBS, KC_TRNS},
{KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    FUNC(3),    KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}
},
[2] = { /* LOWER */
{KC_F1,   KC_F2,   KC_F3,   KC_F4,     KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12},
{KC_SLCK, KC_HOME, KC_PGUP, KC_PGDOWN, KC_END,  KC_INS,  KC_PSCR, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PAUS},
{KC_TRNS, KC_MNXT, KC_MPLY, KC_VOLD,   KC_VOLU, KC_MUTE, KC_CAPS, KC_BTN1, KC_BTN3, KC_BTN2, KC_WH_L, KC_TRNS},
{KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, FUNC(3), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}
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
