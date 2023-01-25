#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define _USE_MATH_DEFINES // for M_PI
#include <math.h> //

void do_exp(double x)
{
    printf("exp(%f) == %f\n", x, exp(x));
}

void do_log(double x)
{
    printf("log(%f) == %f\n", x, log(x));
}

void do_log10(double x)
{
    printf("log10(%f) == %f\n", x, log10(x));
}

void do_pow(double x, double y)
{
    printf("pow(%f, %f) == %f\n", x, y, pow(x, y));
}

void do_fabs(double x)
{
    printf("fabs(%f) == %f\n", x, fabs(x));
}

void do_fmod(double x, double y)
{
    printf("fmod(%f, %f) == %f\n", x, y, fmod(x, y));
}

void do_floor_ceil(double x)
{
    printf("floor(%f) == %f\n", x, floor(x));
    printf("ceil(%f) == %f\n", x, ceil(x));
}

void do_sqrt(double x)
{
    printf("sqrt(%f) == %f\n", x, sqrt(x));
}

void do_sin_cos_tan(double x)
{
    printf("sin(%f) == %f\n", x, sin(x));
    printf("cos(%f) == %f\n", x, cos(x));
    printf("tan(%f) == %f\n", x, tan(x));
}

void do_atan2(double y, double x)
{
    printf("atan2(%f, %f) == %f\n", y, x, atan2(y, x));
}

int main(int argc, char **argv)
{
    do_exp(0);
    do_exp(1);
    do_exp(2);
    do_exp(-2);

    do_log(0);
    do_log(1);
    do_log(2);

    do_log10(0);
    do_log10(10);
    do_log10(0.1);

    do_pow(0, 1);
    do_pow(1, 0);
    do_pow(2, 3);
    do_pow(2, -1);

    do_fabs(0);
    do_fabs(1);
    do_fabs(2);
    do_fabs(-2);

    do_fmod(0, 1);
    do_fmod(5, 2);
    do_fmod(5, 3);
    do_fmod(5, -2);
    do_fmod(-5, -3);
    do_fmod(-5, 2);

    do_floor_ceil(0.5);
    do_floor_ceil(0.6);
    do_floor_ceil(3);
    do_floor_ceil(3.2);
    do_floor_ceil(-2.6);
    do_floor_ceil(-4.2);

    do_sqrt(16);
    do_sqrt(256);
    do_sqrt(5);

#ifndef M_PI
    #define M_PI 3.1415626536
#endif
    do_sin_cos_tan(0);
    do_sin_cos_tan(M_PI);
    do_sin_cos_tan(-M_PI);
    do_sin_cos_tan(M_PI / 2);

    do_atan2(1, 0);
    do_atan2(0, 1);
    do_atan2(1, 1);

    return 0;
}
