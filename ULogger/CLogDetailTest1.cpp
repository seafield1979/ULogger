#include "stdafx.h"
#include "CLogDetailTest1.h"


CLogDetailTest1::CLogDetailTest1()
{
}


CLogDetailTest1::~CLogDetailTest1()
{
}

// Create object copy
CLogDetail* CLogDetailTest1::CreateCopy()
{
	CLogDetailTest1* pCopy = new CLogDetailTest1();
	if (pDetailText != NULL) {
		pCopy->pDetailText = new std::string(*pDetailText);
	}
	return pCopy;
}

string CLogDetailTest1::toString() {

	if (pDetailText != NULL) {
		sprintf_s(buf, "\"%s\"", pDetailText->c_str());
	}
	else {
		buf[0] = '\0';
	}
	return buf;
}

char* CLogDetailTest1::dataTypeString() {
	return "detail_type:str";
}

byte* CLogDetailTest1::toBinary() {
	return NULL; 
}
