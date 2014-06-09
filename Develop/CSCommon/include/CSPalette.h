#ifndef _CS_PALETTE_H_
#define _CS_PALETTE_H_

enum PALETTE_NUM : unsigned char
{
	PALETTENUM_1 = 0,
	PALETTENUM_2,
	PALETTENUM_3,
	PALETTENUM_4,
	PALETTENUM_5,

	PALETTENUM_MAX
};

enum PALETTE_SLOT : unsigned char
{
	PALETTESLOT_1 = 0,
	PALETTESLOT_2,
	PALETTESLOT_3,
	PALETTESLOT_4,
	PALETTESLOT_5,
	PALETTESLOT_6,
	PALETTESLOT_7,
	PALETTESLOT_8,
	PALETTESLOT_9,
	PALETTESLOT_0,

	PALETTESLOT_MAX
};

enum PALETTE_ITEM_TYPE : unsigned char
{
	PIT_NONE = 0,

	PIT_ITEM,
	PIT_TALENT,

	PIT_MAX
};

#endif