#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int do_memcmp(const char *p1, const char *p2, size_t size)
{
    int ret = memcmp(p1, p2, size);
    printf("memcmp('%s', '%s', %d): %d\n", p1, p2, (int)size, ret);
    return ret;
}

int main(int argc, char **argv)
{
    do_memcmp("TEST", "TEST", 4);
    do_memcmp("TEST123", "TEST123", 4);
    do_memcmp("TEST123", "TEST124", 4);
    do_memcmp("TEST123", "TEST123", 7);
    do_memcmp("TEST123", "TEST124", 7);
    do_memcmp("TEST124", "TEST123", 7);
    return 0;
}
