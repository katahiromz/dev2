#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h> //

char do_tolower(char ch)
{
    char ret = tolower(ch);
    char buf1[] = { ' ', '(', ch, ')', 0 };
    char buf2[] = { ' ', '(', ret, ')', 0 };
    if (!isprint(ch)) buf1[0] = 0;
    if (!isprint(ret)) buf2[0] = 0;
    
    printf("tolower(%d (0x%02X)%s) == %d (0x%02X)%s\n", ch, ch, buf1, ret, ret, buf2);
    return ret;
}

int main(int argc, char **argv)
{
    do_tolower('A');
    do_tolower('a');
    do_tolower('1');
    return 0;
}
