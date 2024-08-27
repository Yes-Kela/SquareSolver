// Calculating file "compute.cpp"

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include "compute.h"

int equal_double (double first, double second)
{
    const double epsilon = 1e-5;
    return (fabs(first - second) < epsilon);
}

int EquationSolver (double a, double b, double c, double* x1, double* x2)
{
    assert (x1 != NULL);
    assert (x2 != NULL);

    int a_is_0 = equal_double(a, 0);
    if (a_is_0)
        return Linear (b, c, x1, x2);
    else
        return Square (a, b, c, x1, x2);
}

int Linear (double b, double c, double* x1, double* x2)
{
    int  b_is_0 = equal_double(b, 0), c_is_0 = equal_double(c, 0);
    if (b_is_0 && c_is_0)
    {
        * x1 = * x2 = NAN;
        return INF_ROOTS;
    }
    else if (b_is_0 && !c_is_0)
    {
        * x1 = * x2 = NAN;
        return NO_ROOTS;
    }
    else
    {
        * x1 = -c / b;
        * x2 = NAN;
        return ONE_ROOT;
    }
}

int Square (double a, double b, double c, double* x1, double* x2)
{
    double common = -b / (2*a);
    double discriminant = b*b - 4*a*c;
    assert (x1 != NULL);
    assert (x2 != NULL);
    if (discriminant < 0)
    {
        * x1 = * x2 =  NAN;
        return NO_ROOTS;
    }
    else if (equal_double(discriminant, 0))
    {
        * x1 = common;
        * x2 = NAN;
        return ONE_ROOT;
    }
    else
    {
        double sqrt_discr_div_2a = sqrt(discriminant) / (2*a);
        * x1 = common - sqrt_discr_div_2a;
        * x2 = common + sqrt_discr_div_2a;
        return TWO_ROOTS;
    }
}
