#include "stdafx.h"
#include "CLogger.h"
#include "CLogData.h"

CLogger::CLogger()
{
	for (int i = 0; i < LOG_BUF_SIZE; i++) {
		for (int j = 0; j < LOG_BLOCK_MAX; j++) {
			pBlocks[i][j] = NULL;
		}
	}

	// �ϐ��̏�����
	currentBuffer = 0;
	currentBlock = 0;
	currentPos = 0;
	allocatedBlockNum = 0;
	
	// �ŏ��ɂQ�u���b�N�m��
	for (int i = 0; i < 2; i++) {
		AllocateBlock();
	}

	// Init timer
	InitTimer();
}


CLogger::~CLogger()
{
	// �������J��
	for (int i = 0; i < LOG_BUF_SIZE; i++) {
		ClearBuffer(i);
	}
}

//
// Init Timer
//
bool CLogger::InitTimer() 
{
	// �^�C�}�[�̎��g��(CPU�̎��g��)
	if (!QueryPerformanceFrequency(&qpFrequency)) {
		return false;
	}

	// �J�n�^�C�}�[
	if (!QueryPerformanceCounter(&qpStartCount)) {
		return false;
	}
	
	return true;
}

//
// Get current time
// ���ݎ��Ԃ��擾����
//
double CLogger::GetTime()
{
	LARGE_INTEGER count;			// �J�E���^(�I�u�W�F�N�g������)
	if (!QueryPerformanceCounter(&count)) {
		return 0;
	}
	return (double)(count.QuadPart - qpStartCount.QuadPart) / qpFrequency.QuadPart;
}

//
// Clear Buffer
//
// @input  bufNo: clear buffer number
//
void CLogger::ClearBuffer(int bufNo)
{
	if ( bufNo >= LOG_BUF_SIZE ) {
		return;
	}

	for (int i = 0; i < LOG_BLOCK_MAX; i++) {
		CLog **ppBlock = pBlocks[bufNo][i];

		if (ppBlock != NULL) {
			for (int j = 0; j < LOG_BLOCK_SIZE; j++) {
				CLog *pLog = ppBlock[j];
				if (pLog != NULL) {
					delete pLog;
					ppBlock[j] = NULL;
				}
			}
			delete pBlocks[bufNo][i];
			pBlocks[bufNo][i] = NULL;
		}
	}
}

//
// �u���b�N���m�ۂ���
//
bool CLogger::AllocateBlock()
{
	// ���݂̃o�b�t�@�[�ɋ󂫂����邩���m�F
	if (allocatedBlockNum < LOG_BLOCK_MAX) {
		// �������m��
		pBlocks[currentBuffer][allocatedBlockNum] = new CLog*[LOG_BLOCK_SIZE];

		for (int i = 0; i < LOG_BLOCK_SIZE; i++) {
			pBlocks[currentBuffer][allocatedBlockNum][i] = NULL;
		}

		allocatedBlockNum++;

		return true;
	}
	return false;
}

//
// Print All Logs
//
void CLogger::DebugPrint() 
{
	if (pBlocks == NULL) {
		return;
	}

	for (int i = 0; i < LOG_BUF_SIZE; i++) {
		for (int j = 0; j < LOG_BLOCK_MAX; j++) {
			CLog **ppBlock = pBlocks[i][j];

			if (ppBlock != NULL) {
				for (int k = 0; k < LOG_BLOCK_SIZE; k++) {
					if (ppBlock[k] != NULL) {
						printf_s("[%d][%d][%d] %s\n", i, j, k, ppBlock[k]->toString());
					}
				}
			}
		}
	}
}

//
// ���O��ǉ�����
// @input logId:
// @input logType:
// @input laneId:
// @input pText
// @input pDetail
//
bool CLogger::AddLog(int logId, E_LOG_TYPE logType, int laneId, string *pText)
{
	return AddLog(logId, logType, laneId, pText, NULL);
}

bool CLogger::AddLog(int logId, E_LOG_TYPE logType, int laneId, char *pText)
{
	string text("");
	if (pText != NULL) {
		text = std::string(pText);
	}
	return AddLog(logId, logType, laneId, &text, NULL);
}

bool CLogger::AddLog(int logId, E_LOG_TYPE logType, int laneId, char *pText, CLogDetail *pDetail)
{
	string text("");
	if (pText != NULL) {
		text = std::string(pText);
	}
	return AddLog(logId, logType, laneId, &text, pDetail);
}


bool CLogger::AddLog(int logId, E_LOG_TYPE logType, int laneId, string *pText, CLogDetail *pDetail)
{
	// ���O��ǉ���̃o�b�t�@��T��
	if (pBlocks[currentBuffer][currentBlock] != NULL) {

		// ���݂̃u���b�N�ɋ󂫂��Ȃ��Ȃ玟�̃u���b�N��
		if (currentPos >= LOG_BLOCK_SIZE) {
			if (currentBlock < LOG_BLOCK_MAX) {
				currentBlock++;
				currentPos = 0;
			}
			else {
				// ����ȏ�̃u���b�N�͑��₹�Ȃ�
				return false;
			}
			if (allocatedBlockNum < LOG_BLOCK_MAX) {
				AllocateBlock();
			}
		}

		// ���O��ǉ�
		CLogData *pData = new CLogData(GetTime(), logId, laneId, logType, pText, pDetail);

		CLog **ppLog = pBlocks[currentBuffer][currentBlock];
		ppLog[currentPos] = pData;

		currentPos++;
	}
	return true;
}
