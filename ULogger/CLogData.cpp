#include "stdafx.h"
#include "CLogData.h"


CLogData::CLogData()
{
	title.clear();
	title.append("hoge");
}


CLogData::~CLogData()
{
}

string CLogData::toString()
{
	return title;
}

byte* CLogData::toBinary()
{
	return NULL;
}