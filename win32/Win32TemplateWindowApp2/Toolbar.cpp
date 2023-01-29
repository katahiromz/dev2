#include "main.h"

HWND CreateToolbarDx(HWND hwnd)
{
    HWND hwndToolbar = NULL;
    DWORD style, exstyle;
    INT id;
    BOOL bUseLargeButtons = FALSE;   // TODO: Modify

    // TODO: Modify toolbar buttons
    static TBBUTTON buttons[] =
    {
        // { image index, command id, button state, BTNS_, ... }
        { STD_FILENEW, ID_NEW, TBSTATE_ENABLED, BTNS_BUTTON | BTNS_AUTOSIZE },
        { -1, -1, TBSTATE_ENABLED, BTNS_SEP },
        { STD_FILEOPEN, ID_OPEN, TBSTATE_ENABLED, BTNS_BUTTON | BTNS_AUTOSIZE },
        { STD_FILESAVE, ID_SAVE, TBSTATE_ENABLED, BTNS_BUTTON | BTNS_AUTOSIZE },
        { -1, -1, TBSTATE_ENABLED, BTNS_SEP },
        { STD_PRINTPRE, ID_PRINTPREVIEW, TBSTATE_ENABLED, BTNS_BUTTON | BTNS_AUTOSIZE },
        { STD_PRINT, ID_PRINT, TBSTATE_ENABLED, BTNS_BUTTON | BTNS_AUTOSIZE },
        { -1, -1, TBSTATE_ENABLED, BTNS_SEP },
        { STD_UNDO, ID_UNDO, TBSTATE_ENABLED, BTNS_BUTTON | BTNS_AUTOSIZE },
        { STD_REDOW, ID_REDO, TBSTATE_ENABLED, BTNS_BUTTON | BTNS_AUTOSIZE },
        { -1, -1, TBSTATE_ENABLED, BTNS_SEP },
        { STD_CUT, ID_CUT, TBSTATE_ENABLED, BTNS_BUTTON | BTNS_AUTOSIZE },
        { STD_COPY, ID_COPY, TBSTATE_ENABLED, BTNS_BUTTON | BTNS_AUTOSIZE },
        { STD_PASTE, ID_PASTE, TBSTATE_ENABLED, BTNS_BUTTON | BTNS_AUTOSIZE },
        { STD_DELETE, ID_DELETE, TBSTATE_ENABLED, BTNS_BUTTON | BTNS_AUTOSIZE },
        { -1, -1, TBSTATE_ENABLED, BTNS_SEP },
        { STD_PROPERTIES, ID_PROPERTIES, TBSTATE_ENABLED, BTNS_BUTTON | BTNS_AUTOSIZE },
        { -1, -1, TBSTATE_ENABLED, BTNS_SEP },
        { STD_FIND, ID_FIND, TBSTATE_ENABLED, BTNS_BUTTON | BTNS_AUTOSIZE },
        { STD_REPLACE, ID_REPLACE, TBSTATE_ENABLED, BTNS_BUTTON | BTNS_AUTOSIZE },
        { -1, -1, TBSTATE_ENABLED, BTNS_SEP },
        { STD_HELP, ID_HELP, TBSTATE_ENABLED, BTNS_BUTTON | BTNS_AUTOSIZE },
    };
    size_t i, k;
    LPTSTR text;

    // TODO: Invalidate iString's
    for (i = 0; i < _countof(buttons); ++i)
    {
        buttons[i].iString = -1;
    }

    // Create hwndToolbar
    style = WS_CHILD | CCS_TOP | TBS_HORZ | TBSTYLE_TOOLTIPS;
    exstyle = 0;
    id = IDW_TOOLBAR;
    hwndToolbar = CreateWindowEx(exstyle, TOOLBARCLASSNAME, NULL,
                                 style, 0, 0, 0, 0, hwnd, (HMENU)(INT_PTR)id, g_hInstance, NULL);
    if (!hwndToolbar)
        return NULL;

    // Initialize toolbar
    SendMessage(hwndToolbar, TB_BUTTONSTRUCTSIZE, sizeof(TBBUTTON), 0);

    // Enable multiple image lists
    SendMessage(hwndToolbar, CCM_SETVERSION, 5, 0);

    if (bUseLargeButtons)
    {
        TBADDBITMAP AddBitmap = { HINST_COMMCTRL, IDB_STD_LARGE_COLOR };
        SendMessage(hwndToolbar, TB_ADDBITMAP, 0, (LPARAM)&AddBitmap);
    }
    else
    {
        TBADDBITMAP AddBitmap = { HINST_COMMCTRL, IDB_STD_SMALL_COLOR };
        SendMessage(hwndToolbar, TB_ADDBITMAP, 0, (LPARAM)&AddBitmap);
    }

    SendMessage(hwndToolbar, TB_ADDBUTTONS, _countof(buttons), (LPARAM)&buttons);

    // TODO: Set extended style
    {
        DWORD extended = 0;
        extended |= TBSTYLE_EX_DRAWDDARROWS; // BTNS_DROPDOWN and BTNS_WHOLEDROPDOWN will work
        extended |= TBSTYLE_EX_HIDECLIPPEDBUTTONS;
        SendMessage(hwndToolbar, TB_SETEXTENDEDSTYLE, 0, extended);
    }

    return hwndToolbar;
}

void OnToolbarNeedText(LPTOOLTIPTEXT pTTT)
{
    pTTT->hinst = g_hInstance;
    switch (pTTT->hdr.idFrom)
    {
    case ID_NEW:
        pTTT->lpszText = MAKEINTRESOURCE(IDS_NEW);
        break;
    case ID_OPEN:
        pTTT->lpszText = MAKEINTRESOURCE(IDS_OPEN);
        break;
    case ID_SAVE:
        pTTT->lpszText = MAKEINTRESOURCE(IDS_SAVE);
        break;
    case ID_PRINTPREVIEW:
        pTTT->lpszText = MAKEINTRESOURCE(IDS_PRINTPREVIEW);
        break;
    case ID_PRINT:
        pTTT->lpszText = MAKEINTRESOURCE(IDS_PRINT);
        break;
    case ID_UNDO:
        pTTT->lpszText = MAKEINTRESOURCE(IDS_UNDO);
        break;
    case ID_REDO:
        pTTT->lpszText = MAKEINTRESOURCE(IDS_REDO);
        break;
    case ID_CUT:
        pTTT->lpszText = MAKEINTRESOURCE(IDS_CUT);
        break;
    case ID_COPY:
        pTTT->lpszText = MAKEINTRESOURCE(IDS_COPY);
        break;
    case ID_PASTE:
        pTTT->lpszText = MAKEINTRESOURCE(IDS_PASTE);
        break;
    case ID_DELETE:
        pTTT->lpszText = MAKEINTRESOURCE(IDS_DELETE);
        break;
    case ID_PROPERTIES:
        pTTT->lpszText = MAKEINTRESOURCE(IDS_PROPERTIES);
        break;
    case ID_FIND:
        pTTT->lpszText = MAKEINTRESOURCE(IDS_FIND);
        break;
    case ID_REPLACE:
        pTTT->lpszText = MAKEINTRESOURCE(IDS_REPLACE);
        break;
    case ID_HELP:
        pTTT->lpszText = MAKEINTRESOURCE(IDS_HELP);
        break;
    case ID_VIEW_TOOLBAR:
        pTTT->lpszText = MAKEINTRESOURCE(IDS_VIEW_TOOLBAR);
        break;
    case ID_VIEW_STATUSBAR:
        pTTT->lpszText = MAKEINTRESOURCE(IDS_VIEW_STATUSBAR);
        break;
    }
}
