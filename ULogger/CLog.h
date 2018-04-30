#pragma once

#include "stdafx.h"

#include <string>
using namespace std;

// Type of Log
// ログの種別
typedef enum
{
	E_LOG_SINGLE = 0,				// 単体ログ
	E_LOG_AREA_ST,					// 範囲開始
	E_LOG_AREA_END,					// 範囲終了
	E_LOG_VALUE						// 値
}E_LOG_TYPE;


//
// ログデータの親クラス
// このクラスは仮想クラスなので実際のログは継承先のクラスで実装する
// 
class CLog
{
public:
	CLog();
	~CLog();

	// Properties
	
public:
	virtual char* toString() { return ""; }
	virtual byte* toBinary() { return NULL; }
};

