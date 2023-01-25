#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void do_malloc(size_t size)
{
    char *ptr = (char *)malloc(size + 1);
    if (ptr == NULL)
    {
        printf("malloc(%d): failed\n", (int)size);
        return;
    }

    printf("malloc(%d): success\n", (int)size);
    memset(ptr, 'A', size);
    ptr[size] = 0;
    puts(ptr);

    free(ptr);
}

int main(int argc, char **argv)
{
    do_malloc(0);
    do_malloc(1);
    do_malloc(3);
    do_malloc(64);
    return 0;
}
