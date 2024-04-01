#include QMK_KEYBOARD_H

#include "keymap_french.h"
#include "sendstring_french.h"
#include "string.h"

enum layer_number {
  _QWERTY = 0,
  _SYMB,
  _ACCENT,
  _FUNC,
  _MOVE,
};

// enum custom_keycodes {
//     EURO,
// };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|OSL(2) |    | TO(2) |------+------+------+------+------+------|
 * |LAlt  |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RCtrl |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | TO(0)| LGUI |LCtrl | / Space /       \RShift\  |MO(1) |BackSp| Del  |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  KC_LSFT,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LALT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, OSL(_SYMB), TO(_SYMB),  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RCTL,
                        TO(_QWERTY), KC_LGUI, KC_LCTL, KC_SPC, KC_RSFT, MO(_MOVE), KC_BSPC, KC_DEL
),
/* MOVE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   `  |      |      |      |      |      |                    |      |      |      |      |      | PSCR |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | BTN2 |MWLeft|MUp   |MWRgt |MWUp  |                    | Home |Pg dow|Pg up | End  |  [   |  ]   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |MLeft |MDown |MRight|MWDown|-------.    ,-------| Left | Down |  Up  |Right |  =   | TO(4)|
 * |------+------+------+------+------+------| TT(2) |    | TO(2) |------+------+------+------+------+------|
 * |      |  \   |      |      |      |      |-------|    |-------| BTN1 |Enter |  (   |   )  |  /   | TO(5)|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_MOVE] = LAYOUT(
  KC_GRV,  _______, _______, _______, _______, _______,                        KC_APP, _______, _______, _______, _______, KC_PSCR,
  _______, KC_BTN2, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U,                       KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_LBRC, KC_RBRC,
  _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,                        KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_EQL,  TO(_ACCENT),
  _______, KC_BSLS, _______, _______, _______, _______, OSL(_SYMB), TO(_SYMB), KC_BTN1, KC_ENT,  KC_LPRN, KC_RPRN, KC_SLSH, TO(_FUNC),
                             _______, _______, _______, _______,    _______,   _______, _______, _______
),
/* SYMB
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    | NumL |      |      |      |  *   |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |                    |      |  7   |  8   |  9   |  +   |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F13 |  F14 |  F15 |  F16 |  F17 |  F18 |-------.    ,-------|  0   |  4   |  5   |  6   |  -   |      |
 * |------+------+------+------+------+------| TT(2) |    | TO(2) |------+------+------+------+------+------|
 * |  F19 |  F20 |  F21 |  F22 |  F23 |  F24 |-------|    |-------|  .   |  1   |  2   |  3   |  /   |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_SYMB] = LAYOUT(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                          KC_NUM,  _______, _______, _______, KC_PAST, KC_PEQL,
  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,                         KC_PENT, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, _______,
  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,                         KC_P0,   KC_P4,   KC_P5,   KC_P6,   KC_PMNS, _______,
  KC_F21,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24, TO(_SYMB), TO(_SYMB),   KC_PDOT, KC_P1,   KC_P2,   KC_P3,   KC_PSLS, _______,
                             TO(_QWERTY), KC_LALT, _______, _______,    _______,   MO(_MOVE), _______, _______
),
/* Colemak layout
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   ;  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LSHIFT|   A  |   R  |   S  |   T  |   G  |-------.    ,-------|   M  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------| TT(2) |    | TO(2) |------+------+------+------+------+------|
 * |LALT  |   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |   /  |RCTRL |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | TO(0)| LGUI |LCTRL | / SPACE /       \RSHIFT\  |BACKSP|MO(1) | DEL  |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
 [_ACCENT] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
  KC_TAB,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_MINS,
  KC_LSFT,  KC_A,   KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
  KC_LALT,  KC_Z,   KC_X,    KC_C,    KC_D,    KC_V,  OSL(_SYMB), TO(_SYMB), KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_CAPS, KC_RCTL,
                        TO(_QWERTY), KC_LGUI, KC_LCTL, KC_SPC, KC_RSFT, MO(_MOVE), KC_BSPC, KC_DEL
),
/* Functions layout
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |Play/P|      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------| TT(2) |    | TO(2) |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |Mute  |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | TO(0)|      |      | /       /       \      \  |      |MO(1) |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
 [_FUNC] = LAYOUT(
  _______,   _______,   _______,    _______,    _______,    _______,                           _______,    _______,    _______,    _______,    _______, _______,
  _______,   _______,   _______,    _______,    _______,    _______,                           _______,    _______,    _______,    _______,    KC_MPLY, _______,
  _______,  _______,   _______,    _______,    _______,    _______,                            _______,    _______,    _______,    _______,    _______, _______,
  _______,  _______,   _______,    _______,    _______,    _______,  OSL(_SYMB),    TO(_SYMB), _______,    KC_MUTE,    _______, _______,  _______, _______,
                        TO(_QWERTY), _______, _______, _______,                      _______, MO(_MOVE), _______, _______
)
};

/**************** Key definition ****************/

const uint16_t PROGMEM combo_caps_lock[] = {KC_LSFT, KC_RSFT, COMBO_END};
combo_t key_combos[] = {
    COMBO(combo_caps_lock, KC_CAPS),
};

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) return rotation; // flips the display 180 degrees if offhand
    return OLED_ROTATION_270;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_logo(void);

bool oled_task_user(void) {
    oled_set_cursor(0, 1);

    if (is_keyboard_master()) {
        // Current layer
        switch (get_highest_layer(layer_state)) {
            case _QWERTY:
                oled_write("1", true);
                oled_write("....", false);
                oled_write_ln("Main", false);
                break;
            case _MOVE:
                oled_write(".", false);
                oled_write("2", true);
                oled_write("...", false);
                oled_write_ln("Move", false);
                break;
            case _SYMB:
                oled_write("..", false);
                oled_write("3", true);
                oled_write("..", false);
                oled_write_ln("Symb", false);
                break;
            case _ACCENT:
                oled_write("...", false);
                oled_write("4", true);
                oled_write(".", false);
                oled_write_ln("Accnt", false);
                break;
            case _FUNC:
                oled_write("....", false);
                oled_write("5", true);
                oled_write_ln("Func", false);
                break;
        }

        // Caps lock status
        led_t led_state = host_keyboard_led_state();
        oled_set_cursor(0, 4);
        oled_write_ln("Caps", false);
        oled_write_ln_P(led_state.caps_lock ? PSTR(" On  ") : PSTR(" Off "), led_state.caps_lock);
        // Num lock status
        oled_set_cursor(0, 7);
        oled_write_ln("Num", false);
        oled_write_ln_P(led_state.num_lock ? PSTR(" On  ") : PSTR(" Off "), led_state.num_lock);


    } else {
        oled_write(read_logo(), false);
    }

    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}
