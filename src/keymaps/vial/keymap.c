#include "macro.h"

#define LAYER0_SONG H__NOTE(_C4),
#define LAYER1_SONG H__NOTE(_C4), H__NOTE(_E4),
#define LAYER2_SONG H__NOTE(_C4), H__NOTE(_E4), H__NOTE(_G4),
#define LAYER3_SONG H__NOTE(_C4), H__NOTE(_E4), H__NOTE(_G4), H__NOTE(_C5),

float layer0_song[][2] = SONG(LAYER0_SONG);
float layer1_song[][2] = SONG(LAYER1_SONG);
float layer2_song[][2] = SONG(LAYER2_SONG);
float layer3_song[][2] = SONG(LAYER3_SONG);


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = KEYMAP(KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1),
	[1] = KEYMAP(KC_2, KC_2, KC_2, KC_2, KC_2, KC_2, KC_2, KC_2),
	[2] = KEYMAP(KC_2, KC_2, KC_2, KC_2, KC_2, KC_2, KC_2, KC_2),
	[3] = KEYMAP(KC_4, KC_4, KC_4, KC_4, KC_4, KC_4, KC_4, KC_4),
};

layer_state_t layer_state_set_user(layer_state_t state) {
	if (layer_state_cmp(state, 0)) PLAY_SONG(layer0_song);
	else if(layer_state_cmp(state, 1)) PLAY_SONG(layer1_song);
	else if(layer_state_cmp(state, 2)) PLAY_SONG(layer2_song);
	else if(layer_state_cmp(state, 3)) PLAY_SONG(layer3_song);
	else stop_all_notes();

	return state;
}