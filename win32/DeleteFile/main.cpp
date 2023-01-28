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
        return !DeleteFileA(argv[1]);
    }

    fclose(fopen("test.txt", "wb"));
    if (DeleteFileA("test.txt"))
    {
        printf("test.txt is deleted\n");
    }
    else
    {
        printf("Failed to delete test.txt\n");
    }

    fclose(_wfopen(L"test.txt", L"wb"));
    if (DeleteFileW(L"test.txt"))
    {
        printf("test.txt is deleted\n");
    }
    else
    {
        printf("Failed to delete test.txt\n");
    }

    fclose(_tfopen(TEXT("test.txt"), TEXT("wb")));
    if (DeleteFile(TEXT("test.txt")))
    {
        printf("test.txt is deleted\n");
    }
    else
    {
        printf("Failed to delete test.txt\n");
    }

    return 0;
}
