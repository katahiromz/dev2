#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    char buf[16 + 1];
    memset(buf, 'A', 16);
    printf("buf: '%s'\n", buf);
    memset(buf, 'B', 8);
    printf("buf: '%s'\n", buf);
    memset(&buf[5], 'c', 3);
    printf("buf: '%s'\n", buf);
    return 0;
}
