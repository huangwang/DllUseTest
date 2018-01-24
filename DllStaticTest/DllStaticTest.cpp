// DllTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "DllDemo.h"


int main()
{
	printf("nDllDemo = %d\n", nDllDemo);
	printf("fnDllDemo(42) = %d\n", fnDllDemo(42));
	printf("fnExternCDllDemo(32) = %d\n", fnExternCDllDemo(32));
	CDllDemo* testClass1=new CDllDemo();
	printf("testClass1->Max(32,42) = %d\n", testClass1->Max(32,42));
	CDllDemo testClass2;
	printf("testClass2.Max(32,42) = %d\n", testClass2.Max(32, 42));
	_tsystem(_T("pause"));
    return 0;
}

