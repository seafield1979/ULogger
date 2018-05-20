#pragma once
#include "CLogDetail.h"
class CLogDetailTest1 :
	public CLogDetail
{
public:
	CLogDetailTest1();
	~CLogDetailTest1();

	CLogDetail* CreateCopy();

	string* toString();
	char* dataTypeString();
	byte* toBinary();

	void setDetailText(string *pText) {
		pDetailText = pText;
	}
private:
	string *pDetailText;
};

