#include "stdafx.h"
#include "DBTestGlobal.h"
#include "GConfig.h"


SUITE(RZ_MAIL_GET_ITEM)
{
	class TEST_MAIL_ITEM
	{
	public :
		TEST_MAIL_ITEM() {}

		TEST_MAIL_ITEM(const int64 MAIL_UID, const int SLOT_ID, const int64 IUID, const int ITEM_ID)
		{
			m_MAIL_UID		= MAIL_UID;
			m_SLOT_ID		= SLOT_ID;
			m_IUID			= IUID;
			m_ITEM_ID		= ITEM_ID;
			m_STACK_AMT		= (int16)SLOT_ID;
			m_DURA			= (uint8)SLOT_ID + 1;
			m_MAX_DURA		= (uint8)SLOT_ID + 2;
			m_PERIOD		= (1 == SLOT_ID % 2);
			m_USAGE_PERIOD	= SLOT_ID + 10000;
			m_ADD_EXPI_DAY	= SLOT_ID + 5;
			m_ENCH_ITEM_ID_1 = SLOT_ID + 6;
			m_ENCH_ITEM_ID_2 = SLOT_ID + 7;
			m_ENCH_ITEM_ID_3 = SLOT_ID + 8;
			m_ENCH_ITEM_ID_4 = SLOT_ID + 9;
			m_ENCH_ITEM_ID_5 = SLOT_ID + 10;
			m_ENCH_ITEM_ID_6 = SLOT_ID + 11;

			DBTestHelper::InsertMailItem(GConfig::m_nMyWorldID, m_MAIL_UID, m_SLOT_ID, m_IUID, m_ITEM_ID, m_STACK_AMT, m_DURA, m_MAX_DURA
				, m_ENCH_ITEM_ID_1, m_ENCH_ITEM_ID_2, m_ENCH_ITEM_ID_3, m_ENCH_ITEM_ID_4, m_ENCH_ITEM_ID_5, m_ENCH_ITEM_ID_6, 1);
		}

	public :
		int64	m_MAIL_UID;
		int		m_SLOT_ID;
		int64	m_IUID;
		int		m_ITEM_ID;
		int16	m_STACK_AMT;
		uint8	m_DURA;
		uint8	m_MAX_DURA;
		bool	m_PERIOD;
		int		m_USAGE_PERIOD;
		int		m_ADD_EXPI_DAY;
		int		m_ENCH_ITEM_ID_1;
		int		m_ENCH_ITEM_ID_2;
		int		m_ENCH_ITEM_ID_3;
		int		m_ENCH_ITEM_ID_4;
		int		m_ENCH_ITEM_ID_5;
		int		m_ENCH_ITEM_ID_6;
	};

	class FIXTURE
	{
	public :
		FIXTURE()
		{
			m_GSN		= 1;
			m_CSN		= DBTestHelper::InsertCharacter(m_GSN, GConfig::m_nMyWorldID);
			m_MAIL_UID	= DBTestHelper::InsertMail(GConfig::m_nMyWorldID, m_GSN, m_CSN);
			m_CHAR_PTM	= 10;

			m_ITEM_ID_1 = 100;
			m_ITEM_ID_2 = 200;
			m_ITEM_ID_3 = 300;
			m_ITEM_ID_4 = 400;
			m_ITEM_ID_5 = 500;

			m_MAIL_ITEM_1 = TEST_MAIL_ITEM(m_MAIL_UID, 0, 11, m_ITEM_ID_1);
			m_MAIL_ITEM_2 = TEST_MAIL_ITEM(m_MAIL_UID, 1, 12, m_ITEM_ID_2);
			m_MAIL_ITEM_3 = TEST_MAIL_ITEM(m_MAIL_UID, 2, 13, m_ITEM_ID_3);
			m_MAIL_ITEM_4 = TEST_MAIL_ITEM(m_MAIL_UID, 3, 14, m_ITEM_ID_4);
			m_MAIL_ITEM_5 = TEST_MAIL_ITEM(m_MAIL_UID, 4, 15, m_ITEM_ID_5);			
		}

		void InsertEmptySlot()
		{
			DBTestHelper::InsertEmptyItemSlot(m_GSN, m_CSN, GConfig::m_nMyWorldID, 1, 0);
			DBTestHelper::InsertEmptyItemSlot(m_GSN, m_CSN, GConfig::m_nMyWorldID, 1, 1);
			DBTestHelper::InsertEmptyItemSlot(m_GSN, m_CSN, GConfig::m_nMyWorldID, 1, 2);
			DBTestHelper::InsertEmptyItemSlot(m_GSN, m_CSN, GConfig::m_nMyWorldID, 1, 3);
			DBTestHelper::InsertEmptyItemSlot(m_GSN, m_CSN, GConfig::m_nMyWorldID, 1, 4);
		}

		void CHECK_MAIL_GET_ITEM(const int MAIL_ITEM_SLOT_ID, const int INVEN_SLOT_ID, TEST_MAIL_ITEM& MAIL_ITEM, const int NEW_DEF_ITEM_ID)
		{
			UTestDB.Execute(L"{CALL dbo.USP_RZ_MAIL_GET_ITEM (%d, %I64d, %I64d, %I64d, %d, %I64d, %d, %d, %d)}"
				, GConfig::m_nMyWorldID, m_GSN, m_CSN, m_MAIL_UID, MAIL_ITEM_SLOT_ID, MAIL_ITEM.m_IUID, INVEN_SLOT_ID, NEW_DEF_ITEM_ID, m_CHAR_PTM);			
		}

		void CHECK_MAIL_DELTED_ITEM(const int MAIL_ITEM_SLOT_ID)
		{
			TDBRecordSet rs;
			UTestDB.Execute(rs, L"SELECT * FROM dbo.RZ_MAIL_ITEM WHERE MAIL_ID = %I64d AND SLOT_ID = %Id;", m_MAIL_UID, MAIL_ITEM_SLOT_ID);
			CHECK_EQUAL(0, rs.GetFetchedRowCount());
			rs.Close();
		}

		void CHECK_MAIL_DEF_ITEM_ID(const int DEF_ITEM_ID)
		{
			TDBRecordSet rs;
			UTestDB.Execute(rs, L"SELECT DEF_ITEM_ID FROM dbo.RZ_MAIL WHERE ACCN_ID = %I64d AND CHAR_ID = %I64d AND MAIL_ID = %I64d;"
				, m_GSN, m_CSN, m_MAIL_UID);
			CHECK_EQUAL(DEF_ITEM_ID, rs.Field(L"DEF_ITEM_ID").AsInt());
			rs.Close();
		}

		void CHECK_INVEN_ITEM(const int INVEN_SLOT_ID, const TEST_MAIL_ITEM& MAIL_ITEM)
		{
			TDBRecordSet rs;
			UTestDB.Execute(rs, L"SELECT ITEM_ID, STACK_AMT, SOUL_COUNT, DURA, MAX_DURA, COLOR, CLAIMED, CHAR_PTM, PERIOD, USAGE_PERIOD \
								 , EFF_START_DATE, EFF_END_DATE, ENCH_ITEM_ID_1, ENCH_ITEM_ID_2, ENCH_ITEM_ID_3, ENCH_ITEM_ID_4, ENCH_ITEM_ID_5, ENCH_ITEM_ID_6 \
								 FROM dbo.RZ_INVEN IV LEFT OUTER JOIN dbo.RZ_ITEM_ENCHANT IE ON IV.IUID = IE.IUID WHERE IV.OWNER_ID = %I64d AND IV.SLOT_TYPE = 1 AND IV.SLOT_ID = %d;"
								 , m_CSN, INVEN_SLOT_ID);
			CHECK_EQUAL(1, rs.GetFetchedRowCount());
			CHECK_EQUAL(MAIL_ITEM.m_ITEM_ID, rs.Field(L"ITEM_ID").AsInt());
			CHECK_EQUAL(MAIL_ITEM.m_STACK_AMT, rs.Field(L"STACK_AMT").AsShort());
			CHECK_EQUAL(1, rs.Field(L"SOUL_COUNT").AsByte());
			CHECK_EQUAL(MAIL_ITEM.m_DURA, rs.Field(L"DURA").AsByte());
			CHECK_EQUAL(MAIL_ITEM.m_MAX_DURA, rs.Field(L"MAX_DURA").AsByte());
			CHECK_EQUAL(1, rs.Field(L"COLOR").AsInt());
			CHECK_EQUAL(false, rs.Field(L"CLAIMED").AsBool());
			CHECK_EQUAL(m_CHAR_PTM, rs.Field(L"CHAR_PTM").AsInt());
			CHECK_EQUAL(false, rs.Field(L"PERIOD").AsBool());
			CHECK_EQUAL(0, rs.Field(L"USAGE_PERIOD").AsInt());
			CHECK(!rs.Field(L"EFF_START_DATE").IsNull());
			CHECK(rs.Field(L"EFF_END_DATE").IsNull());
			CHECK_EQUAL(MAIL_ITEM.m_ENCH_ITEM_ID_1, rs.Field(L"ENCH_ITEM_ID_1").AsInt());
			CHECK_EQUAL(MAIL_ITEM.m_ENCH_ITEM_ID_2, rs.Field(L"ENCH_ITEM_ID_2").AsInt());
			CHECK_EQUAL(MAIL_ITEM.m_ENCH_ITEM_ID_3, rs.Field(L"ENCH_ITEM_ID_3").AsInt());
			CHECK_EQUAL(MAIL_ITEM.m_ENCH_ITEM_ID_4, rs.Field(L"ENCH_ITEM_ID_4").AsInt());
			CHECK_EQUAL(MAIL_ITEM.m_ENCH_ITEM_ID_5, rs.Field(L"ENCH_ITEM_ID_5").AsInt());
			CHECK_EQUAL(MAIL_ITEM.m_ENCH_ITEM_ID_6, rs.Field(L"ENCH_ITEM_ID_6").AsInt());
			rs.Close();
		}

		int64			m_GSN;
		int64			m_CSN;
		int64			m_MAIL_UID;
		int				m_CHAR_PTM;

		int				m_ITEM_ID_1;
		int				m_ITEM_ID_2;
		int				m_ITEM_ID_3;
		int				m_ITEM_ID_4;
		int				m_ITEM_ID_5;

		TEST_MAIL_ITEM	m_MAIL_ITEM_1;
		TEST_MAIL_ITEM	m_MAIL_ITEM_2;
		TEST_MAIL_ITEM	m_MAIL_ITEM_3;
		TEST_MAIL_ITEM	m_MAIL_ITEM_4;
		TEST_MAIL_ITEM	m_MAIL_ITEM_5;
	};
	

	GAMEDB_TEST_FIXTURE(FIXTURE, USP_RZ_MAIL_GET_ITEM_FIRST_SLOT)
	{
		const int MAIL_ITEM_SLOT_ID = 0;
		const int INVEN_SLOT_ID		= 0;

		InsertEmptySlot();
		CHECK_MAIL_GET_ITEM(MAIL_ITEM_SLOT_ID, INVEN_SLOT_ID, m_MAIL_ITEM_1, m_ITEM_ID_2);
		CHECK_MAIL_DELTED_ITEM(MAIL_ITEM_SLOT_ID);
		CHECK_MAIL_DEF_ITEM_ID(m_ITEM_ID_2);
		CHECK_INVEN_ITEM(INVEN_SLOT_ID, m_MAIL_ITEM_1);
	}

	GAMEDB_TEST_FIXTURE(FIXTURE, USP_RZ_MAIL_GET_ITEM_FIRST_SLOT_CREATE)
	{
		const int MAIL_ITEM_SLOT_ID = 0;
		const int INVEN_SLOT_ID		= 0;

		CHECK_MAIL_GET_ITEM(MAIL_ITEM_SLOT_ID, INVEN_SLOT_ID, m_MAIL_ITEM_1, m_ITEM_ID_2);
		CHECK_MAIL_DELTED_ITEM(MAIL_ITEM_SLOT_ID);
		CHECK_MAIL_DEF_ITEM_ID(m_ITEM_ID_2);
		CHECK_INVEN_ITEM(INVEN_SLOT_ID, m_MAIL_ITEM_1);
	}

	GAMEDB_TEST_FIXTURE(FIXTURE, USP_RZ_MAIL_GET_ITEM_SECOND_SLOT)
	{
		const int MAIL_ITEM_SLOT_ID = 1;
		const int INVEN_SLOT_ID		= 1;

		InsertEmptySlot();
		CHECK_MAIL_GET_ITEM(MAIL_ITEM_SLOT_ID, INVEN_SLOT_ID, m_MAIL_ITEM_2, m_ITEM_ID_3);
		CHECK_MAIL_DELTED_ITEM(MAIL_ITEM_SLOT_ID);
		CHECK_MAIL_DEF_ITEM_ID(m_ITEM_ID_3);
		CHECK_INVEN_ITEM(INVEN_SLOT_ID, m_MAIL_ITEM_2);
	}

	GAMEDB_TEST_FIXTURE(FIXTURE, USP_RZ_MAIL_GET_ITEM_SECOND_SLOT_CREATE)
	{
		const int MAIL_ITEM_SLOT_ID = 1;
		const int INVEN_SLOT_ID		= 1;

		CHECK_MAIL_GET_ITEM(MAIL_ITEM_SLOT_ID, INVEN_SLOT_ID, m_MAIL_ITEM_2, m_ITEM_ID_3);
		CHECK_MAIL_DELTED_ITEM(MAIL_ITEM_SLOT_ID);
		CHECK_MAIL_DEF_ITEM_ID(m_ITEM_ID_3);
		CHECK_INVEN_ITEM(INVEN_SLOT_ID, m_MAIL_ITEM_2);
	}

	GAMEDB_TEST_FIXTURE(FIXTURE, USP_RZ_MAIL_GET_ITEM_THIRD_SLOT)
	{
		const int MAIL_ITEM_SLOT_ID = 2;
		const int INVEN_SLOT_ID		= 2;

		InsertEmptySlot();
		CHECK_MAIL_GET_ITEM(MAIL_ITEM_SLOT_ID, INVEN_SLOT_ID, m_MAIL_ITEM_3, m_ITEM_ID_4);
		CHECK_MAIL_DELTED_ITEM(MAIL_ITEM_SLOT_ID);
		CHECK_MAIL_DEF_ITEM_ID(m_ITEM_ID_4);
		CHECK_INVEN_ITEM(INVEN_SLOT_ID, m_MAIL_ITEM_3);
	}

	GAMEDB_TEST_FIXTURE(FIXTURE, USP_RZ_MAIL_GET_ITEM_THIRD_SLOT_CREATE)
	{
		const int MAIL_ITEM_SLOT_ID = 2;
		const int INVEN_SLOT_ID		= 2;

		CHECK_MAIL_GET_ITEM(MAIL_ITEM_SLOT_ID, INVEN_SLOT_ID, m_MAIL_ITEM_3, m_ITEM_ID_4);
		CHECK_MAIL_DELTED_ITEM(MAIL_ITEM_SLOT_ID);
		CHECK_MAIL_DEF_ITEM_ID(m_ITEM_ID_4);
		CHECK_INVEN_ITEM(INVEN_SLOT_ID, m_MAIL_ITEM_3);
	}

	GAMEDB_TEST_FIXTURE(FIXTURE, USP_RZ_MAIL_GET_ITEM_FOURTH_SLOT)
	{
		const int MAIL_ITEM_SLOT_ID = 3;
		const int INVEN_SLOT_ID		= 3;

		InsertEmptySlot();
		CHECK_MAIL_GET_ITEM(MAIL_ITEM_SLOT_ID, INVEN_SLOT_ID, m_MAIL_ITEM_4, m_ITEM_ID_5);
		CHECK_MAIL_DELTED_ITEM(MAIL_ITEM_SLOT_ID);
		CHECK_MAIL_DEF_ITEM_ID(m_ITEM_ID_5);
		CHECK_INVEN_ITEM(INVEN_SLOT_ID, m_MAIL_ITEM_4);
	}

	GAMEDB_TEST_FIXTURE(FIXTURE, USP_RZ_MAIL_GET_ITEM_FOURTH_SLOT_CREATE)
	{
		const int MAIL_ITEM_SLOT_ID = 3;
		const int INVEN_SLOT_ID		= 3;

		CHECK_MAIL_GET_ITEM(MAIL_ITEM_SLOT_ID, INVEN_SLOT_ID, m_MAIL_ITEM_4, m_ITEM_ID_5);
		CHECK_MAIL_DELTED_ITEM(MAIL_ITEM_SLOT_ID);
		CHECK_MAIL_DEF_ITEM_ID(m_ITEM_ID_5);
		CHECK_INVEN_ITEM(INVEN_SLOT_ID, m_MAIL_ITEM_4);
	}

	GAMEDB_TEST_FIXTURE(FIXTURE, USP_RZ_MAIL_GET_ITEM_FIFTH_SLOT)
	{
		const int MAIL_ITEM_SLOT_ID = 4;
		const int INVEN_SLOT_ID		= 4;

		InsertEmptySlot();
		CHECK_MAIL_GET_ITEM(MAIL_ITEM_SLOT_ID, INVEN_SLOT_ID, m_MAIL_ITEM_5, 0);
		CHECK_MAIL_DELTED_ITEM(MAIL_ITEM_SLOT_ID);
		CHECK_MAIL_DEF_ITEM_ID(0);
		CHECK_INVEN_ITEM(INVEN_SLOT_ID, m_MAIL_ITEM_5);
	}

	GAMEDB_TEST_FIXTURE(FIXTURE, USP_RZ_MAIL_GET_ITEM_FIFTH_SLOT_CREATE)
	{
		const int MAIL_ITEM_SLOT_ID = 4;
		const int INVEN_SLOT_ID		= 4;

		CHECK_MAIL_GET_ITEM(MAIL_ITEM_SLOT_ID, INVEN_SLOT_ID, m_MAIL_ITEM_5, 0);
		CHECK_MAIL_DELTED_ITEM(MAIL_ITEM_SLOT_ID);
		CHECK_MAIL_DEF_ITEM_ID(0);
		CHECK_INVEN_ITEM(INVEN_SLOT_ID, m_MAIL_ITEM_5);
	}

	GAMEDB_TEST_FIXTURE(FIXTURE, USP_RZ_MAIL_GET_ITEM_LIST)
	{
		TDBRecordSet rs;
		UTestDB.Execute(rs, L"{CALL dbo.USP_RZ_MAIL_GET_ITEM_LIST (%d, %I64d)}", GConfig::m_nMyWorldID, m_MAIL_UID);
		CHECK(0 < rs.GetFetchedRowCount());
		int i = 0;
		for (; !rs.IsEOF(); rs.MoveNext())
		{
			TEST_MAIL_ITEM mi;
			if (0 == i) mi = m_MAIL_ITEM_1;
			if (1 == i) mi = m_MAIL_ITEM_2;
			if (2 == i) mi = m_MAIL_ITEM_3;
			if (3 == i) mi = m_MAIL_ITEM_4;
			if (4 == i) mi = m_MAIL_ITEM_5;			
			
			CHECK_EQUAL(mi.m_SLOT_ID, rs.Field(L"SLOT_ID").AsInt());
			CHECK_EQUAL(mi.m_IUID, rs.Field(L"IUID").AsInt64());
			CHECK_EQUAL(mi.m_ITEM_ID, rs.Field(L"ITEM_ID").AsInt());
			CHECK_EQUAL(mi.m_STACK_AMT, rs.Field(L"STACK_AMT").AsInt());
			CHECK_EQUAL(1, rs.Field(L"SOUL_COUNT").AsByte());
			CHECK_EQUAL(mi.m_DURA, rs.Field(L"DURA").AsByte());
			CHECK_EQUAL(mi.m_MAX_DURA, rs.Field(L"MAX_DURA").AsByte());
			CHECK_EQUAL(1, rs.Field(L"COLOR").AsInt());
			CHECK_EQUAL(mi.m_ENCH_ITEM_ID_1, rs.Field(L"ENCH_ITEM_ID_1").AsInt());
			CHECK_EQUAL(mi.m_ENCH_ITEM_ID_2, rs.Field(L"ENCH_ITEM_ID_2").AsInt());
			CHECK_EQUAL(mi.m_ENCH_ITEM_ID_3, rs.Field(L"ENCH_ITEM_ID_3").AsInt());
			CHECK_EQUAL(mi.m_ENCH_ITEM_ID_4, rs.Field(L"ENCH_ITEM_ID_4").AsInt());
			CHECK_EQUAL(mi.m_ENCH_ITEM_ID_5, rs.Field(L"ENCH_ITEM_ID_5").AsInt());
			CHECK_EQUAL(mi.m_ENCH_ITEM_ID_6, rs.Field(L"ENCH_ITEM_ID_6").AsInt());

			 ++i;
		}
		rs.Close();
	}
}