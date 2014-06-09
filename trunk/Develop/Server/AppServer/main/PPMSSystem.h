#pragma once

#include "PMPMSConnector.h"

class PMPMSObject;

class PPMSSystem : public PMPMSConnector
{
public:
	PPMSSystem(void);
	~PPMSSystem(void);

	// PMS �ݹ� ������Ʈ ���ϱ�
	virtual IPMSObject* GetPMSObject() override;
private:
	PMPMSObject* pCallbackObj;
};
