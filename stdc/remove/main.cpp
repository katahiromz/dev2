#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    fclose(fopen("test.txt", "w"));
    printf("remove: %d\n", remove("test.txt"));
    printf("remove: %d\n", remove("test.txt"));
    return 0;
}
