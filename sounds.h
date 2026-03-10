#include QMK_KEYBOARD_H

void sounds_on_keyboard_post_init(void);

void sounds_on_layer_set_state(layer_state_t state);

void sounds_on_leader_start(void);

void sounds_on_leader_end(void);

void sounds_on_caps_word_set(bool active);

void sounds_on_alt_key_press(void);

void skip_next_sound(void);