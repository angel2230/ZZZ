#pragma once

#include "PmDef.h"
#include "PMPMSObject.h"

class ZPMSObject : public PMPMSObject
{
public:
	ZPMSObject(PMPMSConnector* pPMS);
	virtual ~ZPMSObject(void);

	virtual BOOL OnAnnounceReq(DWORD dwSSN, DWORD dwCategoryID, LPCSTR lpszMsg) override;

	// GameServer만 보내주면, 네오위즈에서 합산한다고 함. [2010/8/3 praptor]
	//virtual BOOL OnRegionInfoReq(IPMSRegionInfoList* plstRegionInfo) override;
	//virtual BOOL OnStatInfoReq( IPMSStatInfoList* plstStatInfo ) override;
};
