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

	int currentBuffer;		// ���݂̃o�b�t�@�ԍ�
	int currentBlock;		// ���݂̃u���b�N�ԍ�
	int currentPos;			// ���݂̃u���b�N���ł̈ʒu
	int allocatedBlockNum;	// �m�ۍς݂̃u���b�N��

	// �_�u���o�b�t�@�Ȃ̂łQ��
	CLog **pBlocks[LOG_BUF_SIZE][LOG_BLOCK_MAX];

	// for Timer
	LARGE_INTEGER qpFrequency;			// �^�C�}�[�̎��g��
	LARGE_INTEGER qpStartCount;			// �J�E���^(��������)

	//--------------------
	// Methods
	//--------------------
	
public:
	bool InitTimer();
	double GetTime();

	// ���OID, ���O��, ���O���, ���[��ID(or ���[����), ���O�ڍ�(������))
	bool AddLog(int logId, E_LOG_TYPE logType, int laneId, string *pTitle);
	bool AddLog(int logId, E_LOG_TYPE logType, int laneId, string *pTitle, CLogDetail *logDetail);



	// for Debug
	void DebugPrint();
private:
	// �o�b�t�@�[���N���A����
	void ClearBuffer(int bufNo);

	// �u���b�N���m�ۂ���
	bool AllocateBlock();
};

