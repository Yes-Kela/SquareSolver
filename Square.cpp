// Решатель квадратных уравнений.

#include <TXLib.h>
#include <stdio.h>
#include <math.h>

struct TEST
{
    int Test_count;
    double a, b, c;
    double x1_ideal, x2_ideal;
    int Roots_count_ideal;
};

int compare_double (double first, double second);
void MainInput (double* cf_a, double* cf_b, double* cf_c);
void Input (double* cf);
int EquationSolver (double a, double b, double c, double* x1, double* x2);
int Linear (double b, double c, double* x1);
int Square (double a, double b, double c, double* x1, double* x2);
void Output (double x1, double x2, int Roots_count);
int RunAllTests(TEST data);

int main(void)
{
    TEST test1 = {.Test_count = 1, .a = 1, .b = -12, .c = 35, .x1_ideal = 5, .x2_ideal = 7, .Roots_count_ideal = 2};
    printf("Эта программа умеет решать квадратное уравнение вида ax^2 + bx + c = 0.\n\n");
    /*
    double cf_a = 0, cf_b = 0, cf_c = 0;
    printf("Введите значения коэффициентов a, b и c в этом порядке.\n");
    MainInput(&cf_a, &cf_b, &cf_c);
    double x1 = 0, x2 = 0;
    int Roots_count = EquationSolver (cf_a, cf_b, cf_c, &x1, &x2);
    Output(x1, x2, Roots_count);
    */
    printf("# RunAllTests: Test 1: %d", RunAllTests(test1));
    return 0;
}

int compare_double (double first, double second)
{
    const double epsilon = 1e-12;
    if (fabs(first - second) < epsilon)
        return 1;
    else
        return 0;
}

void MainInput (double* cf_a, double* cf_b, double* cf_c)
{
    printf("Коэффициент a: ");
    Input(cf_a);
    printf("Коэффициент b: ");
    Input(cf_b);
    printf("Коэффийиент c: ");
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
    int a_is_0 = compare_double(a, 0);

    if (a_is_0)
        return Linear (b, c, x1);
    else
        return Square (a, b, c, x1, x2);
}

int Linear (double b, double c, double* x1)
{
    int  b_is_0 = compare_double(b, 0), c_is_0 = compare_double(c, 0);
    if (b_is_0 && c_is_0)
        return -1;
    else if (b_is_0 && !c_is_0)
        return 0;
    else
    {
        * x1 = -c / b;
        return 1;
    }
}

int Square (double a, double b, double c, double* x1, double* x2)
{
    double common = -b / (2*a);
    double discriminant = b*b - 4*a*c;

    if (discriminant < 0)
        return 0;
    else if (compare_double(discriminant, 0))
    {
        * x1 = common;
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


// Юнит-тестирование, передаланное:

int RunAllTests (TEST data)
{
    double x1, x2;
    int Roots_count = EquationSolver(data.a, data.b, data.c, &x1, &x2);
    if (Roots_count != data.Roots_count_ideal || !compare_double(x1, data.x1_ideal) || !compare_double(x2, data.x2_ideal))
        printf("# ERROR Test %d, a = %lg, b = %lg, c = %lg, Roots_count = %d, x1 = %lg, x2 = %lg\n"
               "Expected: x1 = %lg, x2 = %lg, Roots_count = %d\n",
                data.Test_count, data.a, data.b, data.c, Roots_count, x1, x2,
                data.x1_ideal, data.x2_ideal, data.Roots_count_ideal);
    return data.Test_count;
}

