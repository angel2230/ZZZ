#pragma once

#include "PMPMSConnector.h"

class PMPMSObject;

class ZPMSSystem : public PMPMSConnector
{
public:
	ZPMSSystem(void);
	~ZPMSSystem(void);

	// PMS �ݹ� ������Ʈ ���ϱ�
	virtual IPMSObject* GetPMSObject() override;
private:
	PMPMSObject* pCallbackObj;
};
