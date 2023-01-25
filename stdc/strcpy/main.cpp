#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    const char *str1 = "It's a test";
    char str2[128] = "XXX";
    printf("str2: '%s'\n", str2);
    strcpy(str2, str1);
    printf("str2: '%s'\n", str2);
    return 0;
}
