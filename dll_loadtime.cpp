#include <windows.h>
#include <iostream>

extern "C"
{
	__declspec(dllimport) const char *__cdecl str_func_1();
	__declspec(dllimport) void __cdecl void_func_1();
}

int main()
{
    std::cout << "DLL load-time linking\n";
	MessageBox(NULL, str_func_1(), "DLL load-time linking", MB_OK);
	return 0;
}
