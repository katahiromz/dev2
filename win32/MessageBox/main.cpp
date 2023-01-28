#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>

#include <windows.h>
#include <windowsx.h>
#include <commctrl.h>
#include <commdlg.h>
#include <shlwapi.h>

int main(int argc, char **argv)
{
    if (MessageBoxA(NULL, "Please press OK", "Hello", MB_OKCANCEL) == IDOK)
    {
        MessageBoxW(NULL, L"You pressed OK \u2764", L"Thank you!", MB_ICONINFORMATION);
    }
    else
    {
        MessageBox(NULL, TEXT("You pressed Cancel"), NULL, MB_ICONERROR);
    }
    return 0;
}
