#include QMK_KEYBOARD_H

#include "custom_keycodes.h"

#include "last_key.h"

#define MODS_ANY get_mods()
// #define MODS_SHIFT (get_mods() & MOD_BIT_LSHIFT)
#define NOT_PRECEDING_BACKSLASH get_last_key() != S(KC_SLASH)
#define NOT_BACKSLASH_OR_LEFT not_preceding_bsls_or_left()

bool not_preceding_bsls_or_left(void) {
  switch (get_last_key()) {
    case S(KC_SLASH):
    case KC_LEFT:
    case KC_HOME:
      return false;
    default:
      return true;
  }
}

void unshifted_tap(uint8_t key) {
  unregister_code(KC_LEFT_SHIFT);
  tap_code(key);
  restore_shift();
}

bool smart_brackets_on_process_record(uint16_t keycode, keyrecord_t *record) {
  // manually strack shift status and then impl accurate holding functionality.
  switch (keycode) {
    // This has no hold functionality at the moment.
    case PR_PAREN:
      if (record->event.pressed) {
        if (MODS_ANY) {
          unshifted_tap(KC_9);
        } else {
          register_code(KC_LEFT_SHIFT);
          tap_code(KC_9);

          if (NOT_BACKSLASH_OR_LEFT) {
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

          if (NOT_BACKSLASH_OR_LEFT) {
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

          if (NOT_BACKSLASH_OR_LEFT) {
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

        if (is_shifted() && NOT_PRECEDING_BACKSLASH) {
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

        if (!is_shifted() && NOT_PRECEDING_BACKSLASH) {
          tap_code(KC_GRAVE);
          tap_code(KC_LEFT);
        }
      }
      return false;

    case PR_AMPIP:
      if (record->event.pressed) {
        if (is_shifted()) {
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

    case MA_ARROW:
      if (record->event.pressed) {
        if (MODS_ANY) {
          unshifted_tap(KC_5);
        } else {
          tap_code(KC_MINUS);
          register_code(KC_LEFT_SHIFT);
          tap_code(KC_DOT);
          unregister_code(KC_LEFT_SHIFT);
        }
      }
      return false;

    case MA_SLICE:
      if (record->event.pressed) {
        if (MODS_ANY) {
          unshifted_tap(KC_6);
        } else {
          register_code(KC_LEFT_SHIFT);
          tap_code(KC_7);
          unregister_code(KC_LEFT_SHIFT);
          tap_code(KC_LEFT_BRACKET);
          tap_code(KC_RIGHT_BRACKET);
          tap_code(KC_LEFT);
        }
      }
      return false;

    default:
      return true;
  }
}