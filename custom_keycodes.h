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
  TE_LEFT,
  TE_RGHT,
  TE_DOWN,
  TE_ROT,
  TE_RES,
  TE_PAUS,

  // No-op key that maintains lighting (!= KC_NO)
  INF_NUL,
  // No-op key that indicates the current layer
  INF_IND,

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
