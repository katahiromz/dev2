#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    char input[] = "The quick brown fox jumps over the lazy dog.";
    printf("Parsing the input string '%s'\n", input);

    const char *separators = " ,.-";
    char *token = strtok(input, separators);
    while (token)
    {
        printf("Word '%s'\n", token);
        token = strtok(NULL, separators);
    }

    return 0;
}
