#include <windows.h>
#include <iostream>

typedef const char *(*STR_FUNC_1)();
typedef void (*VOID_FUNC_1)();

int main()
{
    std::cout << "DLL run-time linking\n";
	HMODULE hModule = LoadLibrary("sample.dll");
	if (!hModule)
	{
		std::cout << "Loading sample.lib library: " << GetLastError();
        return 1;
	}

    STR_FUNC_1 strFunc1 = (STR_FUNC_1)GetProcAddress(hModule, "str_func_1");
    if (!strFunc1) 
    {
        std::cout << "Getting proc 'str_func_1' address: " << GetLastError(); return 1; }
    VOID_FUNC_1 voidFunc1 = (VOID_FUNC_1)GetProcAddress(hModule, "void_func_1");
    if (!voidFunc1) 
    {
        std::cout << "Getting proc 'void_func_1' address: " << GetLastError();
        return 1;
    }

    // Wrong, loading non existing procedure
    /* if (!GetProcAddress(hModule, "miau")) */ 
    /* { */
    /*     std::cout << "Getting proc 'miau' address: " << GetLastError(); */
    /*     return 1; */
    /* } */

	MessageBox(NULL, strFunc1(), "DLL run-time linking", MB_OK);

	return 0;
}
