#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    int n = atoi("-234");
    printf("n: %d\n", n);

    long m = atol("-123");
    printf("m: %ld\n", m);

    double f = atof("-123.34");
    printf("f: %f\n", f);
    return 0;
}
