/* Copyright 2015-2021 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"

enum planck_layers { _QWERTY, _LOWER, _RAISE, _ADJUST, _FN, _KITTY };

enum planck_keycodes {
    QWERTY = SAFE_RANGE,
    BACKLIT,
    EXT_PLV,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define FN MO(_FN)
#define KITTY MO(_KITTY)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Qwerty
     * ,-----------------------------------------------------------------------------------.
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Ctrl | GUI  | Alt  |  FN  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
     * `-----------------------------------------------------------------------------------'
     */
    [_QWERTY] = LAYOUT_planck_grid(KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT, KC_LCTL, KC_LALT, KC_LALT, FN, LOWER, KC_SPC, KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT),

    /* Lower
     * ,-----------------------------------------------------------------------------------.
     * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   <  |   >  | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |  _   |  -   |  {   |   }  |   =  |   +  |   [  |   ]  |   (  |   )  |  `   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | KITTY|  |   |  \   |  :   |   ?  |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_LOWER] = LAYOUT_planck_grid(KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LT, KC_GT, KC_BSPC, _______, KC_UNDS, KC_MINS, KC_LCBR, KC_RCBR, KC_EQL, KC_PLUS, KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_GRV, KITTY, KC_PIPE, KC_BSLS, KC_COLN, KC_QUES, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

    /* Raise
     * ,-----------------------------------------------------------------------------------.
     * |   `  |  â   |  à   |   ê  |   é  |   è  |  €   |  ù   |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Del  |      |      |      |      |      | Left | Down |  Up  |Right |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT_planck_grid(KC_GRV, RALT(KC_Q), RALT(KC_A), RALT(KC_3), RALT(KC_W), RALT(KC_E), RALT(KC_5), RALT(KC_U), _______, _______, _______, _______, KC_DEL, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY),

    /* Adjust (Lower + Raise)
     * ,-----------------------------------------------------------------------------------.
     * | BOOT |GI+S+1|GI+S+2|GI+S+3|GI+S+4|GI+-  |GI+S+Q|GI+S+t|GI+S+b|      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |GUI+1 |GUI+2 |GUI+3 |GUI+4 |GUI+R |GUI+H |GUI+J |GUI+K |GUI+L |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |GUI+D |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */

    [_ADJUST] = LAYOUT_planck_grid(QK_BOOTLOADER, LSG(KC_1), LSG(KC_2), LSG(KC_3), LSG(KC_4), _______, LSG(KC_Q), LSG(KC_T), LSG(KC_B), _______, _______, _______, _______, LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), LGUI(KC_4), LGUI(KC_R), LGUI(KC_H), LGUI(KC_J), LGUI(KC_K), LGUI(KC_L), _______, _______, _______, _______, _______, _______, LGUI(KC_D), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

    /* FN
     * ,-----------------------------------------------------------------------------------.
     * | F1   | F2   | F3   | F4   | F5   | F6   |      |  7   |  8   |  9   |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | F7   | F8   | F9   | F10  | F11  | F12  |      |  4   |  5   |  6   |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |  0   |  1   |  2   |  3   |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_FN] = LAYOUT_planck_grid(KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, _______, KC_7, KC_8, KC_9, _______, _______, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, _______, KC_4, KC_5, KC_6, _______, _______, _______, _______, _______, _______, _______, _______, KC_0, KC_1, KC_2, KC_3, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

    /* KITTY
     * ,-----------------------------------------------------------------------------------.
     * |      |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |   A  |   S  |   D  |   F  |   G  |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_KITTY] = LAYOUT_planck_grid(_______, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, _______, _______, KC_A, KC_S, KC_D, KC_F, KC_G, LCTL(LSFT(KC_LEFT)), LCTL(LSFT(KC_T)), _______, LCTL(LSFT(KC_RGHT)), _______, _______, _______, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, LCTL(LSFT(KC_Q)), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

};

#ifdef AUDIO_ENABLE
float plover_song[][2]    = SONG(PLOVER_SOUND);
float plover_gb_song[][2] = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                print("mode just switched to qwerty and this is a huge string\n");
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case BACKLIT:
            if (record->event.pressed) {
                register_code(KC_RSFT);
#ifdef BACKLIGHT_ENABLE
                backlight_step();
#endif
#ifdef KEYBOARD_planck_rev5
                writePinLow(E6);
#endif
            } else {
                unregister_code(KC_RSFT);
#ifdef KEYBOARD_planck_rev5
                writePinHigh(E6);
#endif
            }
            return false;
            break;
        case EXT_PLV:
            if (record->event.pressed) {
#ifdef AUDIO_ENABLE
                PLAY_SONG(plover_gb_song);
#endif
            }
            return false;
            break;
    }
    return true;
}

bool     muse_mode      = false;
uint8_t  last_muse_note = 0;
uint16_t muse_counter   = 0;
uint8_t  muse_offset    = 70;
uint16_t muse_tempo     = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (muse_mode) {
        if (IS_LAYER_ON(_RAISE)) {
            if (clockwise) {
                muse_offset++;
            } else {
                muse_offset--;
            }
        } else {
            if (clockwise) {
                muse_tempo += 1;
            } else {
                muse_tempo -= 1;
            }
        }
    } else {
        if (clockwise) {
#ifdef MOUSEKEY_ENABLE
            tap_code(KC_MS_WH_DOWN);
#else
            tap_code(KC_PGDN);
#endif
        } else {
#ifdef MOUSEKEY_ENABLE
            tap_code(KC_MS_WH_UP);
#else
            tap_code(KC_PGUP);
#endif
        }
    }
    return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) {
                    PLAY_SONG(plover_song);
                }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) {
                    PLAY_SONG(plover_gb_song);
                }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
    return true;
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
        case RAISE:
        case LOWER:
            return false;
        default:
            return true;
    }
}
