#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <io.h> // access

void do_access(const char *fname, int flags)
{
    int ret = access(fname, flags);
    printf("access('%s', %02d) == %d, errno:%d\n", fname, flags, ret, errno);
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: \"%s\" file\n", argv[0]);
        return 1;
    }

    do_access(argv[1], 00);
    do_access(argv[1], 02);
    do_access(argv[1], 04);
    do_access(argv[1], 06);
    return 0;
}
