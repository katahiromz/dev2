#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h> // ERANGE

int main(int argc, char **argv)
{
    // parsing with error handling
    const char *p = "10 200000000000000000000000000000 30 -40 junk";
    printf("Parsing '%s':\n", p);

    char *end;
    for (long i = strtol(p, &end, 10); p != end; i = strtol(p, &end, 10))
    {
        printf("'%.*s' -> ", (int)(end-p), p);
        p = end;
        if (errno == ERANGE)
        {
            printf("range error, got ");
        }
        printf("%ld\n", i);
    }
 
    // parsing without error handling
    printf("\"1010\" in binary  --> %ld\n", strtol("1010", NULL, 2));
    printf("\"12\" in octal     --> %ld\n", strtol("12", NULL, 8));
    printf("\"A\"  in hex       --> %ld\n", strtol("A", NULL, 16));
    printf("\"junk\" in base-36 --> %ld\n", strtol("junk", NULL, 36));
    printf("\"012\" in auto-detected base  --> %ld\n", strtol("012", NULL, 0));
    printf("\"0xA\" in auto-detected base  --> %ld\n", strtol("0xA", NULL, 0));
    printf("\"junk\" in auto-detected base -->  %ld\n", strtol("junk", NULL, 0));

    return 0;
}
