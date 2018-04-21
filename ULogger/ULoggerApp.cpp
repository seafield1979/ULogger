// ULoggerApp.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include "CLogger.h"

int main(int argc, char* args[])
{
	printf_s("hello world");

	CLogger logger = CLogger();
	// 入力待ち 
	char c = getchar();

    return 0;
}

