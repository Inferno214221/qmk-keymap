#include QMK_KEYBOARD_H

void unicode_leader_on_leader_end(void) {
  if (leader_sequence_two_keys(KC_P, KC_M)) {
    register_unicode(0x00B1);
  } else if (leader_sequence_two_keys(KC_M, KC_U)) {
    register_unicode(0x00B5);
  } else if (leader_sequence_two_keys(KC_T, KC_M)) {
    register_unicode(0x2122);
  } else if (leader_sequence_three_keys(KC_D, KC_E, KC_G)) {
    register_unicode(0x00B0);
  } else if (leader_sequence_three_keys(KC_D, KC_I, KC_V)) {
    register_unicode(0x00F7);
  } else if (leader_sequence_three_keys(KC_G, KC_T, KC_E)) {
    register_unicode(0x2265);
  } else if (leader_sequence_three_keys(KC_L, KC_T, KC_E)) {
    register_unicode(0x2264);
  } else if (leader_sequence_three_keys(KC_A, KC_P, KC_R)) {
    register_unicode(0x2248);
  } else if (leader_sequence_five_keys(KC_T, KC_I, KC_M, KC_E, KC_S)) {
    register_unicode(0x00D7);
  }
}