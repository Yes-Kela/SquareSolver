// Output file "out.cpp"

#include <stdio.h>
#include "out.h"

void Output (double x1, double x2, int Roots_count)
{
    printf("\n");
    switch(Roots_count)
    {
        case INF_ROOTS:
            printf("Any real number is the solution to this equation.\n");
            break;
        case NO_ROOTS:
            printf("This equation has no solutions in real numbers.\n");
            break;
        case ONE_ROOT:
            printf("This equation has only one solution in real numbers: õ = %lg.\n", x1);
            break;
        case TWO_ROOTS:
            printf("This equation has two solutions in real numbers:\n"
                   "x1 = %lg\n" "x2 = %lg\n", x1, x2);
            break;
        default:
            printf("# ERROR: Roots_count = %d\n", Roots_count);
    }
}
