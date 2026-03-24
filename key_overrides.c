#include QMK_KEYBOARD_H

#include "layers.h"

#define KEY_OVERRIDE_SHIFT_OR_COMBO(NAME_NONE, NAME_SHIFT, FROM, TO) \
const key_override_t NAME_NONE = ko_make_with_layers_and_negmods(0, FROM, TO, 1 << L_DEF, ~0); \
const key_override_t NAME_SHIFT = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, FROM, FROM, 1 << L_DEF, ~MOD_MASK_SHIFT);

KEY_OVERRIDE_SHIFT_OR_COMBO(o_lcbr_1_none, o_lcbr_1_shift, KC_1, KC_LCBR);
KEY_OVERRIDE_SHIFT_OR_COMBO(o_rcbr_2_none, o_rcbr_2_shift, KC_2, KC_RCBR);
KEY_OVERRIDE_SHIFT_OR_COMBO(o_labk_3_none, o_labk_3_shift, KC_3, KC_LABK);
KEY_OVERRIDE_SHIFT_OR_COMBO(o_rabk_4_none, o_rabk_4_shift, KC_4, KC_RABK);
// KEY_OVERRIDE_SHIFT_OR_COMBO(o_xxxx_5_none, o_xxxx_5_shift, KC_5, KC_NO);
// KEY_OVERRIDE_SHIFT_OR_COMBO(o_xxxx_6_none, o_xxxx_6_shift, KC_6, KC_NO);
KEY_OVERRIDE_SHIFT_OR_COMBO(o_lbrc_7_none, o_lbrc_7_shift, KC_7, KC_LBRC);
KEY_OVERRIDE_SHIFT_OR_COMBO(o_rbrc_8_none, o_rbrc_8_shift, KC_8, KC_RBRC);
KEY_OVERRIDE_SHIFT_OR_COMBO(o_lprn_9_none, o_lprn_9_shift, KC_9, KC_LPRN);
KEY_OVERRIDE_SHIFT_OR_COMBO(o_rprn_0_none, o_rprn_0_shift, KC_0, KC_RPRN);

// No negmods means that ctrl+shift combos will always produce unique inputs, regardless off what
// that combo is actually read as.
#define KEY_OVERRIDE_SHIFT(NAME, FROM, TO) \
const key_override_t NAME = ko_make_with_layers(MOD_MASK_SHIFT, FROM, TO, 1 << L_DEF);

KEY_OVERRIDE_SHIFT(o_comm_astr, KC_COMM, KC_DLR);
KEY_OVERRIDE_SHIFT(o_dot_dot,   KC_DOT,  KC_DOT);
KEY_OVERRIDE_SHIFT(o_slsh_bsls, KC_SLSH, KC_BSLS);
KEY_OVERRIDE_SHIFT(o_exlm_circ, KC_EXLM, KC_CIRC);
KEY_OVERRIDE_SHIFT(o_ampr_pipe, KC_AMPR, KC_PIPE);
KEY_OVERRIDE_SHIFT(o_ques_perc, KC_QUES, KC_AT);
KEY_OVERRIDE_SHIFT(o_hash_dlr,  KC_ASTR, KC_HASH);

const key_override_t *key_overrides[] = {
  &o_lcbr_1_none,
  &o_lcbr_1_shift,
  &o_rcbr_2_none,
  &o_rcbr_2_shift,
  &o_labk_3_none,
  &o_labk_3_shift,
  &o_rabk_4_none,
  &o_rabk_4_shift,
  // &o_xxxx_5_none,
  // &o_xxxx_5_shift,
  // &o_xxxx_6_none,
  // &o_xxxx_6_shift,
  &o_lbrc_7_none,
  &o_lbrc_7_shift,
  &o_rbrc_8_none,
  &o_rbrc_8_shift,
  &o_lprn_9_none,
  &o_lprn_9_shift,
  &o_rprn_0_none,
  &o_rprn_0_shift,

  &o_hash_dlr,
  &o_comm_astr,
  &o_dot_dot,
  &o_slsh_bsls,
  &o_exlm_circ,
  &o_ampr_pipe,
  &o_ques_perc,
};
