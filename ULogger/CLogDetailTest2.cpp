#include "stdafx.h"
#include "CLogDetailTest2.h"


CLogDetailTest2::CLogDetailTest2()
{
	
}


CLogDetailTest2::~CLogDetailTest2()
{
	if (pStrBuf != NULL) {
		delete pStrBuf;
	}
}

// �I�u�W�F�N�g�R�s�[���ɃR���X�g���N�^�ŏ��������s���ƒl�̐ݒ肪�d�����邽�߁AInit�ŏ������������s��
void CLogDetailTest2::Init()
{
	for (int i = 0; i < ARRAY1_SIZE; i++) {
		array1[i] = i + 1;
	}
}

// Create object copy
CLogDetail* CLogDetailTest2::CreateCopy()
{
	CLogDetailTest2* pCopy = new CLogDetailTest2();
	for (int i = 0; i < ARRAY1_SIZE; i++) {
		pCopy->array1[i] = array1[i];
	}
	
	return pCopy;
}

string* CLogDetailTest2::toString()
{
	pStrBuf = new string();
	char buf[256];
	
	for (int i = 0; i < ARRAY1_SIZE; i++) {
		if (i > 0) {
			pStrBuf->append(",");
		}
		sprintf_s(buf, "[%d]:%d", i, array1[i]);
		pStrBuf->append(buf);
	}
	return pStrBuf;
}

char* CLogDetailTest2::dataTypeString()
{
	return "detail_type:array";
}

byte* CLogDetailTest2::toBinary()
{
	return NULL;
}
