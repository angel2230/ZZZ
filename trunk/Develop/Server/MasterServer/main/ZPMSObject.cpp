#include "StdAfx.h"
#include "ZPMSObject.h"
#include "PMPMSConnector.h"
#include "PmRegionStat.h"
#include "MLocale.h"
#include "ZCommandCenter.h"
#include "CCommandTable_Master.h"
#include "MLocale.h"

ZPMSObject::ZPMSObject(PMPMSConnector* pPMS)
: PMPMSObject(pPMS)
{
}

ZPMSObject::~ZPMSObject(void)
{
}

BOOL ZPMSObject::OnAnnounceReq(DWORD dwSSN, DWORD dwCategoryID, LPCSTR lpszMsg)
{
	VALID_RET(lpszMsg != NULL, FALSE);

	MCommand* pNewCmd = gsys.pCommandCenter->MakeNewCommand(MMC_MSG_ANNOUNCE
															, 1
															, NEW_WSTR(MLocale::ConvAnsiToUCS2(lpszMsg).c_str())
															);

	gsys.pCommandCenter->RouteToGameServer(pNewCmd);	
	
	return TRUE;
}

// GameServer만 보내주면, 네오위즈에서 합산한다고 함. [2010/8/3 praptor]
//BOOL ZPMSObject::OnRegionInfoReq( IPMSRegionInfoList* plstRegionInfo )
//{
//	VALID_RET(plstRegionInfo, FALSE);
//
//	DWORD nSSN = GetPMS()->GetSSN();
//	DWORD nCategory = GetPMS()->GetCategory();
//	VLONG* vRegionStat = GetPMS()->GetRegionStat()->GetRegionStat();
//
//	plstRegionInfo->AddRegionInfo(nSSN, nCategory, vRegionStat);
//
//	return TRUE;
//}
//
//BOOL ZPMSObject::OnStatInfoReq( IPMSStatInfoList* plstStatInfo )
//{
//	DWORD nSSN = GetPMS()->GetSSN();
//	DWORD nCategory = GetPMS()->GetCategory();
//	DWORD nCU = GetPMS()->GetRegionStat()->GetTotalUserCount();
//
//	plstStatInfo->AddStatInfoList(nSSN, nCategory, nCU, 0, 0, 0, NULL);
//
//	return TRUE;
//}
