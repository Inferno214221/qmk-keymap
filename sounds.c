#include QMK_KEYBOARD_H

#include "layers.h"

#include "music.h"

#include "audio.h"

float sfx_caps_on       [][2] = SONG(CAPS_LOCK_ON_SOUND);
float sfx_caps_off      [][2] = SONG(CAPS_LOCK_OFF_SOUND);
float sfx_layer_on      [][2] = SONG(SCROLL_LOCK_ON_SOUND);
float sfx_layer_off     [][2] = SONG(SCROLL_LOCK_OFF_SOUND);
float sfx_unicode_start [][2] = SONG(NUM_LOCK_ON_SOUND);
float sfx_unicode_end   [][2] = SONG(NUM_LOCK_OFF_SOUND);
float sfx_alt_key_press [][2] = SONG(TERMINAL_SOUND);

static bool skip_sound = false;

void sounds_on_keyboard_post_init(void) {
  skip_sound = true;
}

void sounds_on_layer_set_state(layer_state_t state) {
  if (skip_sound) {
    skip_sound = false;
    return;
  }
  
  switch (get_highest_layer(state)) {
    case L_GAM:
      PLAY_SONG(sfx_mario_mushroom);
      break;
    case L_DEF:
      PLAY_SONG(sfx_layer_off);
      break;
    default:
      PLAY_SONG(sfx_layer_on);
  }
}

void sounds_on_leader_start(void) {
  PLAY_SONG(sfx_unicode_start);
}

void sounds_on_leader_end(void) {
  PLAY_SONG(sfx_unicode_end);
}

void sounds_on_caps_word_set(bool active) {
  if (active) {
    PLAY_SONG(sfx_caps_on);
  } else {
    PLAY_SONG(sfx_caps_off);
  }
}

void sounds_on_alt_key_press(void) {
  PLAY_SONG(sfx_alt_key_press);
}

void skip_next_sound(void) {
  skip_sound = true;
}