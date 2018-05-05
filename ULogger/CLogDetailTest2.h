#pragma once
#include "CLogDetail.h"

#define ARRAY1_SIZE (10)

class CLogDetailTest2 :
	public CLogDetail
{
public:
	CLogDetailTest2();
	~CLogDetailTest2();
	void Init();

	CLogDetail* CreateCopy();

	virtual char* toString();
	virtual char* dataTypeString();
	virtual byte* toBinary();

private:
	int array1[ARRAY1_SIZE];

public:
	void setArray1(int index, int value) {
		if (index < ARRAY1_SIZE) {
			array1[index] = value;
		}
	}
};
