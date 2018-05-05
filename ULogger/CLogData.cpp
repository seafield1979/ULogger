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
		// コピーコンストラクタでコピーを作成
		// ※ログをファイルに出力するまでにコピー元が存在しているとは限らないため
		pText = new std::string(*_pText);
	}
	if (_pDetail != NULL) {
		pDetail = _pDetail->CreateCopy();
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
	static char buf[256];
	static char buf2[256];
	
	// log, type:1, id : 1, lane : 1, text : "hoge1", time : 123.456, data_type : str, data : "テキスト"

	strcpy_s(buf, "log");
	sprintf_s(buf2, ",type:%d", logType);
	strcat_s(buf, buf2);
	sprintf_s(buf2, ",id:%d", logId);
	strcat_s(buf, buf2);
	sprintf_s(buf2, ",lane:%d", laneId);
	strcat_s(buf, buf2);
	sprintf_s(buf2, ",time:%.10f", time);
	strcat_s(buf, buf2);

	if (pText != NULL) {
		sprintf_s(buf2, ",text:\"%s\"", pText->c_str());
		strcat_s(buf, buf2);
	}
	if (pDetail != NULL) {
		sprintf_s(buf2, ",%s", pDetail->dataTypeString());
		strcat_s(buf, buf2);

		sprintf_s(buf2, ",{%s}", pDetail->toString());
		strcat_s(buf, buf2);
	}

	return buf;
}

byte* CLogData::toBinary()
{
	return NULL;
}