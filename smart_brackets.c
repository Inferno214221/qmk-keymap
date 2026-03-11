#include QMK_KEYBOARD_H

#include "custom_keycodes.h"

#include "last_key.h"

#define MODS_ANY get_mods()
#define MODS_SHIFT (get_mods() & MOD_BIT_LSHIFT)
#define SHIFTED_SLASH S(KC_SLASH)

void unshifted_tap(uint8_t key) {
  bool was_shifted = MODS_SHIFT;
  unregister_code(KC_LEFT_SHIFT);
  tap_code(key);
  if (was_shifted) {
    register_code(KC_LEFT_SHIFT);
  }
}

bool smart_brackets_on_process_record(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // This has no hold functionality at the moment.
    case PR_PAREN:
      if (record->event.pressed) {
        if (MODS_ANY) {
          unshifted_tap(KC_9);
        } else {
          register_code(KC_LEFT_SHIFT);
          tap_code(KC_9);

          if (get_last_key() != SHIFTED_SLASH) {
            tap_code(KC_0);
            unregister_code(KC_LEFT_SHIFT);
            tap_code(KC_LEFT);
          } else {
            unregister_code(KC_LEFT_SHIFT);
          }
        }
      }
      return false;

    case PR_BRACK:
      if (record->event.pressed) {
        if (MODS_ANY) {
          unshifted_tap(KC_7);
        } else {
          tap_code(KC_LEFT_BRACKET);

          if (get_last_key() != SHIFTED_SLASH) {
            tap_code(KC_RIGHT_BRACKET);
            tap_code(KC_LEFT);
          }
        }
      }
      return false;

    case PR_BRACE:
      if (record->event.pressed) {
        if (MODS_ANY) {
          unshifted_tap(KC_1);
        } else {
          register_code(KC_LEFT_SHIFT);
          tap_code(KC_LEFT_BRACKET);

          if (get_last_key() != SHIFTED_SLASH) {
            tap_code(KC_RIGHT_BRACKET);
            unregister_code(KC_LEFT_SHIFT);
            tap_code(KC_LEFT);
          } else {
            unregister_code(KC_LEFT_SHIFT);
          }
        }
      }
      return false;

    case PR_ANGLE:
      if (record->event.pressed) {
        if (MODS_ANY) {
          unshifted_tap(KC_3);
        } else {
          switch (get_last_key()) {
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
      }
      return false;

    case PR_QUOTE:
      if (record->event.pressed) {
        tap_code(KC_QUOTE);

        if (MODS_SHIFT && get_last_key() != SHIFTED_SLASH) {
          tap_code(KC_QUOTE);
          unregister_code(KC_LEFT_SHIFT);
          tap_code(KC_LEFT);
          register_code(KC_LEFT_SHIFT);
        }
      }
      return false;
    case PR_BTICK:
      if (record->event.pressed) {
        tap_code(KC_GRAVE);

        if (!MODS_SHIFT && get_last_key() != SHIFTED_SLASH) {
          tap_code(KC_GRAVE);
          tap_code(KC_LEFT);
        }
      }
      return false;

    case PR_AMPIP:
      if (record->event.pressed) {
        if (MODS_SHIFT) {
          tap_code(KC_BACKSLASH);

          switch (get_last_key()) {
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
      }
      return false;

    default:
      return true;
  }
}