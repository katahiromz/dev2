#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h> //

char do_toupper(char ch)
{
    char ret = toupper(ch);
    char buf1[] = { ' ', '(', ch, ')', 0 };
    char buf2[] = { ' ', '(', ret, ')', 0 };
    if (!isprint(ch)) buf1[0] = 0;
    if (!isprint(ret)) buf2[0] = 0;
    
    printf("toupper(%d (0x%02X)%s) == %d (0x%02X)%s\n", ch, ch, buf1, ret, ret, buf2);
    return ret;
}

int main(int argc, char **argv)
{
    do_toupper('a');
    do_toupper('A');
    do_toupper('1');
    return 0;
}
