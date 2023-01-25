#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    printf("TEMP: '%s'\n", getenv("TEMP"));
    putenv("TEMP=/");
    printf("TEMP: '%s'\n", getenv("TEMP"));
    printf("\n");
    printf("PATH: '%s'\n", getenv("PATH"));
    return 0;
}
