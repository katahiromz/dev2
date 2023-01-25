#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef _countof
    #define _countof(array) (sizeof(array) / sizeof(array[0]))
#endif

typedef struct tagSTRUCT
{
    int key;
    int value;
} STRUCT, *PSTRUCT;

int compare(const void *x, const void *y)
{
    const STRUCT *a = (const STRUCT *)x;
    const STRUCT *b = (const STRUCT *)y;
    if (a->key < b->key)
        return -1;
    if (a->key > b->key)
        return 1;
    return 0;
}

STRUCT array[] =
{
    { 3, 17 },
    { 4, 25 },
    { 6, 1 },
    { 8, 13 },
    { 10, 5 },
}; // this must be sorted by key

int main(int argc, char **argv)
{
    PSTRUCT found;

    STRUCT key = { 6 };
    found = (PSTRUCT)bsearch(&key, array, _countof(array), sizeof(STRUCT), compare);
    if (found)
    {
        printf("found: %d\n", found->value);
    }
    else
    {
        printf("not found\n");
    }

    key.key = 3;
    found = (PSTRUCT)bsearch(&key, array, _countof(array), sizeof(STRUCT), compare);
    if (found)
    {
        printf("found: %d\n", found->value);
    }
    else
    {
        printf("not found\n");
    }

    return 0;
}
