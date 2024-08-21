// Решатель квадратных уравнений.

#include <TXLib.h>
#include <stdio.h>
#include <math.h>

int compare_double (double first, double second);
void Input (double* kf);
int EquationSolver (double a, double b, double c, double* x1, double* x2);
int Linear (double b, double c, double* x1);
int Square (double a, double b, double c, double* x1, double* x2);
void Output (double x1, double x2, int Roots_count);

int main(void)
{
    printf("Эта программа умеет решать квадратное уравнение вида ax^2 + bx + c = 0.\n\n");
    double cf_a = 0, cf_b = 0, cf_c = 0;
    printf("Введите значения коэффициентов a, b и c в этом порядке.\n");
    Input (&cf_a);
    Input (&cf_b);
    Input (&cf_c);
    double x1 = 0, x2 = 0;
    int Roots_count = EquationSolver (cf_a, cf_b, cf_c, &x1, &x2);
    Output(x1, x2, Roots_count);
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

void Input (double* cf)
{
    printf("Введите значение коэффициента: ");
    int returned_cf = scanf("%lf", cf);
    while (returned_cf != 1)
    {
        int ch = 0;
        while ((ch = getchar()) != '\n')
            printf("Введены некорректные данные.\nВведите значение коэффициента заново: ");
        returned_cf = scanf("%lf", cf);
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
        * x1 = -c / b;
        return 1;
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


