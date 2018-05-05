// ULoggerApp.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include "CLogger.h"
#include "CLogDetailTest1.h"
#include "CLogDetailTest2.h"

int main(int argc, char* args[])
{
	printf_s("hello world\n");

	// Loggerを作成
	CLogger logger = CLogger();

	// ログを追加
	logger.AddLog(1, E_LOG_SINGLE, 1, &(std::string("test1")));

	// 詳細ありのログを追加
	CLogDetailTest1 detail;
	detail.setDetailText(new std::string("hoge123"));	
	logger.AddLog(1, E_LOG_SINGLE, 1, "test2", &detail);

	// 詳細ありのログ２を追加
	CLogDetailTest2 detail2;
	detail2.Init();
	detail2.setArray1(0, 10);
	logger.AddLog(1, E_LOG_SINGLE, 1, "test3", &detail2);

	// ログを表示
	logger.DebugPrint();

	// 入力待ち 
	char c = getchar();

    return 0;
}

