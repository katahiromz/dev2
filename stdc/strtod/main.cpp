#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h> // ERANGE

int main(int argc, char **argv)
{
    // parsing with error handling
    const char *ptr = "111.11 -2.22 Nan nan(2) inF 0X1.BC70A3D70A3D7P+6  1.18973e+4932zzz";
    printf("Parsing '%s':\n", ptr);
    char *end;

    for (double f = strtod(ptr, &end); ptr != end; f = strtod(ptr, &end))
    {
        printf("'%.*s' -> ", (int)(end - ptr), ptr);
        ptr = end;
        if (errno == ERANGE)
        {
            printf("range error, got ");
        }
        printf("%f\n", f);
    }
 
    // parsing without error handling
    printf("\"  -0.0000000123junk\"  -->  %g\n", strtod("  -0.0000000123junk", NULL));
    printf("\"junk\"                 -->  %g\n", strtod("junk", NULL));

    return 0;
}
