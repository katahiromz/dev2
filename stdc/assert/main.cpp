#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

int main(int argc, char **argv)
{
    int n = 0, m = 1;
    assert(n != m);
    assert(n == m); // assertion failure!
    return 0;
}
