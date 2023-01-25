#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h> // ERANGE

int main(int argc, char **argv)
{
    const char *p = "10 200000000000000000000000000000 30 -40";
    printf("Parsing '%s':\n", p);

    char *end;
    for (unsigned long i = strtoul(p, &end, 10); p != end; i = strtoul(p, &end, 10))
    {
        printf("'%.*s' -> ", (int)(end-p), p);
        p = end;
        if (errno == ERANGE)
        {
            printf("range error, got ");
        }
        printf("%lu\n", i);
    }

    return 0;
}
