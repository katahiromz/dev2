#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int do_strcmp(const char *x, const char *y)
{
    int ret = strcmp(x, y);
    printf("strcmp('%s', '%s') == %d\n", x, y, ret);
    return ret;
}

int main(int argc, char **argv)
{
    do_strcmp("test", "test");
    do_strcmp("123", "123");
    do_strcmp("124", "123");
    do_strcmp("123", "124");
    do_strcmp("Test", "test");
    do_strcmp("test", "Test");

    return 0;
}
