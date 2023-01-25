#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void do_input_text(const char *fname)
{
    FILE *fin = fopen(fname, "r");
    if (fin)
    {
        int lineno;
        char buf[256];

        lineno = 1;
        while (fgets(buf, 256, fin))
        {
            printf("%03d: %s", lineno, buf);
            ++lineno;
        }

        printf("fseek(0, SEEK_SET): %d\n", fseek(fin, 0, SEEK_SET));

        lineno = 1;
        while (fgets(buf, 256, fin))
        {
            printf("%03d: %s", lineno, buf);
            ++lineno;
        }

        printf("fseek(10, SEEK_SET): %d\n", fseek(fin, 10, SEEK_SET));

        lineno = 1;
        while (fgets(buf, 256, fin))
        {
            printf("%03d: %s", lineno, buf);
            ++lineno;
        }

        printf("fseek(-5, SEEK_CUR): %d\n", fseek(fin, -5, SEEK_CUR));

        lineno = 1;
        while (fgets(buf, 256, fin))
        {
            printf("%03d: %s", lineno, buf);
            ++lineno;
        }

        printf("fseek(0, SEEK_END): %d\n", fseek(fin, 0, SEEK_END));

        lineno = 1;
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


int main(int argc, char **argv)
{
    do_output_text("test.txt");
    do_input_text("test.txt");
    remove("test.txt");
    return 0;
}
