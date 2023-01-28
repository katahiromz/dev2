#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cassert>
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
        return !CreateDirectoryA(argv[1], NULL);
    }

    RemoveDirectoryA("MyDir1");
    RemoveDirectoryW(L"MyDir2");
    RemoveDirectory(TEXT("MyDir3"));

    CreateDirectoryA("MyDir1", NULL);
    CreateDirectoryW(L"MyDir2", NULL);
    CreateDirectory(TEXT("MyDir3"), NULL);

    assert(PathIsDirectoryA("MyDir1"));
    assert(PathIsDirectoryW(L"MyDir2"));
    assert(PathIsDirectory(TEXT("MyDir1")));

    return 0;
}
