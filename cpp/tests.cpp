// Unit-testing file "tests.cpp"

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include "tests.h"

void RunTest (TEST data)
{
    double x1 = 0, x2 = 0;
    int Roots_count = EquationSolver(data.a, data.b, data.c, &x1, &x2);
    int coincidence_Roots_count = (Roots_count == data.Roots_count_ideal);
    int coincidence_x1 = ((isnan(x1) && isnan(data.x1_ideal)) || equal_double (x1, data.x1_ideal));
    int coincidence_x2 = ((isnan(x2) && isnan(data.x2_ideal)) || equal_double (x2, data.x2_ideal));

    if (coincidence_Roots_count && coincidence_x1 && coincidence_x2)
        ShowSuccess(data, x1, x2, Roots_count);
    else
        ShowError(data, x1, x2, Roots_count);
}

void RunAllTests (TEST test[], int nTests)
{
    for (int i = 0; i < nTests; i++)
        RunTest (test[i]);
}


void ShowSuccess (TEST data, double x1, double x2, int Roots_count)
{
    printf("# SUCCESS: Test %d: a = %lg, b = %lg, c = %lg, Roots_count = %d, x1 = %lg, x2 = %lg\n",
            data.Test_count, data.a, data.b, data.c, Roots_count, x1, x2);
}

void ShowError (TEST data, double x1, double x2, int Roots_count)
{
    printf("# ERROR: Test %d: a = %lg, b = %lg, c = %lg, Roots_count = %d, x1 = %lg, x2 = %lg\n"
           "  Expected: Roots_count = %d, x1 = %lg, x2 = %lg\n",
            data.Test_count, data.a, data.b, data.c, Roots_count, x1, x2,
            data.Roots_count_ideal, data.x1_ideal, data.x2_ideal);
}
