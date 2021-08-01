#include <stdio.h>
#include <stdlib.h>
#include "sindeg.h"
int main()
{
    double x, y;
    x = 60.0;
    y = sindeg(x);
    printf("angle = %f degree, sin(angle) = %f\n", x, y);
    exit(0);
}
