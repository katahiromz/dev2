#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int do_strncmp(const char *x, const char *y, size_t n)
{
    int ret = strncmp(x, y, n);
    printf("strncmp('%s', '%s', %d) == %d\n", x, y, (int)n, ret);
    return ret;
}

int main(int argc, char **argv)
{
    do_strncmp("test", "test", 4);
    do_strncmp("123", "123", 3);
    do_strncmp("124", "123", 3);
    do_strncmp("123", "124", 3);
    do_strncmp("123", "124", 2);
    do_strncmp("Test", "test", 0);
    do_strncmp("Test", "test", 1);
    do_strncmp("test", "Test", 1);

    return 0;
}
