#pragma once

#include "PMPMSConnector.h"

class PMPMSObject;

class ZPMSSystem : public PMPMSConnector
{
public:
	ZPMSSystem(void);
	~ZPMSSystem(void);

	// PMS 콜백 오브젝트 구하기
	virtual IPMSObject* GetPMSObject() override;
private:
	PMPMSObject* pCallbackObj;
};
