#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct tagSTRUCT
{
    int a;
    int b;
} STRUCT, *PSTRUCT;

int struct_test(PSTRUCT pst)
{
    return pst->b;
}

int main(int argc, char **argv)
{
    STRUCT st;
    st.a = 3;
    st.b = 4;
    st.a = struct_test(&st) + 1;
    printf("st.a: %d\n", st.a);
    printf("st.b: %d\n", st.b);
    return 0;
}
