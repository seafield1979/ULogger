#pragma once

#include "CLogIDs.h"
#include "CLanes.h"
#include "CIconImages.h"
#include "CLog.h"
#include "CFileWriter.h"

#define LOG_BUF_MAX		(100)

class CLogger
{
public:
	CLogger();
	~CLogger();

	//--------------------
	// Properties
	//--------------------
	CLogIDs			*logIDs;
	CLanes			*lanes;
	CIconImages		*images;
	
	CLog *pLogs[LOG_BUF_MAX];
};

