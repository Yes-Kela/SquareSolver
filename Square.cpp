// Решатель квадратных уравнений

#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#define SHOWTESTS

struct TEST
{
    int Test_count;
    double a, b, c;
    double x1_ideal, x2_ideal;
    int Roots_count_ideal;
};

int equal_double (double first, double second);
void MainInput (double* cf_a, double* cf_b, double* cf_c);
void Input (double* cf);
int EquationSolver (double a, double b, double c, double* x1, double* x2);
int Linear (double b, double c, double* x1, double* x2);
int Square (double a, double b, double c, double* x1, double* x2);
void Output (double x1, double x2, int Roots_count);
void RunAllTests (TEST test[], int nTests);
void RunTest (TEST data);


int main(void)
{
    const int nTests = 7;
    TEST test[nTests] =
    {
    {.Test_count = 1, .a = 1,      .b = -12,    .c = 35,     .x1_ideal = 5,      .x2_ideal = 7,  .Roots_count_ideal = 2},
    {.Test_count = 2, .a = 5,      .b = 9,      .c = -14,    .x1_ideal = -2.8,   .x2_ideal = 1,  .Roots_count_ideal = 2},
    {.Test_count = 3, .a = 0,      .b = 0,      .c = 0,      .x1_ideal = 0,      .x2_ideal = 0,  .Roots_count_ideal = -1},
    {.Test_count = 4, .a = 1,      .b = 0,      .c = 5,      .x1_ideal = 0,      .x2_ideal = 0,  .Roots_count_ideal = 0},
    {.Test_count = 5, .a = 0,      .b = 2,      .c = -6,     .x1_ideal = 3,      .x2_ideal = 3,  .Roots_count_ideal = 1},
    {.Test_count = 6, .a = 0.0001, .b = 1.2345, .c = 1.2344, .x1_ideal = -12344, .x2_ideal = -1, .Roots_count_ideal = 2},
    {.Test_count = 7, .a = 0.05,   .b = 0.09,   .c = -0.14,  .x1_ideal = -2.8,   .x2_ideal = 1,  .Roots_count_ideal = 2}
    };

    printf("Эта программа умеет решать квадратное уравнение вида ax^2 + bx + c = 0.\n\n");
    double cf_a = 0, cf_b = 0, cf_c = 0;
    printf("Введите значения коэффициентов a, b и c в этом порядке.\n");
    MainInput(&cf_a, &cf_b, &cf_c);
    double x1 = 0, x2 = 0;
    int Roots_count = EquationSolver (cf_a, cf_b, cf_c, &x1, &x2);
    Output(x1, x2, Roots_count);

    #ifdef SHOWTESTS
        RunAllTests(test, nTests);
    #endif

    return 0;
}

int equal_double (double first, double second)
{
    const double epsilon = 1e-5;
    return (fabs(first - second) < epsilon);
}

void MainInput (double* cf_a, double* cf_b, double* cf_c)
{
    printf("Коэффициент a: ");
    Input(cf_a);
    printf("Коэффициент b: ");
    Input(cf_b);
    printf("Коэффициент c: ");
    Input(cf_c);
}

void Input (double* cf)
{
    int ch = 0;

    while (scanf("%lf", cf) != 1 || (ch = getchar()) != '\n')
    {
        while ((ch = getchar()) != '\n'){ ; }
        printf("Введены некорректные данные.\nВведите значение коэффициента заново: ");
    }
}

int EquationSolver (double a, double b, double c, double* x1, double* x2)
{
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
        return -1;
    else if (b_is_0 && !c_is_0)
        return 0;
    else
    {
        * x1 = * x2 = -c / b;
        return 1;
    }
}

int Square (double a, double b, double c, double* x1, double* x2)
{
    double common = -b / (2*a);
    double discriminant = b*b - 4*a*c;

    if (discriminant < 0)
        return 0;
    else if (equal_double(discriminant, 0))
    {
        * x1 = * x2 = common;
        return 1;
    }
    else
    {
        double sqrt_discr_div_2a = sqrt(discriminant) / (2*a);
        * x1 = common - sqrt_discr_div_2a;
        * x2 = common + sqrt_discr_div_2a;
        return 2;
    }
}

void Output (double x1, double x2, int Roots_count)
{
    switch(Roots_count)
    {
        case -1:
            printf("Решением данного уравнения является любое действительное число.\n");
            break;
        case 0:
            printf("Данное уравнение корней не имеет.\n");
            break;
        case 1:
            printf("Данное уравнение имеет единственный корень х = %lg.\n", x1);
            break;
        case 2:
            printf("Данное уравнение имеет два решения в действительных числах:\n"
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

    if (Roots_count != data.Roots_count_ideal || !equal_double(x1, data.x1_ideal) || !equal_double(x2, data.x2_ideal))
        printf("# ERROR: Test %d: a = %lg, b = %lg, c = %lg, Roots_count = %d, x1 = %lg, x2 = %lg\n"
               "  Expected: Roots_count = %d, x1 = %lg, x2 = %lg\n",
                data.Test_count, data.a, data.b, data.c, Roots_count, x1, x2,
                data.Roots_count_ideal, data.x1_ideal, data.x2_ideal);
    else
        printf("# SUCCESS: Test %d: a = %lg, b = %lg, c = %lg, Roots_count = %d, x1 = %lg, x2 = %lg\n",
                data.Test_count, data.a, data.b, data.c, Roots_count, x1, x2);

    //return data.Test_count;
}


void RunAllTests (TEST test[], int nTests)
{
    for (int i = 0; i < nTests; i++)
        RunTest (test[i]);
}
