#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    int i = 0;
    printf("abs(%d): %d\n", i, abs(i));
    i = 2;
    printf("abs(%d): %d\n", i, abs(i));
    i = -3;
    printf("abs(%d): %d\n", i, abs(i));

    long n = -123;
    printf("labs(%ld) = %ld\n", n, labs(n));
    n = 123;
    printf("labs(%ld) = %ld\n", n, labs(n));
    return 0;
}
