// Solver quadratic equation

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>

struct TEST
{
    int Test_count;
    double a, b, c;
    double x1_ideal, x2_ideal;
    int Roots_count_ideal;
};

enum solutions {INF_ROOTS = -1, NO_ROOTS, ONE_ROOT, TWO_ROOTS};

int equal_double (double first, double second);
void MainInput (double* cf_a, double* cf_b, double* cf_c);
void Input (double* cf);
int EquationSolver (double a, double b, double c, double* x1, double* x2);
int Linear (double b, double c, double* x1, double* x2);
int Square (double a, double b, double c, double* x1, double* x2);
void Output (double x1, double x2, int Roots_count);
void RunAllTests (TEST test[], int nTests);
void RunTest (TEST data);
void ShowError (TEST data, double x1, double x2, int Roots_count);
void ShowSuccess (TEST data, double x1, double x2, int Roots_count);

void ShowSyntax (char arg0[]);
void basic_solving (void);
void ShowIncorrect (char arg0[], char arg1[]);

int main(int argc, char* argv[])
{
    const int nTests = 10;
    TEST test[nTests] =
    {
    {.Test_count = 1,  .a = 1,      .b = -12,    .c = 35,     .x1_ideal = 5,              .x2_ideal = 7,      .Roots_count_ideal = 2},
    {.Test_count = 2,  .a = 5,      .b = 9,      .c = -14,    .x1_ideal = -2.8,           .x2_ideal = 1,      .Roots_count_ideal = 2},
    {.Test_count = 3,  .a = 0,      .b = 0,      .c = 0,      .x1_ideal = NAN,            .x2_ideal = NAN,    .Roots_count_ideal = -1},
    {.Test_count = 4,  .a = 1,      .b = 0,      .c = 5,      .x1_ideal = NAN,            .x2_ideal = NAN,    .Roots_count_ideal = 0},
    {.Test_count = 5,  .a = 0,      .b = 2,      .c = -6,     .x1_ideal = 3,              .x2_ideal = NAN,    .Roots_count_ideal = 1},
    {.Test_count = 6,  .a = 0.0001, .b = 1.2345, .c = 1.2344, .x1_ideal = -12344,         .x2_ideal = -1,     .Roots_count_ideal = 2},
    {.Test_count = 7,  .a = 0.05,   .b = 0.09,   .c = -0.14,  .x1_ideal = -2.8,           .x2_ideal = 1,      .Roots_count_ideal = 2},
    {.Test_count = 8,  .a = -15,    .b = 0,      .c = -2,     .x1_ideal = NAN,            .x2_ideal = NAN,    .Roots_count_ideal = 0},
    {.Test_count = 9,  .a = 3,      .b = 4,      .c = -4,     .x1_ideal = -2,             .x2_ideal = 2.0/3,  .Roots_count_ideal = 2},
    {.Test_count = 10, .a = 3.44,   .b = 1008,   .c = 0,      .x1_ideal = -1008.0/3.44,   .x2_ideal = 0,      .Roots_count_ideal = 2}
    };

    if (argc <= 1)
        ShowSyntax(argv[0]);
    else if (!strcmp(argv[1], "--solve"))
        basic_solving();
    else if (!strcmp(argv[1], "--test"))
    {
        printf("\n");
        RunAllTests(test, nTests);
    }
    else
        ShowIncorrect(argv[0], argv[1]);

    return 0;
}

int equal_double (double first, double second)
{
    const double epsilon = 1e-5;
    return (fabs(first - second) < epsilon);
}

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
            printf("This equation has only one solution in real numbers: х = %lg.\n", x1);
            break;
        case TWO_ROOTS:
            printf("This equation has two solutions in real numbers:\n"
                   "x1 = %lg\n" "x2 = %lg\n", x1, x2);
            break;
        default:
            printf("# ERROR: Roots_count = %d\n", Roots_count);
    }
}


// Юнит-тестирование

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

void ShowIncorrect(char arg0[], char arg1[])
{
    printf("Unknown parameter: '%s'.\n"
           "Type %s --solve for solving quadratic equation.\n"
           "type %s --test  for running tests.\n", arg1, arg0);
}
