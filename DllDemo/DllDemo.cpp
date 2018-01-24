// DllDemo.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "DllDemo.h"


// 这是导出变量的一个示例
DLLDEMO_API int nDllDemo=10;

// 这是导出函数的一个示例。
DLLDEMO_API int fnDllDemo(int input)
{
    return input;
}

// 这是导出函数的一个示例。
DLLDEMO_API int fnExternCDllDemo(int input)
{
	return input;
}

// 这是已导出类的构造函数。
// 有关类定义的信息，请参阅 DllDemo.h
CDllDemo::CDllDemo()
{
    return;
}

// 有关类定义的信息，请参阅 DllDemo.h
int CDllDemo::Max(int a,int b)
{
	return a>b?a:b;
}
