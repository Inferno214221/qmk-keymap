#pragma once

#include QMK_KEYBOARD_H
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
  // Keyboard-level music controls
  KM_PLAY = ZSA_SAFE_RANGE,
  KM_STOP,
  KM_NEXT,
  KM_PREV,

  // Tetris keycodes
  TET_LEFT,
  TET_RGHT,
  TET_DOWN,
  TET_ROT,
  TET_RES,
  TET_PAUS,

  // No-op key that maintains lighting (!= KC_NO)
  INF_NULL,

  // Paired keys
  // PR_PAREN,
  // PR_BRACK,
  // PR_BRACE,
  // PR_ANGLE,
  // PR_QUOTE,
  // PR_BTICK,
  // PR_AMPIP,
  MA_ARROW,
  MA_SLICE,
};

// Tap hold keycodes
#define TH_ALTU LT(0, 0)
