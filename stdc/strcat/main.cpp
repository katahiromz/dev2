#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    char buf[256] = "TEST ";
    printf("buf: '%s'\n", buf);
    strcat(buf, "TEST");
    printf("buf: '%s'\n", buf);
    return 0;
}
