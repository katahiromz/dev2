#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    const char* str = "hello world, friend of mine!";
    const char* sep = " ,!";
 
    unsigned int cnt = 0;
    do {
       str = strpbrk(str, sep); // find separator
       if(str) str += strspn(str, sep); // skip separator
       ++cnt; // increment word count
    } while(str && *str);
 
    printf("There are %d words\n", cnt);

    return 0;
}
