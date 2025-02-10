#include QMK_KEYBOARD_H

#include "string.h"

enum layer_number {
    _QWERTY = 0,
    _SYMB,
    _ACCENT,
    _FUNC,
    _MOVE,
};

enum custom_keycodes {
    KX_EURO = SAFE_RANGE,
    KX_EGRV,
    KX_AGRV,
    KX_IGRV,
    KX_OGRV,
    KX_UGRV,
    KX_DGRE,
    KX_ORDN,
    KX_LEFT,
    KX_DOWN,
    KX_UP,
    KX_RIGHT,
    KX_LDAQM,
    KX_RDAQM,
};

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

    [_QWERTY] = LAYOUT(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_EQL, KC_TAB, KC_Q, KC_W, KC_E, LT(_ACCENT, KC_R), KC_T, KC_Y, LT(_ACCENT, KC_U), KC_I, KC_O, KC_P, KC_MINS, KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LALT, KC_Z, KC_X, KC_C, KC_V, KC_B, OSL(_SYMB), TO(_SYMB), KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RCTL, TO(_QWERTY), KC_LGUI, KC_LCTL, KC_SPC, KC_RSFT, MO(_MOVE), KC_BSPC, KC_DEL),
    /* MOVE
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |   `  |      |      |      |      |      |                    | App  |      |      |      |      | PSCR |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      | BTN2 |MWLeft|MUp   |MWRgt |MWUp  |                    | Home |Pg dow|Pg up | End  |  [   |  ]   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      | BRN3 |MLeft |MDown |MRight|MWDown|-------.    ,-------| Left | Down |  Up  |Right |  =   |OSL(4)|
     * |------+------+------+------+------+------| TT(2) |    | TO(2) |------+------+------+------+------+------|
     * |      |  \   |      |      |      |      |-------|    |-------| BTN1 |Enter |  (   |   )  |  /   | TO(5)|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   |      |      |      | /       /       \      \  |      |      |      |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */
    [_MOVE] = LAYOUT(KC_GRV, _______, _______, _______, _______, _______, KC_APP, _______, _______, _______, _______, KC_PSCR, _______, KC_BTN2, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_LBRC, KC_RBRC, _______, KC_BTN3, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_EQL, OSL(_ACCENT), _______, KC_BSLS, _______, _______, _______, _______, OSL(_SYMB), TO(_SYMB), KC_BTN1, KC_ENT, KC_LPRN, KC_RPRN, KC_SLSH, TO(_FUNC), _______, _______, _______, _______, _______, _______, _______, _______),
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
     *                   |TO(0) |      |      | /       /       \      \  |MO(1) |      |      |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */
    [_SYMB] = LAYOUT(KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_NUM, _______, _______, _______, KC_PAST, KC_PEQL, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_PENT, KC_P7, KC_P8, KC_P9, KC_PPLS, _______, KC_F13, KC_F14, KC_F15, KC_F16, KC_F17, KC_F18, KC_P0, KC_P4, KC_P5, KC_P6, KC_PMNS, _______, KC_F21, KC_F20, KC_F21, KC_F22, KC_F23, KC_F24, TO(_SYMB), TO(_SYMB), KC_PDOT, KC_P1, KC_P2, KC_P3, KC_PSLS, _______, TO(_QWERTY), KC_LALT, _______, _______, _______, MO(_MOVE), _______, _______),
    /* Accent layout
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | ESC  |  ºª  |   2  |  £€  |   4  |   5  |                    |   6  |   7  |   8  |   9  |  °   |  =   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |   Q  |   W  |  èé  |   R  |   T  |                    |   Y  |  ùú  |  ìí  |  òó  |   P  |  -   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |LShift|  àà  |   S  |   D  |   F  |   G  |-------.    ,-------|   ←  |   ↓  |   ↑  |   →  |   ;  |TO(4) |
     * |------+------+------+------+------+------|OSL(2) |    | TO(2) |------+------+------+------+------+------|
     * |LAlt  |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |  «   |   »  |   /  |RCtrl |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   | TO(0)| LGUI |LCtrl | / Space /       \RShift\  |MO(1) |BackSp| Del  |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */
    [_ACCENT] = LAYOUT(KC_ESC, KX_ORDN, KC_2, KX_EURO, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KX_DGRE, KC_EQL, KC_TAB, KC_Q, KC_W, KX_EGRV, KC_R, KC_T, KC_Y, KX_UGRV, KX_IGRV, KX_OGRV, KC_P, KC_MINS, KC_LSFT, KX_AGRV, KC_S, KC_D, KC_F, KC_G, KX_LEFT, KX_DOWN, KX_UP, KX_RIGHT, KC_SCLN, TO(_ACCENT), KC_LALT, KC_Z, KC_X, KC_C, KC_V, KC_B, OSL(_SYMB), TO(_SYMB), KC_N, KC_M, KX_LDAQM, KX_RDAQM, KC_SLSH, KC_RCTL, TO(_QWERTY), KC_LGUI, KC_LCTL, KC_SPC, KC_RSFT, MO(_MOVE), KC_BSPC, KC_DEL),
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
    [_FUNC] = LAYOUT(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPLY, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, OSL(_SYMB), TO(_SYMB), _______, KC_MUTE, _______, _______, _______, _______, TO(_QWERTY), _______, _______, _______, _______, MO(_MOVE), _______, _______)};

