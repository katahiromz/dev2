#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void do_it(int seed)
{
    printf("seed: %d\n", seed);
    srand(seed);

    for (int i = 0; i < 10; ++i)
    {
        printf(" %d", rand());
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    do_it(1);
    do_it(2);
    do_it(2);
    do_it(3);
    return 0;
}
