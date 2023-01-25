#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void execute_atexit(void)
{
    printf("death agony\n");
}

int main(int argc, char **argv)
{
    atexit(execute_atexit);
    printf("This program will be finished\n");
    return 0;
}
