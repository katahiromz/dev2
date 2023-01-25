#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    fclose(fopen("test.txt", "w"));
    printf("rename: %d\n", rename("test.txt", "test2.txt"));
    remove("test2.txt");
    printf("rename: %d\n", rename("test.txt", "test2.txt"));
    return 0;
}
