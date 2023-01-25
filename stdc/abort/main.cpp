#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    printf("Let's abort!\n");

    abort();

    printf("This line is not executed.\n");

    return 0;
}
