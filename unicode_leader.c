#include QMK_KEYBOARD_H

#include "leader.h"

extern uint16_t leader_sequence[];

#define SEQ1(a)         ((uint64_t)(uint8_t)(a))
#define SEQ2(a,b)       (SEQ1(a)       | ((uint64_t)(uint8_t)(b) <<  8))
#define SEQ3(a,b,c)     (SEQ2(a,b)     | ((uint64_t)(uint8_t)(c) << 16))
#define SEQ4(a,b,c,d)   (SEQ3(a,b,c)   | ((uint64_t)(uint8_t)(d) << 24))
#define SEQ5(a,b,c,d,e) (SEQ4(a,b,c,d) | ((uint64_t)(uint8_t)(e) << 32))

static inline uint64_t pack_leader_sequence(void) {
  return ((uint64_t)(leader_sequence[0] & 0xFF))
    | ((uint64_t)(leader_sequence[1] & 0xFF) <<  8)
    | ((uint64_t)(leader_sequence[2] & 0xFF) << 16)
    | ((uint64_t)(leader_sequence[3] & 0xFF) << 24)
    | ((uint64_t)(leader_sequence[4] & 0xFF) << 32);
}

void unicode_leader_on_leader_end(void) {
    switch (pack_leader_sequence()) {
      // Greek
      case SEQ3(         KC_A, KC_L, KC_P):    register_unicode(0x03B1);  break; // alp   -> α
      case SEQ3(         KC_B, KC_E, KC_T):    register_unicode(0x03B2);  break; // bet   -> β
      case SEQ3(         KC_G, KC_A, KC_M):    register_unicode(0x03B3);  break; // gam   -> γ
      case SEQ4(KC_LSFT, KC_G, KC_A, KC_M):    register_unicode(0x0393);  break; // Gam   -> Γ
      case SEQ3(         KC_D, KC_E, KC_L):    register_unicode(0x03B4);  break; // del   -> δ
      case SEQ4(KC_LSFT, KC_D, KC_E, KC_L):    register_unicode(0x0394);  break; // Del   -> Δ
      case SEQ3(         KC_E, KC_P, KC_S):    register_unicode(0x03B5);  break; // eps   -> ε
      case SEQ3(         KC_Z, KC_E, KC_T):    register_unicode(0x03B6);  break; // Zet   -> ζ
      case SEQ3(         KC_T, KC_H, KC_E):    register_unicode(0x03B8);  break; // the   -> θ
      case SEQ4(KC_LSFT, KC_T, KC_H, KC_E):    register_unicode(0x0398);  break; // The   -> Θ
      case SEQ3(         KC_L, KC_A, KC_M):    register_unicode(0x03BB);  break; // lam   -> λ
      case SEQ4(KC_LSFT, KC_L, KC_A, KC_M):    register_unicode(0x039B);  break; // Lam   -> Λ
      case SEQ2(         KC_M, KC_U):          register_unicode(0x03BC);  break; // mu    -> µ
      case SEQ2(         KC_X, KC_I):          register_unicode(0x03BE);  break; // xi    -> ξ
      case SEQ3(KC_LSFT, KC_X, KC_I):          register_unicode(0x039E);  break; // Xi    -> Ξ
      case SEQ2(         KC_P, KC_I):          register_unicode(0x03C0);  break; // pi    -> π
      case SEQ3(KC_LSFT, KC_P, KC_I):          register_unicode(0x03A0);  break; // Pi    -> Π
      case SEQ3(         KC_S, KC_I, KC_G):    register_unicode(0x03C3);  break; // sig   -> σ
      case SEQ4(KC_LSFT, KC_S, KC_I, KC_G):    register_unicode(0x03A3);  break; // Sig   -> Σ
      case SEQ3(         KC_P, KC_H, KC_I):    register_unicode(0x03C6);  break; // phi   -> φ
      case SEQ4(KC_LSFT, KC_P, KC_H, KC_I):    register_unicode(0x03A6);  break; // Phi   -> Φ
      case SEQ3(         KC_P, KC_S, KC_I):    register_unicode(0x03C8);  break; // psi   -> ψ
      case SEQ4(KC_LSFT, KC_P, KC_S, KC_I):    register_unicode(0x03A8);  break; // Psi   -> Ψ
      case SEQ2(         KC_O, KC_M):          register_unicode(0x03C9);  break; // om    -> ω
      case SEQ3(KC_LSFT, KC_O, KC_M):          register_unicode(0x03A9);  break; // Om    -> Ω
      case SEQ3(         KC_R, KC_H, KC_O):    register_unicode(0x03C1);  break; // rho   -> ρ

      // Math
      case SEQ3(KC_D, KC_E, KC_G):             register_unicode(0x00B0);  break; // deg   -> °
      case SEQ4(KC_T, KC_I, KC_M, KC_E):       register_unicode(0x00D7);  break; // time  -> ×
      case SEQ3(KC_D, KC_I, KC_V):             register_unicode(0x00F7);  break; // div   -> ÷
      case SEQ3(KC_G, KC_T, KC_E):             register_unicode(0x2265);  break; // gte   -> ≥
      case SEQ3(KC_L, KC_T, KC_E):             register_unicode(0x2264);  break; // lte   -> ≤
      case SEQ3(KC_A, KC_P, KC_R):             register_unicode(0x2248);  break; // apr   -> ≈
      case SEQ3(KC_N, KC_E, KC_Q):             register_unicode(0x2260);  break; // neq   -> ≠
      case SEQ3(KC_S, KC_Q, KC_R):             register_unicode(0x221A);  break; // sqr   -> √
      case SEQ2(KC_P, KC_M):                   register_unicode(0x00B1);  break; // pm    -> ±
      case SEQ2(KC_M, KC_P):                   register_unicode(0x2213);  break; // mp    -> ∓
      case SEQ3(KC_D, KC_O, KC_T):             register_unicode(0x22C5);  break; // dot   -> ⋅
      case SEQ3(KC_I, KC_N, KC_T):             register_unicode(0x222B);  break; // int   -> ∫
      case SEQ3(KC_I, KC_N, KC_F):             register_unicode(0x221E);  break; // inf   -> ∞
      case SEQ3(KC_P, KC_R, KC_O):             register_unicode(0x221D);  break; // pro   -> ∝
      case SEQ4(KC_L, KC_E, KC_F, KC_T):       register_unicode(0x2190);  break; // left  -> ←
      case SEQ5(KC_R, KC_I, KC_G, KC_H, KC_T): register_unicode(0x2192);  break; // right -> →

      // Set Theory
      case SEQ2(KC_I, KC_N):                   register_unicode(0x2208);  break; // in    -> ∈
      case SEQ3(KC_N, KC_I, KC_N):             register_unicode(0x2209);  break; // nin   -> ∉
      case SEQ3(KC_S, KC_U, KC_B):             register_unicode(0x2282);  break; // sub   -> ⊂
      case SEQ3(KC_S, KC_U, KC_P):             register_unicode(0x2283);  break; // sup   -> ⊃
      case SEQ5(KC_U, KC_N, KC_I, KC_O, KC_N): register_unicode(0x222A);  break; // union -> ∪
      case SEQ5(KC_I, KC_N, KC_T, KC_E, KC_R): register_unicode(0x2229);  break; // inter -> ∩
      case SEQ3(KC_X, KC_O, KC_R):             register_unicode(0x2295);  break; // xor   -> ⊕
      case SEQ3(KC_A, KC_L, KC_L):             register_unicode(0x2200);  break; // all   -> ∀
      case SEQ3(KC_E, KC_X, KC_I):             register_unicode(0x2203);  break; // exi   -> ∃
      case SEQ2(KC_N, KC_N):                   register_unicode(0x2115);  break; // nn    -> ℕ
      case SEQ2(KC_Z, KC_Z):                   register_unicode(0x2124);  break; // zz    -> ℤ
      case SEQ2(KC_Q, KC_Q):                   register_unicode(0x211A);  break; // qq    -> ℚ
      case SEQ2(KC_R, KC_R):                   register_unicode(0x211D);  break; // rr    -> ℝ
      case SEQ2(KC_C, KC_C):                   register_unicode(0x2102);  break; // cc    -> ℂ

      // Emoji
      case SEQ4(KC_N, KC_E, KC_R, KC_D):       register_unicode(0x1F913); break; // nerd  -> 🤓
      case SEQ3(KC_C, KC_R, KC_Y):             register_unicode(0x1F622); break; // cry   -> 😢
      case SEQ3(KC_S, KC_O, KC_B):             register_unicode(0x1F62D); break; // sob   -> 😭
      case SEQ3(KC_E, KC_Y, KC_B):             register_unicode(0x1F928); break; // eyb   -> 🤨
      case SEQ5(KC_S, KC_K, KC_U, KC_L, KC_L): register_unicode(0x1F480); break; // skull -> 💀
      case SEQ5(KC_B, KC_R, KC_A, KC_I, KC_N): register_unicode(0x1F9E0); break; // brain -> 🧠
      case SEQ1(KC_EQUAL):                     register_unicode(0x1F44D); break; // =     -> 👍
      case SEQ1(KC_MINUS):                     register_unicode(0x1F44E); break; // -     -> 👎
      case SEQ4(KC_T, KC_A, KC_D, KC_A):       register_unicode(0x1F389); break; // tada  -> 🎉
      case SEQ4(KC_P, KC_R, KC_A, KC_Y):       register_unicode(0x1F64F); break; // pray  -> 🙏
      case SEQ4(KC_G, KC_R, KC_I, KC_M):       register_unicode(0x1F62C); break; // grim  -> 😬
      case SEQ4(KC_R, KC_O, KC_F, KC_L):       register_unicode(0x1F923); break; // rofl  -> 🤣
      case SEQ4(KC_C, KC_O, KC_O, KC_L):       register_unicode(0x1F60E); break; // cool  -> 😎
      case SEQ3(KC_U, KC_G, KC_H):             register_unicode(0x1F922); break; // ugh   -> 🤢
      case SEQ4(KC_E, KC_Y, KC_E, KC_S):       register_unicode(0x1F440); break; // eyes  -> 👀
      case SEQ4(KC_R, KC_A, KC_G, KC_E):       register_unicode(0x1F621); break; // rage  -> 😡
      case SEQ5(KC_S, KC_H, KC_O, KC_C, KC_K): register_unicode(0x1FAE8); break; // shock -> 🫨
      case SEQ5(KC_S, KC_A, KC_L, KC_U, KC_T): register_unicode(0x1FAE1); break; // salut -> 🫡
      case SEQ5(KC_A, KC_G, KC_R, KC_E, KC_E): register_unicode(0x1F91D); break; // agree -> 🤝
      case SEQ2(KC_O, KC_K):                   register_unicode(0x1F44C); break; // ok    -> 👌
      case SEQ2(KC_N, KC_O):                   register_unicode(0x1F6AB); break; // no    -> 🚫
      case SEQ5(KC_T, KC_H, KC_I, KC_N, KC_K): register_unicode(0x1F914); break; // think -> 🤔
      case SEQ4(KC_T, KC_I, KC_C, KC_K):       register_unicode(0x2705);  break; // tick  -> ✅
      case SEQ1(KC_F):                         register_unicode(0x1F1EB); break; // f     -> 🇫
      case SEQ1(KC_W):                         register_unicode(0x1F1FC); break; // w     -> 🇼
      case SEQ1(KC_L):                         register_unicode(0x1F1F1); break; // l     -> 🇱
      case SEQ2(KC_T, KC_M):                   register_unicode(0x2122);  break; // tm    -> ™

    }
}
