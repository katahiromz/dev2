#include "main.h"

HINSTANCE g_hInstance = NULL;
HWND g_hMainWnd = NULL;
HWND g_hCanvasWnd = NULL;
HWND g_hStatusBar = NULL;
HWND g_hToolbar = NULL;
BOOL g_bShowToolbar = TRUE;
BOOL g_bShowStatusBar = TRUE;

string_t LoadStringDx(INT id)
{
    TCHAR text[1024];
    text[0] = 0;
    ::LoadString(NULL, id, text, _countof(text));
    return text;
}

BOOL CreateStatusBarDx(HWND hwnd)
{
    DWORD style = WS_CHILD;
    g_hStatusBar = ::CreateStatusWindow(style, NULL, hwnd, IDW_STATUS);
    return (g_hStatusBar != NULL);
}

BOOL OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct)
{
    g_hMainWnd = hwnd;
    if (!CreateStatusBarDx(hwnd))
        return FALSE;

    g_hCanvasWnd = CreateCanvasDx(hwnd);
    if (!g_hCanvasWnd)
        return FALSE;

    g_hToolbar = CreateToolbarDx(hwnd);
    if (!g_hToolbar)
        return FALSE;

    if (g_bShowStatusBar)
    {
        ::ShowWindow(g_hStatusBar, SW_SHOWNOACTIVATE);
    }

    if (g_bShowToolbar)
    {
        ::ShowWindow(g_hToolbar, SW_SHOWNOACTIVATE);
    }

    ::PostMessage(hwnd, WM_SIZE, 0, 0);
    ::PostMessage(hwnd, WM_COMMAND, ID_READY, 0);
    return TRUE;
}

void OnTest1(HWND hwnd)
{
    MsgBoxDx(hwnd, TEXT("This is a test."), LoadStringDx(IDS_APPNAME).c_str());
}

void OnTest2(HWND hwnd)
{
    MsgBoxDx(hwnd, TEXT("This is a test."), LoadStringDx(IDS_APPNAME).c_str());
}

void OnTest3(HWND hwnd)
{
    string_t text;
    if (InputBoxDx(hwnd, text))
    {
        MsgBoxDx(hwnd, text.c_str(), LoadStringDx(IDS_APPNAME).c_str());
    }
}

void OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
    static INT s_cLock = 0;

    s_cLock++;
    switch (id)
    {
    case ID_TEST1:
        OnTest1(hwnd);
        break;
    case ID_TEST2:
        OnTest2(hwnd);
        break;
    case ID_TEST3:
        OnTest3(hwnd);
        break;
    case ID_EXIT:
        ::DestroyWindow(hwnd);
        break;
    case ID_ABOUT:
        AppAboutDx(hwnd);
        break;
    case ID_VIEW_TOOLBAR:
        if (IsWindowVisible(g_hToolbar))
            ShowWindow(g_hToolbar, SW_HIDE);
        else
            ShowWindow(g_hToolbar, SW_SHOWNOACTIVATE);
        g_bShowToolbar = IsWindowVisible(g_hToolbar);
        PostMessage(hwnd, WM_SIZE, 0, 0);
        break;
    case ID_VIEW_STATUSBAR:
        if (IsWindowVisible(g_hStatusBar))
            ShowWindow(g_hStatusBar, SW_HIDE);
        else
            ShowWindow(g_hStatusBar, SW_SHOWNOACTIVATE);
        g_bShowStatusBar = IsWindowVisible(g_hStatusBar);
        PostMessage(hwnd, WM_SIZE, 0, 0);
        break;
    case ID_READY:
        break;
    }
    s_cLock--;

    if (s_cLock == 0)
    {
        ::SendMessage(g_hStatusBar, SB_SETTEXT, 0 | 0, (LPARAM)LoadStringDx(IDS_READY).c_str());
    }
}

LRESULT OnNotify(HWND hwnd, int idFrom, LPNMHDR pnmhdr)
{
    switch (pnmhdr->code)
    {
    case TTN_NEEDTEXT:
        {
            LPTOOLTIPTEXT pTTT = LPTOOLTIPTEXT(pnmhdr);
            OnToolbarNeedText(pTTT);
            return 0;
        }
    }
    return 0;
}

void OnSize(HWND hwnd, UINT state, int cx, int cy)
{
    RECT rc;
    ::GetClientRect(hwnd, &rc);

    ::SendMessage(g_hStatusBar, WM_SIZE, 0, 0);
    ::SendMessage(g_hToolbar, TB_AUTOSIZE, 0, 0);

    if (::IsWindowVisible(g_hStatusBar))
    {
        RECT rcStatus;
        ::GetWindowRect(g_hStatusBar, &rcStatus);
        rc.bottom -= rcStatus.bottom - rcStatus.top;
    }

    if (::IsWindowVisible(g_hToolbar))
    {
        RECT rcTool;
        ::GetWindowRect(g_hToolbar, &rcTool);
        rc.top += rcTool.bottom - rcTool.top;
    }

    ::MoveWindow(g_hCanvasWnd, rc.left, rc.top, rc.right - rc.left, rc.bottom - rc.top, TRUE);
}

