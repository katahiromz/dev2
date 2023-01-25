#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef _countof
    #define _countof(array) (sizeof(array) / sizeof(array[0]))
#endif

int compare_ch(const void *x, const void *y)
{
    const char *a = (const char *)x;
    const char *b = (const char *)y;
    if (*a < *b)
        return -1;
    if (*a > *b)
        return 1;
    return 0;
}

int compare_int(const void *x, const void *y)
{
    const int *a = (const int *)x;
    const int *b = (const int *)y;
    if (*a < *b)
        return -1;
    if (*a > *b)
        return 1;
    return 0;
}

void test_1(void)
{
    char buf[] = "123a5j23l4k23j42j34k";
    size_t len = strlen(buf);

    printf("buf: %s\n", buf);
    qsort(buf, len, sizeof(char), compare_ch);
    printf("buf: %s\n", buf);
}

void test_2(void)
{
    int data[] = { 3, 2, 5, 1, 4 };

    printf("data: ");
    for (int i = 0; i < _countof(data); ++i) printf(" %d", data[i]);
    printf("\n");

    qsort(data, _countof(data), sizeof(data[0]), compare_int);

    printf("data: ");
    for (int i = 0; i < _countof(data); ++i) printf(" %d", data[i]);
    printf("\n");
}

int main(int argc, char **argv)
{
    test_1();
    test_2();

    return 0;
}
