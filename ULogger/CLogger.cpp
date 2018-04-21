#include "stdafx.h"
#include "CLogger.h"
#include "CLogData.h"

CLogger::CLogger()
{
	for (int i = 0; i < LOG_BUF_MAX; i++) {
		pLogs[i] = new CLogData();
	}

	for (int i = 0; i < LOG_BUF_MAX; i++) {
		printf_s("%s\n", pLogs[i]->toString().c_str());
	}
}


CLogger::~CLogger()
{
}
