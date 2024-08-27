// File that is responsible for interaction with console "usecmd.cpp"

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include "usecmd.h"

void ShowSyntax (char arg0[])
{
    printf("Syntax: \n\t%s --solve for solving quadratic equation"
           "\n\t%s --test  for running tests\n", arg0, arg0);
}

void basic_solving (void)
{
    printf("This program can solve quadratic equation of the form ax^2 + bx + c = 0.\n\n");
    double cf_a = 0, cf_b = 0, cf_c = 0;
    printf("Enter the values of the coefficients a, b and c.\n");
    MainInput(&cf_a, &cf_b, &cf_c);
    double x1 = 0, x2 = 0;
    int Roots_count = EquationSolver (cf_a, cf_b, cf_c, &x1, &x2);
    Output(x1, x2, Roots_count);
}

void ShowIncorrect(char arg0[])
{
    printf("Unknown parameter: '%s'.\n"
           "Type %s --solve for solving quadratic equation.\n"
           "type %s --test  for running tests.\n", arg0, arg0, arg0);
}
