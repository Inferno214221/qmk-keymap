#include QMK_KEYBOARD_H

#include "layers.h"

#include "inactivity.h"
#include "sounds.h"

static deferred_token inactivity_token;

static deferred_token fade_out_timer;

static inactivity_state_t inactivity_state = STATE_ACTIVE;

uint32_t on_fade_out_finished(uint32_t trigger_time, void *cb_arg) {
  inactivity_state = STATE_SLEEP;
  rgb_matrix_mode_noeeprom(RGB_MATRIX_DIGITAL_RAIN);
  return 0;
}

uint32_t on_keyboard_inactivity(uint32_t trigger_time, void *cb_arg) {
  inactivity_state = STATE_FADING_OUT;
  rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_FADE_OUT);
  fade_out_timer = defer_exec(RGB_MATRIX_FADE_OUT_DURATION_MS, on_fade_out_finished, NULL);
  return 0;
}

void inactivity_on_keyboard_post_init(void) {
  inactivity_token = defer_exec(INACTIVITY_TIMEOUT, on_keyboard_inactivity, NULL);
}

void inactivity_on_proccess_record(void) {
  switch (inactivity_state) {
    case STATE_FADING_OUT:
      cancel_deferred_exec(fade_out_timer);
      skip_next_sound();
      layer_move(L_DEF);
    case STATE_SLEEP:
      inactivity_token = defer_exec(INACTIVITY_TIMEOUT, on_keyboard_inactivity, NULL);
      skip_next_sound();
      layer_move(L_DEF);
    default:
      break;
  }
  inactivity_state = STATE_ACTIVE;
  extend_deferred_exec(inactivity_token, INACTIVITY_TIMEOUT);
}