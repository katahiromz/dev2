#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    char buf[] = "This is a test.";
    char *ptr;

    ptr = strchr(buf, 'a');
    printf("ptr: '%s'\n", ptr);

    ptr = strchr(buf, 't');
    printf("ptr: '%s'\n", ptr);

    ptr = strchr(buf, 'X');
    printf("ptr: '%s'\n", ptr);

    return 0;
}
