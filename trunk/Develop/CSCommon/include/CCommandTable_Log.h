#ifndef _C_LOG_COMMAND_TABLE_H_
#define _C_LOG_COMMAND_TABLE_H_

#include "CSCommonLib.h"

enum CLogCommandTable
{
// 커맨드 선언 //////////////////////////////////////////////////////////////////////////
// 커맨드 번호 12001 ~ 14000 까지 사용

// 네트웍 통신(COMM) ---------------------------------------------------------------------------------
	MLC_COMM_LOGIN_REQ			= 120001,		///< (C->S) 로그인 요청
	MLC_COMM_LOGIN				= 120002,		///< (S->C) 로그인	

// 캐릭터(CHAR) --------------------------------------------------------------------------------------
	MLC_CHAR_LOG_REQ			= 120101,		///< (C->S) 캐릭터 로그 요청

// 아이템(ITEM) --------------------------------------------------------------------------------------
	MLC_ITEM_ACQUIRE_LOG_REQ	= 120201,		///< (C->S) 아이템 습득 로그 요청
	MLC_ITEM_LOST_LOG_REQ		= 120202,		///< (C->S) 아이템 손실 로그 요청
	MLC_ITEM_TRADE_LOG_REQ		= 120203,		///< (C->S) 아이템 거래 로그 요청

// 아이템(QUEST) --------------------------------------------------------------------------------------
	MLC_QUEST_LOG_REQ			= 120301,		///< (C->S) 퀘스트 로그 요청
};

// 게임 서버와, 로그 서버가 공유하는 커맨드 등록
CSCOMMON_API void AddLogCommandTable();

#endif