#pragma once

#include "stdafx.h"

#include <string>
using namespace std;

// Type of Log
// ���O�̎��
typedef enum
{
	E_LOG_SINGLE = 0,				// �P�̃��O
	E_LOG_AREA_ST,					// �͈͊J�n
	E_LOG_AREA_END,					// �͈͏I��
	E_LOG_VALUE						// �l
}E_LOG_TYPE;


//
// ���O�f�[�^�̐e�N���X
// ���̃N���X�͉��z�N���X�Ȃ̂Ŏ��ۂ̃��O�͌p����̃N���X�Ŏ�������
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

