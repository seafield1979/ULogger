#pragma once

#include "stdafx.h"
#include <string>
using namespace std;

class CLogDetail
{
public:
	CLogDetail();
	~CLogDetail();
	virtual CLogDetail* CreateCopy() { return NULL; }

	virtual string* toString() { return NULL; }
	virtual char* dataTypeString() { return NULL; }
	virtual byte* toBinary() { return NULL; }

protected:
	string *pStrBuf;
};

