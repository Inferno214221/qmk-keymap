#pragma once

#include QMK_KEYBOARD_H
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
  // Keyboard-level Music Controls
  KM_PLAY = ZSA_SAFE_RANGE,
  KM_STOP,
  KM_NEXT,
  KM_PREV,

  // Tetris Keycodes
  TET_LEFT,
  TET_RGHT,
  TET_DOWN,
  TET_ROT,
  TET_RES,
  TET_PAUS
};