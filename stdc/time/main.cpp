#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h> //

int main(int argc, char **argv)
{
    time_t now = time(NULL);

    struct tm *gm = gmtime(&now);
    printf("gmtime: %04d-%02d-%02d %02d:%02d:%02d\n",
        gm->tm_year,
        gm->tm_mon + 1,
        gm->tm_mday,
        gm->tm_hour,
        gm->tm_min,
        gm->tm_sec
    );

    struct tm *local = localtime(&now);
    printf("localtime: %04d-%02d-%02d %02d:%02d:%02d\n",
        local->tm_year,
        local->tm_mon + 1,
        local->tm_mday,
        local->tm_hour,
        local->tm_min,
        local->tm_sec
    );

    char *asc = asctime(local);
    printf("asctime: %s\n", asc);

    asc = ctime(&now);
    printf("ctime: %s\n", asc);

    time_t t1 = mktime(local);
    printf("mktime: %lld\n", (long long)t1);

    local->tm_hour += 1;
    time_t t2 = mktime(local);
    printf("mktime: %lld\n", (long long)t2);

    double diff = difftime(t1, t2);
    printf("difftime: %f\n", diff);

    return 0;
}
