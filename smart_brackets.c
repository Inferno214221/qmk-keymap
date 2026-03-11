#include QMK_KEYBOARD_H

#include "custom_keycodes.h"

// TODO: Avoid double taps following a '\'.

bool smart_brackets_on_process_record(uint16_t keycode, keyrecord_t *record) {
  static uint16_t last_keycode;
  switch (keycode) {
    // This has no hold functionality at the moment.
    case PR_PAREN:
      if (record->event.pressed) {
        if (get_mods()) {
          bool was_shifted = get_mods() & MOD_BIT_LSHIFT;
          unregister_code(KC_LEFT_SHIFT);
          tap_code(KC_9);
          if (was_shifted) {
            register_code(KC_LEFT_SHIFT);
          }
        } else {
          register_code(KC_LEFT_SHIFT);
          tap_code(KC_9);
          tap_code(KC_0);
          unregister_code(KC_LEFT_SHIFT);
          tap_code(KC_LEFT);
        }
        last_keycode = keycode;
      }
      return false;
    case PR_BRACK:
      if (record->event.pressed) {
        if (get_mods()) {
          bool was_shifted = get_mods() & MOD_BIT_LSHIFT;
          unregister_code(KC_LEFT_SHIFT);
          tap_code(KC_7);
          if (was_shifted) {
            register_code(KC_LEFT_SHIFT);
          }
        } else {
          tap_code(KC_LEFT_BRACKET);
          tap_code(KC_RIGHT_BRACKET);
          tap_code(KC_LEFT);
        }
        last_keycode = keycode;
      }
      return false;
    case PR_BRACE:
      if (record->event.pressed) {
        if (get_mods()) {
          bool was_shifted = get_mods() & MOD_BIT_LSHIFT;
          unregister_code(KC_LEFT_SHIFT);
          tap_code(KC_1);
          if (was_shifted) {
            register_code(KC_LEFT_SHIFT);
          }
        } else {
          register_code(KC_LEFT_SHIFT);
          tap_code(KC_LEFT_BRACKET);
          tap_code(KC_RIGHT_BRACKET);
          unregister_code(KC_LEFT_SHIFT);
          tap_code(KC_LEFT);
        }
        last_keycode = keycode;
      }
      return false;
    case PR_ANGLE:
      if (record->event.pressed) {
        if (get_mods()) {
          bool was_shifted = get_mods() & MOD_BIT_LSHIFT;
          unregister_code(KC_LEFT_SHIFT);
          tap_code(KC_3);
          if (was_shifted) {
            register_code(KC_LEFT_SHIFT);
          }
        } else {
          switch (last_keycode) {
            case KC_A ... KC_Z:
              register_code(KC_LEFT_SHIFT);
              tap_code(KC_COMMA);
              tap_code(KC_DOT);
              unregister_code(KC_LEFT_SHIFT);
              tap_code(KC_LEFT);
              break;
            default:
              tap_code16(KC_LEFT_ANGLE_BRACKET);
              break;
          }
        }
        last_keycode = keycode;
      }
      return false;
    case PR_QUOTE:
      if (record->event.pressed) {
        tap_code(KC_QUOTE);
        if (get_mods() & MOD_BIT_LSHIFT) {
          tap_code(KC_QUOTE);
          unregister_code(KC_LEFT_SHIFT);
          tap_code(KC_LEFT);
          register_code(KC_LEFT_SHIFT);
        }
        last_keycode = keycode;
      }
      return false;
    case PR_BTICK:
      if (record->event.pressed) {
        tap_code(KC_GRAVE);
        if (!(get_mods() & MOD_BIT_LSHIFT)) {
          tap_code(KC_GRAVE);
          tap_code(KC_LEFT);
        }
        last_keycode = keycode;
      }
      return false;
    case PR_AMPIP:
      if (record->event.pressed) {
        if (get_mods() & MOD_BIT_LSHIFT) {
          tap_code(KC_BACKSLASH);
          switch (last_keycode) {
            case PR_PAREN:
            case KC_TAB:
              tap_code(KC_BACKSLASH);
              unregister_code(KC_LEFT_SHIFT);
              tap_code(KC_LEFT);
              register_code(KC_LEFT_SHIFT);
              break;
          }
        } else {
          tap_code16(KC_AMPERSAND);
        }
        last_keycode = keycode;
      }
      return false;
    default:
      if (record->event.pressed && keycode != KC_LEFT_SHIFT) last_keycode = keycode;
      return true;
  }
}