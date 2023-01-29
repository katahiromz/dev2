#include "main.h"

std::wstring WideFromAnsi(UINT codepage, LPCSTR ansi)
{
    WCHAR wide[1024];
    ::MultiByteToWideChar(codepage, 0, ansi, -1, wide, _countof(wide));
    wide[_countof(wide) - 1] = 0; // Avoid buffer overrun
    return wide;
}

std::string AnsiFromWide(UINT codepage, LPCWSTR wide)
{
    char ansi[1024];
    ::WideCharToMultiByte(codepage, 0, wide, -1, ansi, _countof(ansi), NULL, NULL);
    ansi[_countof(ansi) - 2] = ansi[_countof(ansi) - 1] = 0; // Avoid buffer overrun
    return ansi;
}

//#define LOG_FILE "log.txt"

void DebugOutputA(const char *text)
{
#ifdef LOG_FILE
    if (FILE *fout = fopen(LOG_FILE, "a"))
    {
        fprintf(fout, "%s", text);
        fclose(fout);
    }
#else
    ::OutputDebugStringA(text);
#endif
}

void DebugOutputW(const wchar_t *text)
{
#ifdef LOG_FILE
    if (FILE *fout = fopen(LOG_FILE, "ab"))
    {
        fwrite(text, sizeof(wchar_t), lstrlenW(text), fout);
        fclose(fout);
    }
#else
    ::OutputDebugStringW(text);
#endif
}

void DebugPrintfA(const char *fmt, ...)
{
    va_list va;
    char buf[1024];
    va_start(va, fmt);
    StringCchVPrintfA(buf, _countof(buf), fmt, va);
    DebugOutputA(buf);
    va_end(va);
}

void DebugPrintfW(const wchar_t *fmt, ...)
{
    va_list va;
    wchar_t buf[1024];
    va_start(va, fmt);
    StringCchVPrintfW(buf, _countof(buf), fmt, va);
    DebugOutputW(buf);
    va_end(va);
}

VOID RepositionPointDx(LPPOINT ppt, SIZE siz, LPCRECT prc)
{
    if (ppt->x + siz.cx > prc->right)
        ppt->x = prc->right - siz.cx;
    if (ppt->y + siz.cy > prc->bottom)
        ppt->y = prc->bottom - siz.cy;
    if (ppt->x < prc->left)
        ppt->x = prc->left;
    if (ppt->y < prc->top)
        ppt->y = prc->top;
}

RECT WorkAreaFromWindowDx(HWND hwnd)
{
#if (WINVER >= 0x0500)
    MONITORINFO mi;
    mi.cbSize = sizeof(mi);
    HMONITOR hMonitor = MonitorFromWindow(hwnd, MONITOR_DEFAULTTONEAREST);
    if (GetMonitorInfo(hMonitor, &mi))
    {
        return mi.rcWork;
    }
#endif
    RECT rc;
    ::SystemParametersInfo(SPI_GETWORKAREA, 0, &rc, 0);
    return rc;
}

SIZE SizeFromRectDx(LPCRECT prc)
{
    SIZE siz;
    siz.cx = prc->right - prc->left;
    siz.cy = prc->bottom - prc->top;
    return siz;
}

VOID CenterWindowDx(HWND hwnd)
{
    assert(IsWindow(hwnd));

    BOOL bChild = !!(GetWindowStyle(hwnd) & WS_CHILD);

    HWND hwndParent;
    if (bChild)
        hwndParent = ::GetParent(hwnd);
    else
        hwndParent = ::GetWindow(hwnd, GW_OWNER);

    RECT rcWorkArea = WorkAreaFromWindowDx(hwnd);

    RECT rcParent;
    if (hwndParent)
        ::GetWindowRect(hwndParent, &rcParent);
    else
        rcParent = rcWorkArea;

    SIZE sizParent = SizeFromRectDx(&rcParent);

    RECT rc;
    ::GetWindowRect(hwnd, &rc);
    SIZE siz = SizeFromRectDx(&rc);

    POINT pt;
    pt.x = rcParent.left + (sizParent.cx - siz.cx) / 2;
    pt.y = rcParent.top + (sizParent.cy - siz.cy) / 2;

    if (bChild && hwndParent)
    {
        ::GetClientRect(hwndParent, &rcParent);
        ::MapWindowPoints(hwndParent, NULL, (LPPOINT)&rcParent, 2);
        RepositionPointDx(&pt, siz, &rcParent);

        ::ScreenToClient(hwndParent, &pt);
    }
    else
    {
        RepositionPointDx(&pt, siz, &rcWorkArea);
    }

    ::SetWindowPos(hwnd, NULL, pt.x, pt.y, 0, 0, SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE);
}

static LRESULT CALLBACK
_msgBoxCbtProcDx(INT nCode, WPARAM wParam, LPARAM lParam)
{
    if (nCode == HCBT_ACTIVATE)
    {
        HWND hwnd = (HWND)wParam;
        TCHAR szClassName[16];
        ::GetClassName(hwnd, szClassName, _countof(szClassName));
        if (lstrcmpi(szClassName, TEXT("#32770")) == 0)
        {
            CenterWindowDx(hwnd);
        }
    }
    return 0;   // allow the operation
}

static HHOOK _hookCenterMsgBoxDx(BOOL bHook)
{
    static HHOOK s_hHook = NULL;
    if (bHook)
    {
        if (s_hHook == NULL)
        {
            DWORD dwThreadID = GetCurrentThreadId();
            s_hHook = ::SetWindowsHookEx(WH_CBT, _msgBoxCbtProcDx, NULL, dwThreadID);
        }
    }
    else
    {
        if (s_hHook)
        {
            if (::UnhookWindowsHookEx(s_hHook))
            {
                s_hHook = NULL;
            }
        }
    }
    return s_hHook;
}

INT MsgBoxDx(HWND hwnd, LPCTSTR text, LPCTSTR title, UINT uType)
{
    _hookCenterMsgBoxDx(TRUE);
    INT nID = ::MessageBox(hwnd, text, title, uType);
    _hookCenterMsgBoxDx(FALSE);
    return nID;
}
