#pragma once

#include "CLogIDs.h"
#include "CLanes.h"
#include "CIconImages.h"
#include "CLog.h"
#include "CLogDetail.h"
#include "CFileWriter.h"
#include <Windows.h>

#define LOG_BUF_SIZE		(2)
#define LOG_BLOCK_MAX		(10)
#define LOG_BLOCK_SIZE		(10)



class CLogger
{
public:
	CLogger();
	~CLogger();

	//--------------------
	// Properties
	//--------------------
	
private:
	CLogIDs			*logIDs;
	CLanes			*lanes;
	CIconImages		*images;

	int currentBuffer;		// 現在のバッファ番号
	int currentBlock;		// 現在のブロック番号
	int currentPos;			// 現在のブロック内での位置
	int allocatedBlockNum;	// 確保済みのブロック数

	// ダブルバッファなので２つ
	CLog **pBlocks[LOG_BUF_SIZE][LOG_BLOCK_MAX];

	// for Timer
	LARGE_INTEGER qpFrequency;			// タイマーの周波数
	LARGE_INTEGER qpStartCount;			// カウンタ(初期化時)

	//--------------------
	// Methods
	//--------------------
	
public:
	bool InitTimer();
	double GetTime();

	// ログID, ログ名, ログ種別, レーンID(or レーン名), ログ詳細(文字列))
	bool AddLog(int logId, E_LOG_TYPE logType, int laneId, string *pTitle);
	bool AddLog(int logId, E_LOG_TYPE logType, int laneId, string *pTitle, CLogDetail *logDetail);



	// for Debug
	void DebugPrint();
private:
	// バッファーをクリアする
	void ClearBuffer(int bufNo);

	// ブロックを確保する
	bool AllocateBlock();
};

