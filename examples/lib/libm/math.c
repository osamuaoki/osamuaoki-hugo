#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double
sindeg(double x)
{
    return sin(x * 3.141592 / 180.0);
}

int
main()
{
    double x, y;
    x = 60.0;
    y = sindeg(x);
    printf("angle = %f degree, sin(angle) = %f\n", x, y);
    exit(0);
}
