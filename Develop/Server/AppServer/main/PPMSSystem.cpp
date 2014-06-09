#include "stdafx.h"
#include "PPMSSystem.h"
#include "PMServerInitLogger.h"
#include "PMPMSObject.h"
#include "PConfig.h"

PPMSSystem::PPMSSystem()
{
	SetGameInfo(PConfig::m_SSN, PConfig::m_nMyWorldID);
	pCallbackObj = new PMPMSObject(this);
}

PPMSSystem::~PPMSSystem()
{
	SAFE_DELETE(pCallbackObj);
}

IPMSObject* PPMSSystem::GetPMSObject()
{
	return pCallbackObj;
}