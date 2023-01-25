#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

size_t do_strftime(char *s, size_t smax, const char *fmt, const struct tm *tp)
{
    size_t ret;
    ret = strftime(s, smax, fmt, tp);
    printf("strftime('%s') = '%s'\n", fmt, s);
    return ret;
}

int main(int argc, char **argv)
{
    time_t now = time(NULL);
    struct tm *ptm = localtime(&now);

    char buf[256];
    do_strftime(buf, 256, "<%x>", ptm);
    do_strftime(buf, 256, "(%X)", ptm);
    do_strftime(buf, 256, "%Y-%m-%d", ptm);
    do_strftime(buf, 256, "%Y-%m-%d %H:%M:%S", ptm);
    do_strftime(buf, 256, "%H h %M m %S s", ptm);
    return 0;
}
