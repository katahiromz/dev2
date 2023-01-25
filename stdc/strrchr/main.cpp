#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    char buf[] = "This is a test.";
    char *ptr;

    ptr = strrchr(buf, 't');
    printf("ptr: '%s'\n", ptr);

    ptr = strrchr(buf, 'X');
    printf("ptr: '%s'\n", ptr);

    return 0;
}
