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

#define CLASSNAME TEXT("Win32TemplateWindowApp2")
#define CANVAS_CLASSNAME TEXT("Win32TemplateWindowApp2 Canvas")

extern HINSTANCE g_hInstance;

// Window IDs
#define IDW_CANVAS 1
#define IDW_STATUS 2
#define IDW_TOOLBAR 3

string_t LoadStringDx(INT id);
string_t findLocalFile(LPCTSTR filename);

VOID AppAboutDx(HWND hwnd);

VOID CenterWindowDx(HWND hwnd);
INT MsgBoxDx(HWND hwnd, LPCTSTR text, LPCTSTR title, UINT uType = MB_ICONINFORMATION);
BOOL InputBoxDx(HWND hwnd, string_t& text, LPCTSTR prompt = NULL, LPCTSTR title = NULL);

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

inline void str_trim(LPSTR text, LPCSTR spaces = " \t\r\n")
{
    assert(text != NULL);
    assert(spaces != NULL);
    StrTrimA(text, spaces);
}

inline void str_trim(LPWSTR text, LPCWSTR spaces = L" \t\r\n\x3000")
{
    assert(text != NULL);
    assert(spaces != NULL);
    StrTrimW(text, spaces);
}

template <typename T_CHAR>
inline void str_trim(std::basic_string<T_CHAR>& str, const T_CHAR *spaces)
{
    typedef std::basic_string<T_CHAR> string_type;
    size_t i = str.find_first_not_of(spaces);
    size_t j = str.find_last_not_of(spaces);
    if ((i == string_type::npos) || (j == string_type::npos))
    {
        str.clear();
    }
    else
    {
        str = str.substr(i, j - i + 1);
    }
}

template <typename T_STR>
inline bool
str_replace(T_STR& str, const T_STR& from, const T_STR& to)
{
    if (from.empty())
        return false;

    bool ret = false;
    size_t i = 0;
    for (;;) {
        i = str.find(from, i);
        if (i == T_STR::npos)
            break;
        ret = true;
        str.replace(i, from.size(), to);
        i += to.size();
    }
    return ret;
}
template <typename T_STR>
inline bool
str_replace(T_STR& str,
            const typename T_STR::value_type *from,
            const typename T_STR::value_type *to)
{
    assert(from != NULL);
    assert(to != NULL);
    return str_replace(str, T_STR(from), T_STR(to));
}

template <typename T_STR_CONTAINER>
inline void
str_split(T_STR_CONTAINER& container,
          const typename T_STR_CONTAINER::value_type& str,
          const typename T_STR_CONTAINER::value_type& chars)
{
    container.clear();
    assert(!chars.empty());
    size_t i = 0, k = str.find_first_of(chars);
    while (k != T_STR_CONTAINER::value_type::npos)
    {
        container.push_back(str.substr(i, k - i));
        i = k + 1;
        k = str.find_first_of(chars, i);
    }
    container.push_back(str.substr(i));
}

template <typename T_STR_CONTAINER>
inline typename T_STR_CONTAINER::value_type
str_join(const T_STR_CONTAINER& container,
         const typename T_STR_CONTAINER::value_type& sep)
{
    typename T_STR_CONTAINER::value_type result;
    typename T_STR_CONTAINER::const_iterator it, end;
    it = container.begin();
    end = container.end();
    if (it != end)
    {
        result = *it;
        for (++it; it != end; ++it)
        {
            result += sep;
            result += *it;
        }
    }
    return result;
}

// Canvas.cpp
BOOL RegisterCanvasDx(HINSTANCE hInstance);
HWND CreateCanvasDx(HWND hwnd);

// Toolbar.cpp
HWND CreateToolbarDx(HWND hwnd);
void OnToolbarNeedText(LPTOOLTIPTEXT pTTT);
