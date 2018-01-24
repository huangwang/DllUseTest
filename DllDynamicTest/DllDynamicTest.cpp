// DllDynamicTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <Windows.h>
#include "DllDemo.h"

/*动态调用动态库步骤：
1、创建一个函数指针，其指针数据类型要与调用的DLL引出函数相吻合。
2、通过Win32 API函数LoadLibrary（）显式的调用DLL，此函数返回DLL的实例句柄。
3、通过Win32 API函数GetProcAddress（）获取要调用的DLL的函数地址, 把结果赋给自定义函数的指针类型。
4、使用函数指针来调用DLL函数。
5、最后调用完成后，通过Win32 API函数FreeLibrary()释放DLL函数。*/

int main()
{
	HMODULE hModule = LoadLibrary(_T("DllDemo.dll"));
	typedef int(*TYPE_fnDllDemo) (int);//定义函数指针  
	typedef int(*TYPE_fnExternCDllDemo) (int);//定义函数指针  
	//创建类对象
	CDllDemo* pCDllDemo = (CDllDemo*)malloc(sizeof(CDllDemo));

	TYPE_fnDllDemo fnDllDemo = (TYPE_fnDllDemo)GetProcAddress(hModule, "?fnDllDemo@@YAHH@Z");
	int *nDllDemo = (int *)GetProcAddress(hModule, "nDllDemo");
	TYPE_fnExternCDllDemo fnExternCDllDemo = (TYPE_fnExternCDllDemo)GetProcAddress(hModule, "fnExternCDllDemo");
	
	if (pCDllDemo != NULL)
		//printf("pCDllDemo->Max(32,42) = %d\n", pCDllDemo->Max(32, 42));//Dll导出类的调用太麻烦，因为DLL本来就是为C函数服务设计的。
	if (fnDllDemo != NULL)
		printf("fnDllDemo(32) = %d\n", fnDllDemo(32));
	if (nDllDemo != NULL)
		printf("*nDllDemo = %d\n", *nDllDemo);
	if (fnExternCDllDemo != NULL)
		printf("fnExternCDllDemo(22) = %d\n", fnExternCDllDemo(22));
	_tsystem(_T("pause"));
    return 0;
}

