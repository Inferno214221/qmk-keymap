#include QMK_KEYBOARD_H

#include "custom_keycodes.h"

static uint16_t last_keycode;

static bool shifted;
static bool alted;

uint16_t get_last_key(void) {
    return last_keycode;
}

bool is_shifted(void) {
    return shifted;
}

void restore_shift(void) {
    if (shifted) {
        register_code(KC_LEFT_SHIFT);
    } else {
        unregister_code(KC_LEFT_SHIFT);
    }
}

bool is_alted(void) {
    return alted;
}

void restore_alt(void) {
    if (alted) {
        register_code(KC_LEFT_ALT);
    } else {
        unregister_code(KC_LEFT_ALT);
    }
}

void last_key_on_process_record(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_LEFT_SHIFT:
            shifted = record->event.pressed;
            break;
        case TH_ALTU:
            alted = record->event.pressed;
        default:
            if (record->event.pressed) {
                last_keycode = (get_mods() & MOD_BIT_LSHIFT) ? S(keycode) : keycode;
            }
            break;
    }
}