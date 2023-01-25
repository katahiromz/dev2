#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h> // va_list

void MyPrintf(const char *fmt, ...)
{
    va_list va;
    va_start(va, fmt);
    vprintf(fmt, va);
    va_end(va);
}

int main(int argc, char **argv)
{
    MyPrintf("This is a test\n");
    int n = 123;
    MyPrintf("n: %d\n", n);
    return 0;
}
