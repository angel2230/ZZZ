#pragma once

// NPC 아이콘 상태
// 순서는 우선순위로 정렬된것 함부로 수정x
enum NPC_ICON_TYPE
{
	NIT_NONE = 0,			
	NIT_ITEM_UNUSABLE,		// 아이템이 없어서 인터랙션 불가
	NIT_ITEM_USABLE,		// 아이템사용해서 인터랙션
	NIT_ONLYINTERACTION,	// 인터랙션만 가능(아이콘x)	

	NIT_TRIGGER,			// 트리거
	NIT_QUEST_INTERACT,		// 인터랙션으로 퀘스트 목적 업데이트
	NIT_LOOT,				// 루팅
	NIT_TALK,				// 대화
	NIT_HELPER,				// 가이드
	NIT_SHOP,				// 상점
	NIT_GUILD_CREATE,		// 길드 생성
	NIT_CRAFT,				// 장인	

	NIT_QUEST_NOT_BEGIN_ONLYICON,	// 퀘스트 취득 불가(인터랙션x)
	NIT_QUEST_NOT_BEGIN,			// 퀘스트 취득 불가
	NIT_QUEST_CONTINUE_ONLYICON,	// 퀘스트 수행중(인터랙션x)
	NIT_QUEST_CONTINUE,				// 퀘스트 수행중

	NIT_QUEST_BEGIN,		// 퀘스트 시작
	NIT_QUEST_END,			// 퀘스트 종료
	NIT_COMBAT,				// 전투 돌입	
};

enum INTERACTION_TYPE
{	
	IT_NONE		= 0,	

	IT_AUCTION,
	IT_MAILBOX,
	IT_STORAGE,	
	IT_SOLDTRADE,	
	IT_INN_SLEEP,	

	IT_TRIGGER,
	IT_GUILD_DESTROY,
	IT_GUILD_CREATE,
	IT_GUILD_STORAGE,

	IT_QUEST_INTERACT_MORTAL,
	IT_QUEST_INTERACT_IMMORTAL,

	IT_SOULBINDING,
	IT_CHALLENGERQUEST,

	IT_GATHER_1,
	IT_GATHER_2,
	IT_GATHER_3,
	IT_GATHER_4,
	IT_GATHER_5,
	IT_GATHER_6,
	IT_GATHER_7,
	IT_GATHER_8,
	IT_GATHER_9,
	IT_GATHER_10,
	IT_LOOT_MORTAL,
	IT_LOOT_IMMORTAL,	

	IT_DIALOG,
	IT_NPCSHOP,
	IT_CRAFT,
	IT_QUEST_BEGIN,
	IT_QUEST_END,	
	
	IT_MAX
};

// 인터랙션 방법
enum ITRIGGER_TYPE
{
	ITRT_NONE = 0,
	ITRT_CLICK,
	ITRT_ITEM,

	ITRT_MAX
};

// 인터랙션 대상
enum ITARGET_TYPE
{
	ITAT_NONE = 0,
	ITAT_NPC,
	ITAT_ITEM,

	ITAT_MAX
};

// 인터랙션 대상이 인터랙션 가능한 상태
enum ITARGET_CONDITION_TYPE
{
	ITCT_NONE = 0,
	ITCT_LIVE,
	ITCT_DEAD,
	ITCT_ALL,

	ITCT_MAX
};

#define SLEEP_ANI_TIME				4

#define CLICK_INTERACTION_BEGIN_ID	1
#define ITEM_INTERACTION_BEGIN_ID	100
#define MAX_CLICK_INTERACTION_SIZE	20
#define MAX_ITEM_INTERACTION_SIZE	2