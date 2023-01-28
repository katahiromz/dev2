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

DWORD test_GetFileAttributesA(LPCSTR filename)
{
    DWORD attrs = GetFileAttributesA(filename);
    printf("GetFileAttributesA(%s) = 0x%08X:\n", filename, attrs);
    printf("  ");
#define DO_ATTR(attr, shortname) if (attrs & (attr)) printf("%s ", shortname)
    DO_ATTR(FILE_ATTRIBUTE_READONLY, "read-only");
    DO_ATTR(FILE_ATTRIBUTE_HIDDEN, "hidden");
    DO_ATTR(FILE_ATTRIBUTE_SYSTEM, "system");
    DO_ATTR(FILE_ATTRIBUTE_DIRECTORY, "directory");
    DO_ATTR(FILE_ATTRIBUTE_ARCHIVE, "archive");
    DO_ATTR(FILE_ATTRIBUTE_DEVICE, "device");
    DO_ATTR(FILE_ATTRIBUTE_NORMAL, "normal");
    DO_ATTR(FILE_ATTRIBUTE_TEMPORARY, "temporary");
    DO_ATTR(FILE_ATTRIBUTE_SPARSE_FILE, "sparse");
    DO_ATTR(FILE_ATTRIBUTE_REPARSE_POINT, "reparse_point");
    DO_ATTR(FILE_ATTRIBUTE_COMPRESSED, "compressed");
    DO_ATTR(FILE_ATTRIBUTE_OFFLINE, "offline");
    DO_ATTR(FILE_ATTRIBUTE_ENCRYPTED, "encrypted");
    DO_ATTR(FILE_ATTRIBUTE_VIRTUAL, "virtual");
#undef DO_ATTR
    printf("\n");
    return attrs;
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        test_GetFileAttributesA(argv[1]);
        return 0;
    }

    test_GetFileAttributesA("C:\\");
    test_GetFileAttributesA("C:\\Windows");
    test_GetFileAttributesA("C:\\Windows\\notepad.exe");

    return 0;
}
