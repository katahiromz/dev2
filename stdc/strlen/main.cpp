#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    const char *str1 = "It's a test";
    char str2[] = "TEST";
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    printf("%d, %d\n", (int)len1, (int)len2);
    return 0;
}
