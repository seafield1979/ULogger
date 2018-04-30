#pragma once
#include "CLog.h"
#include "CLogDetail.h"


class CLogData : public CLog
{
private:
	//
	// Properties
	//
	double			time;			// time of log
	string			*pText;			// text
	int				logId;			// log id
	int				laneId;			// lane id
	E_LOG_TYPE		logType;		// type of log
	CLogDetail		*pDetail;		// detail of log
	
public:
	// Constructor
	CLogData();
	CLogData(double _time, int _logId, int _laneId, E_LOG_TYPE _logType, string *_pText, CLogDetail *_pDetail);

	// Destructor
	~CLogData();

	char* toString();
	byte* toBinary();
};

