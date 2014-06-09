#include "stdafx.h"
#include "ZPMSSystem.h"
#include "PMServerInitLogger.h"
#include "ZPMSObject.h"
#include "ZConfig.h"

ZPMSSystem::ZPMSSystem()
{
	SetGameInfo(ZConfig::m_SSN, ZConfig::m_nMyWorldID);
	pCallbackObj = new ZPMSObject(this);
}

ZPMSSystem::~ZPMSSystem()
{
	SAFE_DELETE(pCallbackObj);
}

IPMSObject* ZPMSSystem::GetPMSObject()
{
	return pCallbackObj;
}