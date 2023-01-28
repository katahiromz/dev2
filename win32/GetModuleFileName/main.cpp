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
    TCHAR szPath[MAX_PATH];
    GetModuleFileNameA(NULL, szPath, _countof(szPath));
    printf("szPath: '%s'\n", szPath);
    return 0;
}
