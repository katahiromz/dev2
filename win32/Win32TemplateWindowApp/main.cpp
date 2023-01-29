#include "main.h"

HINSTANCE g_hInstance = NULL;
HWND g_hMainWnd = NULL;

string_t LoadStringDx(INT id)
{
    TCHAR text[1024];
    text[0] = 0;
    ::LoadString(NULL, id, text, _countof(text));
    return text;
}

BOOL OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct)
{
    g_hMainWnd = hwnd;
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
    }
}

void OnPaint(HWND hwnd)
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

void OnDestroy(HWND hwnd)
{
    ::PostQuitMessage(0);
}

LRESULT CALLBACK
WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        HANDLE_MSG(hwnd, WM_CREATE, OnCreate);
        HANDLE_MSG(hwnd, WM_COMMAND, OnCommand);
        HANDLE_MSG(hwnd, WM_PAINT, OnPaint);
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
