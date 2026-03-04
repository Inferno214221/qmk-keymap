#include QMK_KEYBOARD_H

#include "custom_keycodes.h"

#include "audio.h"

float sfx_mario_coin      [][2] = SONG(COIN_SOUND);
float sfx_mario_mushroom  [][2] = SONG(MARIO_MUSHROOM);
float sfx_mario_one_up    [][2] = SONG(ONE_UP_SOUND);
float sfx_zelda_puzzle    [][2] = SONG(ZELDA_PUZZLE);
float sfx_zelda_treasure  [][2] = SONG(ZELDA_TREASURE);
float song_e1m1_doom      [][2] = SONG(E1M1_DOOM);
float song_imperial_march [][2] = SONG(IMPERIAL_MARCH);
float song_mario_theme    [][2] = SONG(MARIO_THEME);
float song_megalovania    [][2] = SONG(MEGALOVANIA);
float song_rick_roll      [][2] = SONG(RICK_ROLL);
float song_tetris_theme   [][2] = SONG(TETRIS_THEME);

// Effectively a &[[f32; 2]]
typedef struct {
  // In Rust this would read something like &[[f32; 2]; _] because C types are read starting from
  // the identifier. I'm not entirely sure why its valid to take a pointer to an implicitly sized
  // array, rather than the first element itself but that's what audio_play_melody expects. It's
  // essentially a slice without a length anyway.
  float (*notes)[][2];
  uint16_t len;
} song_slice_t;

#define SONG_SLICE(song) \
{ \
  .notes = &song, \
  .len = ARRAY_SIZE(song) \
}

song_slice_t songs[] = {
  SONG_SLICE(song_e1m1_doom),
  SONG_SLICE(song_megalovania),
  SONG_SLICE(song_rick_roll),
  SONG_SLICE(song_tetris_theme),
  SONG_SLICE(song_mario_theme),
  SONG_SLICE(song_imperial_march),
  SONG_SLICE(sfx_zelda_puzzle),
  SONG_SLICE(sfx_zelda_treasure),
  SONG_SLICE(sfx_mario_coin),
  SONG_SLICE(sfx_mario_one_up),
  SONG_SLICE(sfx_mario_mushroom),
};

static uint8_t song_index = 0;

#define PLAY_SONG_SLICE(song) audio_play_melody(song.notes, song.len, false)

void song_play(void) {
  PLAY_SONG_SLICE(songs[song_index]);
}

void song_stop(void) {
  audio_stop_all();
}

void song_next(void) {
  song_index++;
  if (song_index >= ARRAY_SIZE(songs)) {
    song_index = 0;
  }
  song_play();
}

void song_prev(void) {
  if (song_index == 0) {
    song_index = ARRAY_SIZE(songs) - 1;
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