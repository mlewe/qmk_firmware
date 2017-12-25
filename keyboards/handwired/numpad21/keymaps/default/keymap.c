#include "numpad21.h"

#define  TRNS
#define KC_FN LT(1, KC_P0)
#define KC_MU_TOG MU_TOG

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[0] = COMPACT_KEYMAP(
		NLCK, PSLS, PAST, PMNS,
		P7, P8, P9, PPLS,
		P4, P5, P6, BSPC,
		P1, P2, P3, PENT,
		FN, P0, PDOT, SPC),

	[1] = COMPACT_KEYMAP(
		TRNS, TRNS, TRNS, TRNS,
		TRNS, TRNS, TRNS, TRNS,
		D, E, F, TRNS,
		A, B, C, TRNS,
		TRNS, TRNS, COLN, MU_TOG),
};


const uint16_t PROGMEM fn_actions[] = {
};
