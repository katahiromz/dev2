#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    const char *string = "abcde312$#@";
    size_t spnsz = strspn(string, "abcdefghijklmnopqrstuvwxyz");
    printf("After skipping initial lowercase letters from '%s'\n"
           "The remainder is '%s'\n", string, string + spnsz);
    return 0;
}
