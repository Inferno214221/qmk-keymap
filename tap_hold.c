#include QMK_KEYBOARD_H

#include "custom_keycodes.h"

bool tap_hold_on_process_record(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Tap hold functionality for non-basic keycode.
    case TH_ALTU:
      if (record->event.pressed) {
        if (record->tap.count) {
          // Tap
          leader_start();
        } else {
          // Hold
          register_code16(KC_LALT);
        }
      } else if (!record->tap.count) {
        // Un-hold
        unregister_code16(KC_LALT);
      }
      return false;
  }
  return true;
}