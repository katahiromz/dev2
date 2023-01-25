#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <setjmp.h> //

jmp_buf env;

int val(char **s)
{
    if (!isdigit(**s))
    {
        fprintf(stderr, "missing number\n");
        longjmp(env, 1);
    }
    return (strtol(*s, s, 10));
}

int bar(char *s)
{
    int v = val(&s);
    switch (*s++)
    {
    case '+': return (v + val(&s));
    case '-': return (v - val(&s));
    case '*': return (v * val(&s));
    case '/': return (v / val(&s));
    default:
        fprintf(stderr, "illegal operation\n");
        longjmp(env, 1);
    }
}

int main(int argc, char **argv)
{
    char line[80];

    for (;;)
    {
        printf("Enter a simple expression ('q' to quit): ");
        fgets(line, 80, stdin);
        if (strstr(line, "q"))
            break;
        if (setjmp(env) == 0)
            printf("%d\n", bar(line));
    }
    return 0;
}
