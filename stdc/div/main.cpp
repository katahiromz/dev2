#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void do_div(int num, int denom)
{
    div_t d = div(num, denom);
    printf("div(%d, %d) == (%d, %d)\n", num, denom, d.quot, d.rem);
}

void do_ldiv(int num, int denom)
{
    ldiv_t d = ldiv(num, denom);
    printf("ldiv(%ld, %ld) == (%ld, %ld)\n", num, denom, d.quot, d.rem);
}

int main(int argc, char **argv)
{
    do_div(5, 3);
    do_div(5, 2);
    do_div(7, 5);
    do_div(-5, 2);
    do_div(5, -2);

    do_ldiv(5, 3);
    do_ldiv(5, 2);
    do_ldiv(7, 5);
    do_ldiv(-5, 2);
    do_ldiv(5, -2);

    return 0;
}
