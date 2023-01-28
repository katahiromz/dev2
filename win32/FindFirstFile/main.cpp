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
    WIN32_FIND_DATAA find;
    HANDLE hFind;

    if (argc == 2)
    {
        hFind = FindFirstFileA(argv[1], &find);
    }
    else
    {
        hFind = FindFirstFileA("..\\*", &find);
    }

    if (hFind == INVALID_HANDLE_VALUE)
    {
        printf("Cannot found\n");
        return 1;
    }

    do
    {
        if (find.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
        {
            printf("dir: '%s'\n", find.cFileName);
        }
        else
        {
            printf("file: '%s'\n", find.cFileName);
        }
    } while (FindNextFileA(hFind, &find));

    FindClose(hFind);

    return 0;
}
