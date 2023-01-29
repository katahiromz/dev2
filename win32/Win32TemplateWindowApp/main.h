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
#include <strsafe.h>

#include "resource.h"

#ifdef UNICODE
    typedef std::wstring string_t;
#else
    typedef std::string string_t;
#endif

#define CLASSNAME TEXT("Win32TemplateWindowApp")

string_t LoadStringDx(INT id);
string_t findLocalFile(LPCTSTR filename);

VOID AppAboutDx(HWND hwnd);

VOID CenterWindowDx(HWND hwnd);
INT MsgBoxDx(HWND hwnd, LPCTSTR text, LPCTSTR title, UINT uType = MB_ICONINFORMATION);

RECT WorkAreaFromWindowDx(HWND hwnd);
SIZE SizeFromRectDx(LPCRECT prc);

std::wstring WideFromAnsi(UINT codepage, LPCSTR ansi);
std::string AnsiFromWide(UINT codepage, LPCWSTR wide);

inline std::string AnsiFromAnsi(UINT codepage, LPCSTR ansi) { return ansi; }
inline std::wstring WideFromWide(UINT codepage, LPCWSTR wide) { return wide; }

#ifdef UNICODE
    #define TextFromText WideFromWide
    #define TextFromAnsi WideFromAnsi
    #define TextFromWide WideFromWide
    #define AnsiFromText AnsiFromWide
    #define WideFromText WideFromWide
#else
    #define TextFromText AnsiFromAnsi
    #define TextFromAnsi AnsiFromAnsi
    #define TextFromWide AnsiFromWide
    #define AnsiFromText AnsiFromAnsi
    #define WideFromText WideFromAnsi
#endif

void DebugOutputA(const char *text);
void DebugOutputW(const wchar_t *text);
void DebugPrintfA(const char *fmt, ...);
void DebugPrintfW(const wchar_t *fmt, ...);
#ifdef UNICODE
    #define DebugOutput DebugOutputW
    #define DebugPrintf DebugPrintfW
#else
    #define DebugOutput DebugOutputA
    #define DebugPrintf DebugPrintfA
#endif

#ifdef NDEBUG
    #define DOUT(text) /*empty*/
    #define DOUTA(text) /*empty*/
    #define DOUTW(text) /*empty*/
    #define DPRINT(fmt, ...) /*empty*/
    #define DPRINTA(fmt, ...) /*empty*/
    #define DPRINTW(fmt, ...) /*empty*/
#else
    #define DOUT DebugOutput
    #define DOUTA DebugOutputA
    #define DOUTW DebugOutputW
    #define DPRINT DebugPrintf
    #define DPRINTA DebugPrintfA
    #define DPRINTW DebugPrintfW
#endif
