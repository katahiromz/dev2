#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void do_input_text(const char *fname)
{
    FILE *fin = fopen(fname, "r");
    if (fin)
    {
        int lineno = 1;
        char buf[256];
        while (fgets(buf, 256, fin))
        {
            printf("%03d: %s", lineno, buf);
            ++lineno;
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

void do_append_text(const char *fname)
{
    FILE *fout = fopen(fname, "a");
    if (fout)
    {
        fprintf(fout, "This is appendant\n");

        fclose(fout);
    }
}

void do_input_binary(const char *fname)
{
    FILE *fin = fopen(fname, "rb");
    if (fin)
    {
        printf("feof: %d\n", feof(fin));

        char buf[256];
        size_t cb = fread(buf, 1, 256, fin);

        for (size_t i = 0; i < cb; ++i)
        {
            printf(" 0x%02X (%c)", buf[i], (isprint(buf[i]) ? buf[i] : '.'));
        }
        printf("\n");

        printf("feof: %d\n", feof(fin));

        fclose(fin);
    }
}

void do_output_binary(const char *fname)
{
    FILE *fout = fopen(fname, "wb");
    if (fout)
    {
        char buf[] = { 0x11, 0x22, 0x33, 0x44, 0x55 };
        fwrite(buf, sizeof(buf), 1, fout);

        fclose(fout);
    }
}

int main(int argc, char **argv)
{
    do_output_text("test.txt");
    do_append_text("test.txt");
    do_input_text("test.txt");
    do_input_binary("test.txt");
    do_output_binary("test.txt");
    do_input_binary("test.txt");
    remove("test.txt");
    return 0;
}
