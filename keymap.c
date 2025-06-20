#include QMK_KEYBOARD_H

#if __has_include("keymap.h")
#    include "keymap.h"
#endif

#ifdef OTHER_KEYMAP_C
#    include OTHER_KEYMAP_C
#endif // OTHER_KEYMAP_C

enum custom_keycodes {
    PY_FOR = SAFE_RANGE,
    PY_PAR,
    PY_BRK,
    PY_CRL,
    PY_CMT,
    PY_DEF,
    PY_PRT,
    PY_IMP,
    PY_OPN,
    PY_TRY,
    L_ARR,
    R_ARR,
    U_ARR,
    D_ARR,
    M_DIV,
    M_DEG
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case PY_PAR:
                SEND_STRING("()" SS_TAP(X_LEFT));
                return false;
            case PY_BRK:
                SEND_STRING("[]" SS_TAP(X_LEFT));
                return false;
            case PY_CRL:
                SEND_STRING("{}" SS_TAP(X_LEFT));
                return false;
            case PY_CMT:
                SEND_STRING("###\n\n###\n" SS_TAP(X_UP) SS_TAP(X_UP));
                return false;
            case PY_DEF:
                SEND_STRING("def ():" SS_TAP(X_LEFT) SS_TAP(X_LEFT));
                return false;
            case PY_PRT:
                SEND_STRING("print(f'')" SS_TAP(X_LEFT) SS_TAP(X_LEFT));
                return false;
            case PY_FOR:
                SEND_STRING("for i in range():" SS_TAP(X_LEFT) SS_TAP(X_LEFT));
                return false;
            case PY_IMP:
                SEND_STRING("import pandas as pd\nimport numpy as np\n");
                return false;
            case PY_OPN:
                SEND_STRING("with open(\"\") as f:\n    data = f.read()" SS_TAP(X_UP) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT));
                return false;
            case PY_TRY:
                SEND_STRING("try:\n    \nexcept Exception as e:\n    print(e)" SS_TAP(X_UP) SS_TAP(X_UP));
                return false;
            case L_ARR:
                SEND_STRING("←");
                return false;
            case R_ARR:
                SEND_STRING("→");
                return false;
            case U_ARR:
                SEND_STRING("↑");
                return false;
            case D_ARR:
                SEND_STRING("↓");
                return false;
            case M_DIV:
                SEND_STRING("÷");
                return false;
            case M_DEG:
                SEND_STRING("°");
                return false;
        }
    }return true;
};

enum {
    TD_Q_TAB,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_Q_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_TAB),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {[0] = LAYOUT_split_3x5_2(TD(TD_Q_TAB),KC_W,KC_E,KC_R,KC_T,KC_Y,KC_U,KC_I,KC_O,KC_P,KC_A,LALT_T(KC_S),LCTL_T(KC_D),LSFT_T(KC_F),KC_G,KC_H,RSFT_T(KC_J),RCTL_T(KC_K),LALT_T(KC_L),KC_SCLN,LGUI_T(KC_Z),KC_X,KC_C,KC_V,KC_B,KC_N,KC_M,KC_COMM,KC_DOT,RGUI_T(KC_SLSH),LT(1,KC_ESC),LT(2,KC_SPC),LT(3,KC_BSPC),LT(4,KC_ENT)),
                                                              [1] = LAYOUT_split_3x5_2(KC_GRV,KC_TILD,KC_EXLM,KC_AT,KC_HASH,KC_DLR,KC_PERC,KC_CIRC,KC_AMPR,KC_ASTR,KC_UNDS,KC_LCBR,KC_LBRC,KC_LPRN,U_ARR,R_ARR,KC_RPRN,KC_RBRC,KC_LCBR,KC_DQUO,M_DIV,KC_PEQL,KC_PMNS,KC_PLUS,L_ARR,D_ARR,KC_BSLS,KC_PIPE,KC_QUOT,M_DEG,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS),
                                                              [2] = LAYOUT_split_3x5_2(KC_F1,KC_F2,KC_F3,KC_F4,KC_SLEP,KC_PEQL,KC_7,KC_8,KC_9,KC_ASTR,KC_F5,LALT_T(KC_F6),LCTL_T(KC_F7),LSFT_T(KC_F8),KC_WAKE,KC_DOT,RSFT_T(KC_4),RCTL_T(KC_5),LALT_T(KC_6),KC_PMNS,KC_BRID,KC_P1,KC_P2,KC_P3,KC_SLSH,KC_0,KC_1,KC_2,KC_3,KC_PLUS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS),
                                                              [3] = LAYOUT_split_3x5_2(KC_BRID,KC_BRIU,MS_BTN3,KC_HOME,KC_END,KC_PSCR,KC_WBAK,MS_BTN3,KC_WFWD,KC_VOLU,KC_LSFT,MS_WHLL,MS_WHLU,MS_WHLR,KC_UP,KC_RIGHT,MS_LEFT,MS_UP,MS_RGHT,KC_VOLD,KC_LCTL,MS_BTN1,MS_WHLD,MS_BTN2,KC_LEFT,KC_DOWN,MS_BTN1,MS_DOWN,MS_BTN2,KC_MUTE,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS),
                                                              [4] = LAYOUT_split_3x5_2(XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,PY_FOR,PY_CRL,PY_BRK,PY_PAR,PY_IMP,PY_OPN,PY_PRT,PY_CMT,PY_DEF,PY_TRY,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX)};

bool caps_word_press_user(uint16_t keycode) {switch (keycode) {
        // Keep Caps Word active for letters
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT)); // Apply Shift to make them uppercase
            return true;

        // Allow numbers and underscore
        case KC_1 ... KC_0:
        case KC_UNDS:
        case KC_BSPC:
        case KC_DEL:
            return true;

        // Otherwise, turn Caps Word off
        default:
            return false;}
};



const uint16_t PROGMEM llock_combo_left[] = {LT(1, KC_ESC), LT(2, KC_SPC), COMBO_END};
const uint16_t PROGMEM llock_combo_right[] = {LT(3, KC_BSPC), LT(4, KC_ENT), COMBO_END};
combo_t key_combos[] = {
    COMBO(llock_combo_left, QK_LLCK),
    COMBO(llock_combo_right, QK_LLCK),
};
