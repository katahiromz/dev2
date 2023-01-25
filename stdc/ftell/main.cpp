#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void do_input_binary(const char *fname)
{
    FILE *fin = fopen(fname, "rb");
    if (fin)
    {
        int lineno;
        char buf[256];

        fseek(fin, 0, SEEK_END);
        long file_size = ftell(fin);

        printf("ftell: %ld\n", file_size);

        fseek(fin, 0, SEEK_SET);

        char *ptr = (char*)calloc(file_size + 1, 1);
        if (ptr)
        {
            fread(ptr, file_size, 1, fin);
            fputs(ptr, stdout);

            free(ptr);
        }

        fclose(fin);
    }
}

void do_output_text(const char *fname)
{
    FILE *fout = fopen(fname, "w");
    if (fout)
    {
        fprintf(fout, "This is a test.\n");
        fprintf(fout, "Ok, ok.\n");

        fclose(fout);
    }
}

int main(int argc, char **argv)
{
    do_output_text("test.txt");
    do_input_binary("test.txt");
    remove("test.txt");
    return 0;
}
