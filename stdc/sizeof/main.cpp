#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    int a;
    char b;
    long c;
    long long d;
    size_t e = sizeof(d);
    printf("sizeof(int) == %d\n", (int)sizeof(int));
    printf("sizeof(a) == %d\n", (int)sizeof(a));
    printf("sizeof(b) == %d\n", (int)sizeof(b));
    printf("sizeof(c) == %d\n", (int)sizeof(c));
    printf("sizeof(d) == %d\n", (int)sizeof(d));
    printf("%d\n", (int)e);
    return 0;
}
