#include QMK_KEYBOARD_H

static uint16_t last_keycode;

uint16_t get_last_key(void) {
    return last_keycode;
}

void last_key_on_process_record(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) return;
    switch (keycode) {
        case KC_LEFT_SHIFT:
            break;
        default:
            last_keycode = (get_mods() & MOD_BIT_LSHIFT) ? S(keycode) : keycode;
    }
}