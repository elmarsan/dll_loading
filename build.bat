@echo off

if exist ".\build" (
    rmdir /s /q ".\build"
)

mkdir ".\build"

:: dll build
cl ^
    dll_main.cpp ^
    /LD ^
    /EHsc ^
    /Fe"build\sample.dll" ^
    /Fo"build\sample.obj"

:: load-time link executable
cl ^
    dll_loadtime.cpp ^
    /Fe".\build\dll_loadtime.exe" ^
    /Fo".\build\dll_loadtime.obj" ^
    /EHsc ^
    /link /SUBSYSTEM:CONSOLE ".\build\sample.lib" user32.lib

:: run-time link executable
cl ^
    dll_runtime.cpp ^
    /Fe".\build\dll_runtime.exe" ^
    /Fo".\build\dll_loadtime.obj" ^
    /EHsc ^
    /link /SUBSYSTEM:CONSOLE user32.lib
