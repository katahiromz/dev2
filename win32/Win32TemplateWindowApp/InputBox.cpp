#include "main.h"

extern HINSTANCE g_hInstance;

typedef struct INPUTBOX
{
    string_t m_text;
    string_t m_prompt;
    string_t m_title;
} INPUTBOX, *PINPUTBOX;

static BOOL OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam)
{
    CenterWindowDx(hwnd);

    PINPUTBOX pInputBox = (PINPUTBOX)lParam;
    SetWindowLongPtr(hwnd, DWLP_USER, lParam);

    if (pInputBox->m_prompt.size())
        ::SetDlgItemText(hwnd, stc1, pInputBox->m_prompt.c_str());
    if (pInputBox->m_title.size())
        ::SetWindowText(hwnd, pInputBox->m_title.c_str());
    if (pInputBox->m_text.size())
        ::SetDlgItemText(hwnd, edt1, pInputBox->m_text.c_str());
    return TRUE;
}

static BOOL OnOK(HWND hwnd)
{
    PINPUTBOX pInputBox = (PINPUTBOX)GetWindowLongPtr(hwnd, DWLP_USER);

    TCHAR text[1024];
    ::GetDlgItemText(hwnd, edt1, text, _countof(text));
    pInputBox->m_text = text;

    return TRUE;
}

static void OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
    switch (id)
    {
    case IDOK:
        if (OnOK(hwnd))
        {
            ::EndDialog(hwnd, id);
        }
        break;
    case IDCANCEL:
        ::EndDialog(hwnd, id);
        break;
    }
}

static INT_PTR CALLBACK
InputBoxDlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        HANDLE_MSG(hwnd, WM_INITDIALOG, OnInitDialog);
        HANDLE_MSG(hwnd, WM_COMMAND, OnCommand);
    }
    return 0;
}

BOOL InputBoxDx(HWND hwnd, string_t& text, LPCTSTR prompt, LPCTSTR title)
{
    INPUTBOX inputbox;
    inputbox.m_text = text;
    if (prompt)
        inputbox.m_prompt = prompt;
    if (title)
        inputbox.m_title = title;
    if (::DialogBoxParam(g_hInstance, MAKEINTRESOURCE(IDD_INPUTBOX), hwnd,
                         InputBoxDlgProc, (LPARAM)&inputbox) == IDOK)
    {
        text = std::move(inputbox.m_text);
        return TRUE;
    }
    return FALSE;
}
