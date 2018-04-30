#include "stdafx.h"
#include "CLogData.h"


CLogData::CLogData()
{	
}


CLogData::CLogData(double _time, int _logId, int _laneId, E_LOG_TYPE _logType, string *_pText, CLogDetail *_pDetail)
{
	time = _time;
	logId = _logId;
	laneId = _laneId;
	logType = _logType;
	if (_pText != NULL) {
		pText = _pText;
	}
	if (_pDetail != NULL) {
		pDetail = _pDetail;
	}
}


CLogData::~CLogData()
{
	if (pText != NULL) {
		delete pText;
	}
	if (pDetail != NULL) {
		delete pDetail;
	}
}

char* CLogData::toString()
{
	static char buf[100];
	string str;
	str.append("hoge");
	strcpy_s(buf,(char*)str.c_str());
	return buf;
}

byte* CLogData::toBinary()
{
	return NULL;
}