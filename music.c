#include QMK_KEYBOARD_H

#include "custom_keycodes.h"

#include "audio.h"

float song_tetris_theme[][2] = SONG(TETRIS_THEME);
float song_imperial_march[][2] = SONG(IMPERIAL_MARCH);
float sfx_coin[][2] = SONG(COIN_SOUND);
float sfx_one_up[][2] = SONG(ONE_UP_SOUND);
float sfx_zelda_puzzle[][2] = SONG(ZELDA_PUZZLE);
float sfx_zelda_treasure[][2] = SONG(ZELDA_TREASURE);
float song_mario_theme[][2] = SONG(MARIO_THEME);
float sfx_mario_mushroom[][2] = SONG(MARIO_MUSHROOM);
float song_e1m1_doom[][2] = SONG(E1M1_DOOM);
float song_rick_roll[][2] = SONG(RICK_ROLL);
float song_megalovania[][2] = SONG(MEGALOVANIA);

static uint8_t song_index = 0;

#define SONG_COUNT 11

void song_play(void) {
  switch (song_index) {
    case 0:
      PLAY_SONG(song_tetris_theme);
      break;
    case 1:
      PLAY_SONG(song_imperial_march);
      break;
    case 2:
      PLAY_SONG(sfx_coin);
      break;
    case 3:
      PLAY_SONG(sfx_one_up);
      break;
    case 4:
      PLAY_SONG(sfx_zelda_puzzle);
      break;
    case 5:
      PLAY_SONG(sfx_zelda_treasure);
      break;
    case 6:
      PLAY_SONG(song_mario_theme);
      break;
    case 7:
      PLAY_SONG(sfx_mario_mushroom);
      break;
    case 8:
      PLAY_SONG(song_e1m1_doom);
      break;
    case 9:
      PLAY_SONG(song_rick_roll);
      break;
    case 10:
      PLAY_SONG(song_megalovania);
      break;
  }
}

void song_stop(void) {
  audio_stop_all();
}

void song_next(void) {
  song_index++;
  if (song_index >= SONG_COUNT) {
    song_index = 0;
  }
  song_play();
}

void song_prev(void) {
  if (song_index == 0) {
    song_index = SONG_COUNT - 1;
  } else {
    song_index--;
  }
  song_play();
}

bool music_on_process_record(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Keyboard-level Music Controls
    case KM_PLAY:
      if (record->event.pressed) song_play();
      return false;
    case KM_STOP:
      if (record->event.pressed) song_stop();
      return false;
    case KM_NEXT:
      if (record->event.pressed) song_next();
      return false;
    case KM_PREV:
      if (record->event.pressed) song_prev();
      return false;
  }
  return true;
}

void music_on_layer_set_gaming(void) {
  PLAY_SONG(sfx_mario_mushroom);
}