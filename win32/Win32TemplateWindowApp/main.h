#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <cassert>

#include <windows.h>
#include <windowsx.h>
#include <commctrl.h>
#include <commdlg.h>
#include <shlwapi.h>
#include <tchar.h>

#include "resource.h"

#ifdef UNICODE
    typedef std::wstring string_t;
#else
    typedef std::string string_t;
#endif

string_t LoadStringDx(INT id);
VOID AppAboutDx(HWND hwnd);

VOID CenterWindowDx(HWND hwnd);
INT MsgBoxDx(HWND hwnd, LPCTSTR text, LPCTSTR title, UINT uType = MB_ICONINFORMATION);

#define CLASSNAME TEXT("Win32TemplateWindowApp")
