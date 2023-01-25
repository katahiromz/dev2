#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    char buf[256] = "This is a test.";

    size_t len = strlen(buf);
    printf("len: %d\n", (int)len);

    printf("buf: '%s'\n", buf);

    memmove(&buf[0], &buf[3], len - 3);
    printf("buf: '%s'\n", buf);

    return 0;
}
