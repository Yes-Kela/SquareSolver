// Module of processing input data "inproc.cpp"

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "inproc.h"

void MainInput (double* cf_a, double* cf_b, double* cf_c)
{
    assert (cf_a != NULL);
    assert (cf_b != NULL);
    assert (cf_c != NULL);

    printf("Coefficient a (press <Enter> after inputting a number): ");
    Input(cf_a);
    printf("Coefficient b (press <Enter> after inputting a number): ");
    Input(cf_b);
    printf("Coefficient c (press <Enter> after inputting a number): ");
    Input(cf_c);
}

void Input (double* cf)
{
    int ch = 0;
    int returned_cf = scanf("%lf", cf);
    assert (* cf != NAN);
    while (returned_cf != 1 || (ch = getchar()) != '\n')
    {
        while ((ch = getchar()) != '\n'){ ; }
        printf("\nIncorrect data has been entered (perhaps, you used gap or other unacceptable characters)."
               "\nEnter it again: ");
        returned_cf = scanf("%lf", cf);
    }
}
