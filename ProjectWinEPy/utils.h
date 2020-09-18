#pragma once

wchar_t * char2wchar(const char* cchar);//CHAR转TCHAR
int ExecPy(const wchar_t* script);//执行python
int CDECL MessageBoxPrintf(HWND hand,const TCHAR* szCaption,const TCHAR* szFormat, ...);//便捷messagebox格式输出