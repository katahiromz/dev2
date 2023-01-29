#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>

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

#define CLASSNAME TEXT("Win32TemplateWindowApp")
