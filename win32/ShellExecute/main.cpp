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

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        ShellExecuteA(NULL, NULL, argv[1], NULL, NULL, SW_SHOWNORMAL);
        return 0;
    }

    ShellExecuteA(NULL, NULL, "notepad.exe", NULL, NULL, SW_SHOWNORMAL);

    ShellExecuteA(NULL, NULL, "https://example.com", NULL, NULL, SW_SHOWNORMAL);

    ShellExecuteA(NULL, "open", "C:\\Windows", NULL, NULL, SW_SHOWNORMAL);
    //ShellExecuteA(NULL, "explore", "C:\\Windows", NULL, NULL, SW_SHOWNORMAL);

    return 0;
}
