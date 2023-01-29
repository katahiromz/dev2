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

HINSTANCE g_hInstance = NULL;
HWND g_hMainWnd = NULL;
HICON g_hIcon = NULL;
HICON g_hIconSm = NULL;

string_t LoadStringDx(INT id)
{
    TCHAR text[1024];
    text[0] = 0;
    ::LoadString(NULL, id, text, _countof(text));
    return text;
}

BOOL OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam)
{
    g_hMainWnd = hwnd;

    g_hIcon = ::LoadIcon(g_hInstance, MAKEINTRESOURCE(IDI_MAINICON));
    g_hIconSm = (HICON)::LoadImage(g_hInstance, MAKEINTRESOURCE(IDI_MAINICON),
        IMAGE_ICON, ::GetSystemMetrics(SM_CXSMICON), ::GetSystemMetrics(SM_CYSMICON),
        0);

    SendMessage(hwnd, WM_SETICON, ICON_BIG, (LPARAM)g_hIcon);
    SendMessage(hwnd, WM_SETICON, ICON_SMALL, (LPARAM)g_hIconSm);

    return TRUE;
}

BOOL OnOK(HWND hwnd)
{
    return TRUE;
}

void OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
    switch (id)
    {
    case IDOK:
        if (OnOK(hwnd))
        {
            EndDialog(hwnd, id);
        }
        break;
    case IDCANCEL:
        EndDialog(hwnd, id);
        break;
    }
}

void OnDestroy(HWND hwnd)
{
    if (g_hIcon)
    {
        ::DestroyIcon(g_hIcon);
        g_hIcon = NULL;
    }
    if (g_hIconSm)
    {
        ::DestroyIcon(g_hIconSm);
        g_hIconSm = NULL;
    }
}

INT_PTR CALLBACK
DialogProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        HANDLE_MSG(hwnd, WM_INITDIALOG, OnInitDialog);
        HANDLE_MSG(hwnd, WM_COMMAND, OnCommand);
        HANDLE_MSG(hwnd, WM_DESTROY, OnDestroy);
    }
    return 0;
}

INT WINAPI
WinMain(HINSTANCE   hInstance,
        HINSTANCE   hPrevInstance,
        LPSTR       lpCmdLine,
        INT         nCmdShow)
{
    g_hInstance = hInstance;
    InitCommonControls();
    DialogBox(hInstance, MAKEINTRESOURCE(IDD_MAIN), NULL, DialogProc);
    return 0;
}
