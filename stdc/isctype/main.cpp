#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h> // is...

void do_it(char ch)
{
    char buf[] = { ' ', '(', ch, ')', 0 };
    if (!isprint(ch))
        buf[0] = 0;
    printf("0x%02X (%d)%s:\n", ch, ch, buf);
#define DO_IT(what) printf(" %s:%d", #what, what(ch))
    DO_IT(isalpha);
    DO_IT(isupper);
    DO_IT(islower);
    DO_IT(isdigit);
    DO_IT(isspace);
    DO_IT(isalnum);
    DO_IT(iscntrl);
    DO_IT(isgraph);
    DO_IT(isprint);
    DO_IT(ispunct);
    DO_IT(isxdigit);
    DO_IT(isascii);
    DO_IT(iscsymf);
    DO_IT(iscsym);
#undef DO_IT
    printf("\n\n");
}

int main(int argc, char **argv)
{
    const char *defstr = "Test.";
    const char *ptr = ((argc == 2) ? argv[1] : defstr);

    do_it(' ');
    do_it('"');

    for (int i = 0; ptr[i]; ++i)
    {
        char ch = ptr[i];
        do_it(ch);
    }

    return 0;
}
