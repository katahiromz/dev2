#include "main.h"

extern HINSTANCE g_hInstance;

static BOOL OnEraseBkgnd(HWND hwnd, HDC hdc)
{
    RECT rc;
    ::GetClientRect(hwnd, &rc);

    ::FillRect(hdc, &rc, GetStockBrush(WHITE_BRUSH));
    return TRUE;
}

static void OnPaint(HWND hwnd)
{
    RECT rc;
    ::GetClientRect(hwnd, &rc);

    PAINTSTRUCT ps;
    if (HDC hdc = ::BeginPaint(hwnd, &ps))
    {
        ::Ellipse(hdc, rc.left, rc.top, rc.right, rc.bottom);
        UINT uFormat = DT_SINGLELINE | DT_CENTER | DT_VCENTER;
        ::DrawText(hdc, TEXT("WindowApp"), -1, &rc, uFormat);
        ::EndPaint(hwnd, &ps);
    }
}

static LRESULT CALLBACK
WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        HANDLE_MSG(hwnd, WM_ERASEBKGND, OnEraseBkgnd);
        HANDLE_MSG(hwnd, WM_PAINT, OnPaint);
    default:
        return ::DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}

BOOL RegisterCanvasDx(HINSTANCE hInstance)
{
    WNDCLASSEX wcx = { sizeof(wcx), CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW };
    wcx.lpfnWndProc = WindowProc;
    wcx.hInstance = hInstance;
    wcx.hCursor = ::LoadCursor(NULL, IDC_ARROW);
    wcx.hbrBackground = NULL;
    wcx.lpszClassName = CANVAS_CLASSNAME;
    wcx.hIconSm = NULL;
    if (!::RegisterClassEx(&wcx))
        return FALSE;

    return TRUE;
}

HWND CreateCanvasDx(HWND hwnd)
{
    DWORD style = WS_CHILD | WS_VISIBLE;
    DWORD exstyle = WS_EX_CLIENTEDGE;
    return ::CreateWindowEx(exstyle, CANVAS_CLASSNAME, NULL, style, 0, 0, 0, 0, hwnd,
                            (HMENU)(INT_PTR)IDW_CANVAS, g_hInstance, NULL);
}
