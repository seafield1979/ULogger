#pragma once
#include "CLog.h"


class CLogData : public CLog
{
private:
	//---------------------
	// Properties
	//---------------------
	string title;

public:
	CLogData();
	~CLogData();

	string toString();
	byte* toBinary();
};

