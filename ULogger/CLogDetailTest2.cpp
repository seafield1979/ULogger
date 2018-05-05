#include "stdafx.h"
#include "CLogDetailTest2.h"


CLogDetailTest2::CLogDetailTest2()
{
}


CLogDetailTest2::~CLogDetailTest2()
{
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

char* CLogDetailTest2::toString()
{
	static char buf[256];
	char buf2[256] = "\0";

	buf[0] = '\0';

	for (int i = 0; i < ARRAY1_SIZE; i++) {
		if (i > 0) {
			strcat_s(buf, ",");
		}
		sprintf_s(buf2, "[%d]:%d", i, array1[i]);
		strcat_s(buf, buf2);
	}
	return buf;
}

char* CLogDetailTest2::dataTypeString()
{
	return "detail_type:array";
}

byte* CLogDetailTest2::toBinary()
{
	return NULL;
}
