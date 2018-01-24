// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 DLLDEMO_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何其他项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// DLLDEMO_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。
#ifdef DLLDEMO_EXPORTS
#define DLLDEMO_API __declspec(dllexport)
#else
#define DLLDEMO_API __declspec(dllimport)
#endif

// 此类是从 DllDemo.dll 导出的
class DLLDEMO_API CDllDemo {
public:
	CDllDemo(void);
	// TODO:  在此添加您的方法。
	int Max(int, int);
};

extern "C" extern DLLDEMO_API int nDllDemo;

DLLDEMO_API int fnDllDemo(int);

extern "C" DLLDEMO_API int fnExternCDllDemo(int);
