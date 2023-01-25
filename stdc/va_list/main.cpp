#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h> //

int add_nums(int count, ...) 
{
    int result = 0;
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; ++i)
    {
        result += va_arg(args, int);
    }
    va_end(args);
    return result;
}

void test_1(void)
{
    int num;

    num = add_nums(1, 999);
    printf("num: %d\n", num);

    num = add_nums(2, 1, 2);
    printf("num: %d\n", num);

    num = add_nums(3, 1, 2, -5);
    printf("num: %d\n", num);
}

int main(int argc, char **argv)
{
    test_1();

    return 0;
}
