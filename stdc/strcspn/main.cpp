#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    const char *string = "abcde312$#@";
    const char *invalid = "*$#";
 
    size_t valid_len = strcspn(string, invalid);
    if (valid_len != strlen(string))
    {
        printf("'%s' contains invalid chars starting at position %zu\n",
               string, valid_len);
    }
    return 0;
}
