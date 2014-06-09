#pragma once

#include "PMPMSConnector.h"

class PMPMSObject;

class PPMSSystem : public PMPMSConnector
{
public:
	PPMSSystem(void);
	~PPMSSystem(void);

	// PMS 콜백 오브젝트 구하기
	virtual IPMSObject* GetPMSObject() override;
private:
	PMPMSObject* pCallbackObj;
};
