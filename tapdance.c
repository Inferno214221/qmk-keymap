#include QMK_KEYBOARD_H

enum custom_tapdance {
  T_COPY
};

void tap_copy_cut_each(tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code(KC_LCTL);
    register_code(KC_C);
  } else {
    unregister_code(KC_C);
    register_code(KC_X);
  }
}

void tap_copy_cut_finish(tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code(KC_C);
  } else {
    unregister_code(KC_X);
  }
  unregister_code(KC_LCTL);
}

void tap_copy_cut_reset(tap_dance_state_t *state, void *user_data) {
  // Do nothing
}

tap_dance_action_t tap_dance_actions[] = {
  // [T_COPY] = ACTION_TAP_DANCE_DOUBLE(LCTL(KC_C), LCTL(KC_X)),
  // This looks a lot like the basic keycode above but there are some differences:
  // - We eagerly send copy, swapping to cut if the tapdance continues. Will register both key
  //   combos but should be harmless unless trying to send Ctrl+X to a terminal process.
  // - Register the relevant keycodes on the way down and unregister on finish, more like a normal
  //   key. This is an advantage of being able to eagerly send copy.
  [T_COPY] = ACTION_TAP_DANCE_FN_ADVANCED(tap_copy_cut_each, tap_copy_cut_finish, tap_copy_cut_reset),
};