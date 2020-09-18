#include "stdafx.h"
#include "utils.h"
#define MAX_BUFF 1000

wchar_t * char2wchar(const char* cchar)
{
	wchar_t *m_wchar;
	int len = MultiByteToWideChar(CP_ACP, 0, cchar, strlen(cchar), NULL, 0);
	m_wchar = new wchar_t[len + 1];
	MultiByteToWideChar(CP_ACP, 0, cchar, strlen(cchar), m_wchar, len);
	m_wchar[len] = '\0';
	return m_wchar;
}

int ExecPy(const wchar_t* script)
{
	const wchar_t** argv;
	argv = (const wchar_t**)malloc(sizeof(wchar_t *) * (2));
	argv[0] = L"python";
	argv[1] = script;
	return Py_Main(2, (wchar_t **)argv);
	free((void *)argv);
}

int CDECL MessageBoxPrintf(HWND hand,const TCHAR* szCaption, const TCHAR* szFormat, ...)
{
	TCHAR content[MAX_BUFF];

	va_list args;
	va_start(args, szFormat);
	wvsprintf(content, szFormat, args);
	va_end(args);
	return MessageBox(hand, content, szCaption, NULL);
}
