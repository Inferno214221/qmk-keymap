#include QMK_KEYBOARD_H

enum custom_tapdance {
  T_COPY
};

tap_dance_action_t tap_dance_actions[] = {
  [T_COPY] = ACTION_TAP_DANCE_DOUBLE(LCTL(KC_C), LCTL(KC_X)),
};