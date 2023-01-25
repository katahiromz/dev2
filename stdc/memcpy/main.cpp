#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    char buf1[16] = "12345";
    char buf2[16];

    memcpy(buf2, buf1, 16);
    printf("'%s'\n", buf2);

    memcpy(&buf2[3], buf1, 5);
    printf("'%s'\n", buf2);

    return 0;
}
