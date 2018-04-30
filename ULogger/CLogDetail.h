#pragma once

#include "stdafx.h"
#include <string>
using namespace std;

class CLogDetail
{
public:
	CLogDetail();
	~CLogDetail();

	virtual char* toString() { return NULL; }
	virtual byte* toBinary() { return NULL; }

private:
	string str;
};

