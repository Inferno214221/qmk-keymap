#include QMK_KEYBOARD_H

#include "layers.h"

#include "one_handed.h"

void led_indicators_on_layer_set_state(layer_state_t state) {
  STATUS_LED_1(is_caps_word_on());
  STATUS_LED_2(leader_sequence_active());
  STATUS_LED_3(!audio_is_on());
  if (!is_one_handed()) {
    STATUS_LED_4(IS_LAYER_ON_STATE(state, L_GAM));
    STATUS_LED_5(IS_LAYER_ON_STATE(state, L_NUM) || IS_LAYER_ON_STATE(state, L_GAM));
    STATUS_LED_6(IS_LAYER_ON_STATE(state, L_FUN) || IS_LAYER_ON_STATE(state, L_GAM));
  }
}

void led_indicators_on_layer_set_tetris(void) {
  STATUS_LED_1(false);
  STATUS_LED_2(false);
  STATUS_LED_3(false);
  STATUS_LED_4(true);
  STATUS_LED_5(true);
  STATUS_LED_6(true);
}

void led_indicators_on_caps_word_set(bool active) {
  STATUS_LED_1(active);
}

void led_indicators_on_leader_start(void) {
  STATUS_LED_2(true);
}

void led_indicators_on_leader_end(void) {
  STATUS_LED_2(false);
}
void led_indicators_on_audio_on(void) {
  STATUS_LED_3(false);
}

void led_indicators_on_audio_off(void) {
  STATUS_LED_3(true);
}