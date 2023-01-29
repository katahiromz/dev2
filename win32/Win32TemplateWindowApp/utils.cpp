#include "main.h"

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

    SIZE sizParent;
    sizParent.cx = rcParent.right - rcParent.left;
    sizParent.cy = rcParent.bottom - rcParent.top;

    RECT rc;
    ::GetWindowRect(hwnd, &rc);
    SIZE siz;
    siz.cx = rc.right - rc.left;
    siz.cy = rc.bottom - rc.top;

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

    ::SetWindowPos(hwnd, NULL, pt.x, pt.y, 0, 0,
                   SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE);
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

static HHOOK HookCenterMsgBoxDx(BOOL bHook)
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
    HookCenterMsgBoxDx(TRUE);
    INT nID = ::MessageBox(hwnd, text, title, uType);
    HookCenterMsgBoxDx(FALSE);
    return nID;
}
