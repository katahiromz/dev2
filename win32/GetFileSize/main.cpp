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

DWORD test_GetFileSize(LPCSTR filename)
{
    HANDLE hFile = CreateFileA(filename, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE,
                               NULL, OPEN_EXISTING, 0, NULL);
    if (hFile == INVALID_HANDLE_VALUE)
    {
        printf("Cannot open\n");
        return 0;
    }

    DWORD size = GetFileSize(hFile, NULL);
    printf("size: %lu (0x%08X)\n", size, size);

    CloseHandle(hFile);
    return size;
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        test_GetFileSize(argv[1]);
        return 0;
    }

    FILE *fp = fopen("test.txt", "w");
    if (fp == NULL)
    {
        printf("could not open\n");
        return 1;
    }

    test_GetFileSize("test.txt");
    fprintf(fp, "This is a test\n");
    test_GetFileSize("test.txt");
    fflush(fp);
    test_GetFileSize("test.txt");
    fclose(fp);

    test_GetFileSize("test.txt");

    DeleteFileA("test.txt");

    return 0;
}
