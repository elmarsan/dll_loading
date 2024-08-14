#include "pch.h"

#include <iostream>
#include <windows.h>

extern "C"
{
	__declspec(dllexport) const char *__cdecl str_func_1()
	{
		return "I'm str_func_1";
	}

	__declspec(dllexport) void __cdecl void_func_1()
	{
		std::cout << "I'm void_func_1";
	}

	__declspec(dllexport) int int_var_1 = 42;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call,
					  LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
        std::cout << "DLL_PROCESS_ATTACH\n";
	case DLL_THREAD_ATTACH:
        std::cout << "DLL_THREAD_ATTACH\n";
	case DLL_THREAD_DETACH:
        std::cout << "DLL_THREAD_DETACH\n";
	case DLL_PROCESS_DETACH:
        std::cout << "DLL_PROCESS_DETACH\n";
		break;
	}
	return TRUE;
}
