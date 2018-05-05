#pragma once
#include "CLogDetail.h"
class CLogDetailTest1 :
	public CLogDetail
{
public:
	CLogDetailTest1();
	~CLogDetailTest1();

	CLogDetail* CreateCopy();

	virtual char* toString();
	virtual char* dataTypeString();
	virtual byte* toBinary();

	void setDetailText(string *pText) {
		pDetailText = pText;
	}
private:
	string *pDetailText;
};

