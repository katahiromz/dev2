#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *do_strstr(const char *x, const char *y)
{
    char *ret = strstr(x, y);
    printf("strstr('%s', '%s'): '%s'\n", x, y, ret);
    return ret;
}

int main(int argc, char **argv)
{
    do_strstr("This is a test", "test");
    do_strstr("This is a test", "XXX");
    do_strstr("This is a test", " is ");
    do_strstr("This is a test", " IS ");
    return 0;
}
