#pragma once

#include "stdafx.h"

#include <string>
using namespace std;


class CLog
{
public:
	CLog();
	~CLog();

public:
	virtual string toString() { return string(""); }
	virtual byte* toBinary() { return NULL; }
};

