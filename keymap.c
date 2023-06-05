#include QMK_KEYBOARD_H
#include <string.h>

/* enter/spc ctrl */
#define ENT_CTL LCTL_T(KC_ENT)
#define SPC_CTL RCTL_T(KC_SPC)

/* home row mods */
#define A_GUI LGUI_T(KC_A)
#define R_ALT LALT_T(KC_R)
#define S_CTL LCTL_T(KC_S)

#define O_GUI LGUI_T(KC_O)
#define I_ALT LALT_T(KC_I)
#define E_CTL LCTL_T(KC_E)

/* corner shifts */
#define Z_SFT LSFT_T(KC_Z)
#define EQL_SFT LSFT_T(KC_EQL)
#define BS_SFT RSFT_T(KC_BSLS)
#define SL_SFT RSFT_T(KC_SLSH)

/* layer taps */
#define L1_BSPC LT(1, KC_BSPC)
#define L3_TAB LT(3, KC_TAB)
#define L4_ESC LT(4, KC_ESC)

enum combo_events {
  JL_EQL,
  LU_MINS,
  UY_SCLN,
  YQ_GRV,
  EM_EMAIL,
  HK_MB1,
  JH_MB2,
  H_BTN1,
  H_BTN2,
  H_BTN3,
  CM_COPY,
  CM_PASTE,
  CM_CUT,
  CM_ALL,
  COMBO_LENGTH,
  CM_F11,
  CM_F12,
  TH_DEL,
  TH_ESC
};

uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM jl_eql[] = {KC_J, KC_L, COMBO_END};
const uint16_t PROGMEM lu_mins[] = {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM uy_scln[] = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM yq_grv[] = {KC_Y, KC_QUOT, COMBO_END};

const uint16_t PROGMEM hk_mb1[] = {KC_H, KC_K, COMBO_END};
const uint16_t PROGMEM jh_mb2[] = {KC_H, KC_J, COMBO_END};

const uint16_t PROGMEM h_btn1[] = {KC_H, KC_N, COMBO_END};
const uint16_t PROGMEM h_btn2[] = {KC_N, E_CTL, COMBO_END};
const uint16_t PROGMEM h_btn3[] = {KC_H, KC_N, E_CTL, COMBO_END};

const uint16_t PROGMEM cm_copy[] = {ENT_CTL, KC_C, COMBO_END};
const uint16_t PROGMEM cm_paste[] = {ENT_CTL, KC_V, COMBO_END};
const uint16_t PROGMEM cm_cut[] = {ENT_CTL, KC_X, COMBO_END};
const uint16_t PROGMEM cm_all[] = {ENT_CTL, A_GUI, COMBO_END};

const uint16_t PROGMEM cm_f11[] = {KC_F1, KC_F10, COMBO_END};
const uint16_t PROGMEM cm_f12[] = {KC_F2, KC_F10, COMBO_END};

const uint16_t PROGMEM th_del[] = {L1_BSPC, ENT_CTL, COMBO_END};
const uint16_t PROGMEM th_esc[] = {SPC_CTL, L3_TAB, COMBO_END};

combo_t key_combos[] = {
  [JL_EQL] = COMBO(jl_eql, KC_EQL),
  [LU_MINS] = COMBO(lu_mins, KC_MINS),
  [UY_SCLN] = COMBO(uy_scln, KC_SCLN),
  [YQ_GRV] = COMBO(yq_grv, KC_GRV),
  [HK_MB1] = COMBO(hk_mb1, KC_BTN1),
  [JH_MB2] = COMBO(jh_mb2, KC_BTN2),
  [H_BTN1] = COMBO(h_btn1, KC_BTN1),
  [H_BTN2] = COMBO(h_btn2, KC_BTN2),
  [H_BTN3] = COMBO(h_btn3, KC_BTN3),
  [CM_COPY] = COMBO(cm_copy, LCTL(KC_C)),
  [CM_PASTE] = COMBO(cm_paste, LCTL(KC_V)),
  [CM_CUT] = COMBO(cm_cut, LCTL(KC_X)),
  [CM_ALL] = COMBO(cm_all, LCTL(KC_A)),
  [CM_F11] = COMBO(cm_f11, KC_F11),
  [CM_F12] = COMBO(cm_f12, KC_F12),
  [TH_DEL] = COMBO(th_del, KC_DEL),
  [TH_ESC] = COMBO(th_esc, L4_ESC),
};

// enum ferris_layers {
//   _MAIN,
//   _LOWER,
//   _RAISE
// };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
  //,--------------------------------------------.                    ,--------------------------------------------.
      KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                         KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      A_GUI,   R_ALT,   S_CTL,   KC_T,    KC_D,                         KC_H,    KC_N,    E_CTL,   I_ALT,   O_GUI,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      Z_SFT,   KC_X,    KC_C,    KC_V,    KC_B,                         KC_K,    KC_M,    KC_COMM, KC_DOT,  SL_SFT,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                          L1_BSPC, ENT_CTL,    SPC_CTL, L3_TAB
                                      //`-----------------'  `-----------------'
    ),

  [1] = LAYOUT(
  //,--------------------------------------------.                    ,--------------------------------------------.
      _______, _______, _______, _______, _______,                       KC_DLR, KC_HOME, KC_PGUP, KC_PGDN,  KC_END,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_LGUI, KC_LALT, KC_LCTL, _______, _______,                      KC_SCLN, KC_LEFT,   KC_UP, KC_DOWN, KC_RGHT,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      EQL_SFT, _______, _______, _______, _______,                      KC_MINS, KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                          _______, _______,    _______, _______
                                      //`-----------------'  `-----------------'
    ),

  [2] = LAYOUT(
  //,--------------------------------------------.                    ,--------------------------------------------.
      _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                          _______, _______,    _______, _______
                                      //`-----------------'  `-----------------'
    ),

  [3] = LAYOUT(
  //,--------------------------------------------.                    ,--------------------------------------------.
       KC_DLR,    KC_7,    KC_8,    KC_9, KC_LBRC,                       KC_DLR,  KC_EQL, KC_MINS, KC_SCLN,  KC_GRV,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_PIPE,    KC_4,    KC_5,    KC_6, KC_LPRN,                      KC_SCLN, _______, KC_LCTL, KC_LALT, KC_LGUI,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      EQL_SFT,    KC_1,    KC_2,    KC_3, KC_LCBR,                      KC_MINS, _______, KC_WH_U, KC_WH_D,  BS_SFT,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                             KC_0, _______,    _______, _______
                                      //`-----------------'  `-----------------'
    ),

  [4] = LAYOUT(
  //,--------------------------------------------.                    ,--------------------------------------------.
      _______,   KC_F7,   KC_F8,   KC_F9, _______,                      _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      _______,   KC_F4,   KC_F5,   KC_F6, _______,                      _______, _______, KC_LCTL, KC_LALT, KC_LGUI,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      _______,   KC_F1,   KC_F2,   KC_F3, _______,                      _______, _______, _______, _______, KC_LSFT,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                           KC_F10, _______,    _______, _______
                                      //`-----------------'  `-----------------'
    ),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case SPC_CTL:
  case A_GUI:
    return TAPPING_TERM + 30;
  case O_GUI:
    return TAPPING_TERM + 20;
  case EQL_SFT:
  case SL_SFT:
  case BS_SFT:
  case L1_BSPC:
    return TAPPING_TERM - 30;
  case L3_TAB:
    return TAPPING_TERM - 65;
  case Z_SFT:
    return TAPPING_TERM - 75;
  default:
    return TAPPING_TERM;
  }
}

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
  switch (index) {
  case UY_SCLN:
  case LU_MINS:
  case H_BTN3:
    return COMBO_TERM - 20;
  case H_BTN2:
    return COMBO_TERM - 35;
  case H_BTN1:
    return COMBO_TERM - 40;
  }
  return COMBO_TERM;
}

// shift key overrides
const key_override_t delete_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_BSPC, KC_DEL, 1<<0);
const key_override_t lbrc_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_LBRC, KC_RBRC);
const key_override_t lprn_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_LPRN, KC_RPRN);
const key_override_t lcbr_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_LCBR, KC_RCBR);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &delete_key_override,
    &lbrc_key_override,
    &lprn_key_override,
    &lcbr_key_override,
    NULL // Null terminate the array of overrides!
};
