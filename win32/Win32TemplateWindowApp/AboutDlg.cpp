#include "main.h"

extern HINSTANCE g_hInstance;

static BOOL OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam)
{
    CenterWindowDx(hwnd);
    return TRUE;
}

static void OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
    switch (id)
    {
    case IDOK:
    case IDCANCEL:
        ::EndDialog(hwnd, id);
        break;
    }
}

static INT_PTR CALLBACK
AboutDlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        HANDLE_MSG(hwnd, WM_INITDIALOG, OnInitDialog);
        HANDLE_MSG(hwnd, WM_COMMAND, OnCommand);
    }
    return 0;
}

VOID AppAboutDx(HWND hwnd)
{
    DialogBox(g_hInstance, MAKEINTRESOURCE(IDD_ABOUT), hwnd, AboutDlgProc);
}
