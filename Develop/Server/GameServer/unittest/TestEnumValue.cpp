#include "stdafx.h"
#include "CSChrInfo.h"
#include "CSQuestInfo.h"

SUITE(EnumValue)
{
	TEST(ThisEnumValuesCannotBeChangedBecauseOfDB)
	{
		CHECK_EQUAL(SEX_MALE,	0);
		CHECK_EQUAL(SEX_FEMALE, 1);

		CHECK_EQUAL(WEAPON_1H_SLASH,		1);
		CHECK_EQUAL(WEAPON_1H_BLUNT,		2);
		CHECK_EQUAL(WEAPON_1H_PIERCE,		3);
		CHECK_EQUAL(WEAPON_TWO_HANDED,		4);
		CHECK_EQUAL(WEAPON_STAFF,			5);
		CHECK_EQUAL(WEAPON_ARCHERY,			6);
		CHECK_EQUAL(WEAPON_2H_BLUNT,		7);

		CHECK_EQUAL(QOT_DESTROY,	1);
		CHECK_EQUAL(QOT_COLLECT,	2);
		CHECK_EQUAL(QOT_ACT,		3);
	}

}

