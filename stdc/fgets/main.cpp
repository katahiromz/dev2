#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    printf("Please enter an integer: ");
    char buf[256];
    fgets(buf, 256, stdin);
    int n = atoi(buf);
    printf("n: %d\n", n);
    return 0;
}