/**************** Key definition ****************/

const uint16_t PROGMEM combo_caps_lock[] = {KC_LSFT, KC_RSFT, COMBO_END};
combo_t                key_combos[]      = {
    COMBO(combo_caps_lock, KC_CAPS),
};

// SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
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
        switch (get_highest_layer(layer_state)) {
            case _QWERTY:
                oled_write("1", true);
                oled_write("....", false);
                oled_write_ln("Main", false);
                break;
            case _SYMB:
                oled_write(".", false);
                oled_write("2", true);
                oled_write("...", false);
                oled_write_ln("Symbl", false);
                break;
            case _ACCENT:
                oled_write("..", false);
                oled_write("3", true);
                oled_write("..", false);
                oled_write_ln("Accnt", false);
                break;
            case _FUNC:
                oled_write("...", false);
                oled_write("4", true);
                oled_write(".", false);
                oled_write_ln("Funct", false);
                break;
            case _MOVE:
                oled_write("....", false);
                oled_write("5", true);
                oled_write_ln("Move", false);
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

void send_altcode_v2(uint16_t mask, bool leading_zero, keyrecord_t *record) {
    // Check & save mod state
    static uint8_t lalt_mask;
    lalt_mask = keyboard_report->mods & KC_LALT;

    // Check & save numlock state
    bool bNumLockWasOn = host_keyboard_led_state().num_lock;

    // Split up the mask into its 4 decimals
    static uint16_t kp[4];

    // if the number doesn't have leading zeros, use -1 as KC_NO
    kp[3] = (mask % 10) + ((mask >= 0) ? 0 : -1) * !leading_zero;
    kp[2] = (mask / 10) % 10 + ((mask >= 10) ? 0 : -1) * !leading_zero;
    kp[1] = (mask / 100) % 10 + ((mask >= 100) ? 0 : -1) * !leading_zero;
    kp[0] = (mask / 1000) % 10 + ((mask >= 1000) ? 0 : -1) * !leading_zero;

    // Convert to keycaps
    for (uint8_t i = 0; i <= 3; i++) {
        switch (kp[i]) {
            case 0:
                kp[i] = KC_KP_0;
                break;
            case 1:
                kp[i] = KC_KP_1;
                break;
            case 2:
                kp[i] = KC_KP_2;
                break;
            case 3:
                kp[i] = KC_KP_3;
                break;
            case 4:
                kp[i] = KC_KP_4;
                break;
            case 5:
                kp[i] = KC_KP_5;
                break;
            case 6:
                kp[i] = KC_KP_6;
                break;
            case 7:
                kp[i] = KC_KP_7;
                break;
            case 8:
                kp[i] = KC_KP_8;
                break;
            case 9:
                kp[i] = KC_KP_9;
                break;
            case -1:
                kp[i] = KC_NO;
                break;
        }
    }

    // Put ALT into pressed state
    if (!lalt_mask) {
        register_code(KC_LALT);
        send_keyboard_report();
    }

    // If not enabled, enable numlock
    if (!bNumLockWasOn) {
        register_code(KC_LNUM);
        send_keyboard_report();
    }

    // Send keycodes
    for (uint8_t i = 0; i <= 3; i++) {
        add_key(kp[i]);
        send_keyboard_report();
        del_key(kp[i]);
        send_keyboard_report();
    }

    // If user wasn't pressing ALT, release it
    if (!lalt_mask) {
        unregister_code(KC_LALT);
        send_keyboard_report();
    }

    // If it wasn't enabled before, disable numlock
    if (!bNumLockWasOn) {
        unregister_code(KC_LNUM);
        send_keyboard_report();
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    const uint8_t mod_state  = get_mods();
    const bool    ctrl_held  = (mod_state & MOD_MASK_CTRL) != 0;
    const bool    shift_held = (mod_state & MOD_MASK_SHIFT) != 0;

    const led_t led_state    = host_keyboard_led_state();
    const bool  caps_lock_on = led_state.caps_lock;

    /* When a key is kept down, the keycode gets repeated */
    switch (keycode) {
        case KC_MINS: // With CAPS_LOCK invert '-' with '_'
            if (caps_lock_on) {
                if (record->event.pressed) {
                    if (shift_held) {
                        unregister_mods(MOD_MASK_SHIFT);
                        register_code(KC_MINS);
                        set_mods(mod_state);
                    } else {
                        register_mods(MOD_MASK_SHIFT);
                        register_code(KC_MINS);
                        set_mods(mod_state);
                    }
                } else {
                    unregister_code(KC_MINS);
                }
                return false;
            }
            break;
    }

    /* When a key is kept down, the keycode is sent only once */
    if (record->event.pressed) {
        switch (keycode) {
            case KX_LDAQM:
                send_altcode_v2(171, true, record);
                return false;
                break;

            case KX_RDAQM:
                send_altcode_v2(187, true, record);
                return false;
                break;

            case KX_EURO:
                if (shift_held) {
                    unregister_mods(MOD_MASK_SHIFT);
                    send_altcode_v2(163, true, record); // £
                } else {
                    send_altcode_v2(128, true, record); // €
                }
                set_mods(mod_state);
                return false;
                break;

            case KX_EGRV:
                if (ctrl_held & shift_held) {
                    unregister_mods(MOD_MASK_SHIFT);
                    unregister_mods(MOD_MASK_CTRL);
                    send_altcode_v2(201, true, record); // É
                } else if (ctrl_held) {
                    unregister_mods(MOD_MASK_CTRL);
                    send_altcode_v2(233, true, record); // é
                } else if (shift_held) {
                    unregister_mods(MOD_MASK_SHIFT);
                    send_altcode_v2(200, true, record); // È
                } else {
                    send_altcode_v2(232, true, record); // è
                }
                set_mods(mod_state);
                return false;
                break;

            case KX_AGRV:
                if (ctrl_held & shift_held) {
                    unregister_mods(MOD_MASK_SHIFT);
                    unregister_mods(MOD_MASK_CTRL);
                    send_altcode_v2(193, true, record); // Á
                } else if (ctrl_held) {
                    unregister_mods(MOD_MASK_CTRL);
                    send_altcode_v2(225, true, record); // á
                } else if (shift_held) {
                    unregister_mods(MOD_MASK_SHIFT);
                    send_altcode_v2(192, true, record); // À
                } else {
                    send_altcode_v2(224, true, record); // à
                }
                set_mods(mod_state);
                return false;
                break;

            case KX_UGRV:
                if (ctrl_held & shift_held) {
                    unregister_mods(MOD_MASK_SHIFT);
                    unregister_mods(MOD_MASK_CTRL);
                    send_altcode_v2(218, true, record); // Á
                } else if (ctrl_held) {
                    unregister_mods(MOD_MASK_CTRL);
                    send_altcode_v2(250, true, record); // ú
                } else if (shift_held) {
                    unregister_mods(MOD_MASK_SHIFT);
                    send_altcode_v2(217, true, record); // Ù
                } else {
                    send_altcode_v2(249, true, record); // ù
                }
                set_mods(mod_state);
                return false;
                break;

            case KX_IGRV:
                if (ctrl_held & shift_held) {
                    unregister_mods(MOD_MASK_SHIFT);
                    unregister_mods(MOD_MASK_CTRL);
                    send_altcode_v2(205, true, record); // Í
                } else if (ctrl_held) {
                    unregister_mods(MOD_MASK_CTRL);
                    send_altcode_v2(237, true, record); // í
                } else if (shift_held) {
                    unregister_mods(MOD_MASK_SHIFT);
                    send_altcode_v2(204, true, record); // Ì
                } else {
                    send_altcode_v2(236, true, record); // ì
                }
                set_mods(mod_state);
                return false;
                break;

            case KX_OGRV:
                if (ctrl_held & shift_held) {
                    unregister_mods(MOD_MASK_SHIFT);
                    unregister_mods(MOD_MASK_CTRL);
                    send_altcode_v2(211, true, record); // Ó
                } else if (ctrl_held) {
                    unregister_mods(MOD_MASK_CTRL);
                    send_altcode_v2(243, true, record); // ó
                } else if (shift_held) {
                    unregister_mods(MOD_MASK_SHIFT);
                    send_altcode_v2(210, true, record); // Ò
                } else {
                    send_altcode_v2(242, true, record); // ò
                }
                set_mods(mod_state);
                return false;
                break;

            case KX_DGRE:
                send_altcode_v2(176, true, record); // °
                return false;
                break;

            case KX_ORDN:
                if (shift_held) {
                    unregister_mods(MOD_MASK_SHIFT);
                    send_altcode_v2(170, true, record); // ª
                } else {
                    send_altcode_v2(186, true, record); // º
                }
                set_mods(mod_state);
                return false;
                break;

            case KX_LEFT:
                send_altcode_v2(27, false, record); // ←
                return false;
                break;

            case KX_DOWN:
                send_altcode_v2(25, false, record); // ↓
                return false;
                break;

            case KX_UP:
                send_altcode_v2(24, false, record); // ↑
                return false;
                break;

            case KX_RIGHT:
                send_altcode_v2(26, false, record); // →
                return false;
                break;
        }
    }
    return true;
}
