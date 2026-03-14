#include QMK_KEYBOARD_H

#define UL1(a, cp)             if (leader_sequence_one_key(a))               { register_unicode(cp); } else
#define UL2(a, b, cp)          if (leader_sequence_two_keys(a, b))           { register_unicode(cp); } else
#define UL3(a, b, c, cp)       if (leader_sequence_three_keys(a, b, c))      { register_unicode(cp); } else
#define UL4(a, b, c, d, cp)    if (leader_sequence_four_keys(a, b, c, d))    { register_unicode(cp); } else
#define UL5(a, b, c, d, e, cp) if (leader_sequence_five_keys(a, b, c, d, e)) { register_unicode(cp); } else

void unicode_leader_on_leader_end(void) {
  // Greek
  UL3(         KC_A, KC_L, KC_P,    0x03B1)  // alp   -> α
  UL3(         KC_B, KC_E, KC_T,    0x03B2)  // bet   -> β
  UL3(         KC_G, KC_A, KC_M,    0x03B3)  // gam   -> γ
  UL4(KC_LSFT, KC_G, KC_A, KC_M,    0x0393)  // Gam   -> Γ
  UL3(         KC_D, KC_E, KC_L,    0x03B4)  // del   -> δ
  UL4(KC_LSFT, KC_D, KC_E, KC_L,    0x0394)  // Del   -> Δ
  UL3(         KC_E, KC_P, KC_S,    0x03B5)  // eps   -> ε
  UL3(         KC_Z, KC_E, KC_T,    0x03B6)  // Zet   -> ζ
  UL3(         KC_T, KC_H, KC_E,    0x03B8)  // the   -> θ
  UL4(KC_LSFT, KC_T, KC_H, KC_E,    0x0398)  // The   -> Θ
  UL3(         KC_L, KC_A, KC_M,    0x03BB)  // lam   -> λ
  UL4(KC_LSFT, KC_L, KC_A, KC_M,    0x039B)  // Lam   -> Λ
  UL2(         KC_M, KC_U,          0x03BC)  // mu    -> µ
  UL2(         KC_X, KC_I,          0x03BE)  // xi    -> ξ
  UL3(KC_LSFT, KC_X, KC_I,          0x039E)  // Xi    -> Ξ
  UL2(         KC_P, KC_I,          0x03C0)  // pi    -> π
  UL3(KC_LSFT, KC_P, KC_I,          0x03A0)  // Pi    -> Π
  UL3(         KC_S, KC_I, KC_G,    0x03C3)  // sig   -> σ
  UL4(KC_LSFT, KC_S, KC_I, KC_G,    0x03A3)  // Sig   -> Σ
  UL3(         KC_P, KC_H, KC_I,    0x03C6)  // phi   -> φ
  UL4(KC_LSFT, KC_P, KC_H, KC_I,    0x03A6)  // Phi   -> Φ
  UL3(         KC_P, KC_S, KC_I,    0x03C8)  // psi   -> ψ
  UL4(KC_LSFT, KC_P, KC_S, KC_I,    0x03A8)  // Psi   -> Ψ
  UL2(         KC_O, KC_M,          0x03C9)  // om    -> ω
  UL3(KC_LSFT, KC_O, KC_M,          0x03A9)  // Om    -> Ω
  UL3(         KC_R, KC_H, KC_O,    0x03C1)  // rho   -> ρ

  // Math
  UL3(KC_D, KC_E, KC_G,             0x00B0)  // deg   -> °
  UL4(KC_T, KC_I, KC_M, KC_E,       0x00D7)  // time  -> ×
  UL3(KC_D, KC_I, KC_V,             0x00F7)  // div   -> ÷
  UL3(KC_G, KC_T, KC_E,             0x2265)  // gte   -> ≥
  UL3(KC_L, KC_T, KC_E,             0x2264)  // lte   -> ≤
  UL3(KC_A, KC_P, KC_R,             0x2248)  // apr   -> ≈
  UL3(KC_N, KC_E, KC_Q,             0x2260)  // neq   -> ≠
  UL3(KC_S, KC_Q, KC_R,             0x221A)  // sqr   -> √
  UL2(KC_P, KC_M,                   0x00B1)  // pm    -> ±
  UL2(KC_M, KC_P,                   0x2213)  // mp    -> ∓
  UL3(KC_D, KC_O, KC_T,             0x22C5)  // dot   -> ⋅
  UL3(KC_I, KC_N, KC_T,             0x222B)  // int   -> ∫
  UL3(KC_I, KC_N, KC_F,             0x221E)  // inf   -> ∞
  UL3(KC_P, KC_R, KC_O,             0x221D)  // pro   -> ∝
  UL4(KC_L, KC_E, KC_F, KC_T,       0x2190)  // left  -> ←
  UL5(KC_R, KC_I, KC_G, KC_H, KC_T, 0x2192)  // right -> →

  // Set Theory
  UL2(KC_I, KC_N,                   0x2208)  // in    -> ∈
  UL3(KC_N, KC_I, KC_N,             0x2209)  // nin   -> ∉
  UL3(KC_S, KC_U, KC_B,             0x2282)  // sub   -> ⊂
  UL3(KC_S, KC_U, KC_P,             0x2283)  // sup   -> ⊃
  UL5(KC_U, KC_N, KC_I, KC_O, KC_N, 0x222A)  // union -> ∪
  UL5(KC_I, KC_N, KC_T, KC_E, KC_R, 0x2229)  // inter -> ∩
  UL3(KC_X, KC_O, KC_R,             0x2295)  // xor   -> ⊕
  UL3(KC_A, KC_L, KC_L,             0x2200)  // all   -> ∀
  UL3(KC_E, KC_X, KC_I,             0x2203)  // exi   -> ∃
  UL2(KC_N, KC_N,                   0x2115)  // nn    -> ℕ
  UL2(KC_Z, KC_Z,                   0x2124)  // zz    -> ℤ
  UL2(KC_Q, KC_Q,                   0x211A)  // qq    -> ℚ
  UL2(KC_R, KC_R,                   0x211D)  // rr    -> ℝ
  UL2(KC_C, KC_C,                   0x2102)  // cc    -> ℂ

  // Emoji
  UL4(KC_N, KC_E, KC_R, KC_D,       0x1F913) // nerd  -> 🤓
  UL3(KC_C, KC_R, KC_Y,             0x1F622) // cry   -> 😢
  UL3(KC_S, KC_O, KC_B,             0x1F62D) // sob   -> 😭
  UL3(KC_E, KC_Y, KC_B,             0x1F928) // eyb   -> 🤨
  UL5(KC_S, KC_K, KC_U, KC_L, KC_L, 0x1F480) // skull -> 💀
  UL5(KC_B, KC_R, KC_A, KC_I, KC_N, 0x1F9E0) // brain -> 🧠
  UL1(KC_EQUAL,                     0x1F44D) // =     -> 👍
  UL1(KC_MINUS,                     0x1F44E) // -     -> 👎
  UL4(KC_T, KC_A, KC_D, KC_A,       0x1F389) // tada  -> 🎉
  UL4(KC_P, KC_R, KC_A, KC_Y,       0x1F64F) // pray  -> 🙏
  UL4(KC_G, KC_R, KC_I, KC_M,       0x1F62C) // grim  -> 😬
  UL4(KC_R, KC_O, KC_F, KC_L,       0x1F923) // rofl  -> 🤣
  UL4(KC_C, KC_O, KC_O, KC_L,       0x1F60E) // cool  -> 😎
  UL3(KC_U, KC_G, KC_H,             0x1F922) // ugh   -> 🤢
  UL4(KC_E, KC_Y, KC_E, KC_S,       0x1F440) // eyes  -> 👀
  UL4(KC_R, KC_A, KC_G, KC_E,       0x1F621) // rage  -> 😡
  UL5(KC_S, KC_H, KC_O, KC_C, KC_K, 0x1FAE8) // shock -> 🫨
  UL5(KC_S, KC_A, KC_L, KC_U, KC_T, 0x1FAE1) // salut -> 🫡
  UL5(KC_A, KC_G, KC_R, KC_E, KC_E, 0x1F91D) // agree -> 🤝
  UL2(KC_O, KC_K,                   0x1F44C) // ok    -> 👌
  UL2(KC_N, KC_O,                   0x1F6AB) // no    -> 🚫
  UL5(KC_T, KC_H, KC_I, KC_N, KC_K, 0x1F914) // think -> 🤔
  UL4(KC_T, KC_I, KC_C, KC_K,       0x2705)  // tick  -> ✅
  UL1(KC_F,                         0x1F1EB) // f     -> 🇫
  UL1(KC_W,                         0x1F1FC) // w     -> 🇼
  UL1(KC_L,                         0x1F1F1) // l     -> 🇱
  UL2(KC_T, KC_M,                   0x2122)  // tm    -> ™
  {}
}