void OnInitMenuPopup(HWND hwnd, HMENU hMenu, UINT item, BOOL fSystemMenu)
{
    if (::IsWindowVisible(g_hStatusBar))
        ::CheckMenuItem(hMenu, ID_VIEW_STATUSBAR, MF_CHECKED);
    else
        ::CheckMenuItem(hMenu, ID_VIEW_STATUSBAR, MF_UNCHECKED);

    if (::IsWindowVisible(g_hToolbar))
        ::CheckMenuItem(hMenu, ID_VIEW_TOOLBAR, MF_CHECKED);
    else
        ::CheckMenuItem(hMenu, ID_VIEW_TOOLBAR, MF_UNCHECKED);
}

void OnDestroy(HWND hwnd)
{
    if (g_hStatusBar)
    {
        ::DestroyWindow(g_hStatusBar);
        g_hStatusBar = NULL;
    }
    if (g_hCanvasWnd)
    {
        ::DestroyWindow(g_hCanvasWnd);
        g_hCanvasWnd = NULL;
    }
    if (g_hToolbar)
    {
        ::DestroyWindow(g_hToolbar);
        g_hToolbar = NULL;
    }
    ::PostQuitMessage(0);
}

LRESULT CALLBACK
WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        HANDLE_MSG(hwnd, WM_CREATE, OnCreate);
        HANDLE_MSG(hwnd, WM_COMMAND, OnCommand);
        HANDLE_MSG(hwnd, WM_NOTIFY, OnNotify);
        HANDLE_MSG(hwnd, WM_SIZE, OnSize);
        HANDLE_MSG(hwnd, WM_INITMENUPOPUP, OnInitMenuPopup);
        HANDLE_MSG(hwnd, WM_DESTROY, OnDestroy);
    default:
        return ::DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}

BOOL InitInst(HINSTANCE hInstance)
{
    g_hInstance = hInstance;

    WNDCLASSEX wcx = { sizeof(wcx), CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW };
    wcx.lpfnWndProc = WindowProc;
    wcx.hInstance = hInstance;
    //wcx.hIcon = ::LoadIcon(NULL, IDI_APPLICATION);
    wcx.hIcon = ::LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MAINICON));
    wcx.hCursor = ::LoadCursor(NULL, IDC_ARROW);
    wcx.hbrBackground = (HBRUSH)(INT_PTR)(COLOR_3DFACE + 1);
    wcx.lpszMenuName = MAKEINTRESOURCE(IDR_MAINMENU);
    wcx.lpszClassName = CLASSNAME;
    wcx.hIconSm = NULL;
    if (!::RegisterClassEx(&wcx))
    {
        MessageBox(NULL, TEXT("RegisterClassEx failed"), NULL, MB_ICONERROR);
        return FALSE;
    }

    if (!RegisterCanvasDx(hInstance))
    {
        MessageBox(NULL, TEXT("RegisterClassEx failed"), NULL, MB_ICONERROR);
        return FALSE;
    }

    return TRUE;
}

INT Run(HINSTANCE hInstance, INT nCmdShow)
{
    string_t title = LoadStringDx(IDS_APPNAME);

    DWORD style = WS_OVERLAPPEDWINDOW;
    DWORD exstyle = 0;
    ::CreateWindowEx(exstyle, CLASSNAME, title.c_str(), style,
                     CW_USEDEFAULT, CW_USEDEFAULT, 500, 300,
                     NULL, NULL, hInstance, NULL);
    if (g_hMainWnd == NULL)
    {
        ::MessageBox(NULL, TEXT("CreateWindowEx failed"), NULL, MB_ICONERROR);
        return FALSE;
    }

    ::ShowWindow(g_hMainWnd, nCmdShow);
    ::UpdateWindow(g_hMainWnd);

    MSG msg;
    while (::GetMessage(&msg, NULL, 0, 0))
    {
        ::TranslateMessage(&msg);
        ::DispatchMessage(&msg);
    }

    return (INT)msg.wParam;
}

INT WINAPI
WinMain(HINSTANCE   hInstance,
        HINSTANCE   hPrevInstance,
        LPSTR       lpCmdLine,
        INT         nCmdShow)
{
    InitCommonControls();

    if (!InitInst(hInstance))
        return -1;

    return Run(hInstance, nCmdShow);
}
