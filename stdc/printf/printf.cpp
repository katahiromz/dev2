#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    char buf[] = "hello";
    int i = 1;
    char ch = 2;
    long n = 3;
    long long nn = 4;
    float f = 5;
    double d = 6;
    printf("'%s': %d, %d, %ld, %lld, %f, %f\n", buf, i, ch, n, nn, f, d);
    printf("'%.4s'\n", buf);
    return 0;
}
