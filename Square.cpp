// Решатель квадратных уравнений.

#include <TXLib.h>
#include <stdio.h>
#include <math.h>

void Input (double * a, double * b, double * c, int * returned_a, int * returned_b, int * returned_c);
void Interaction (double * a, double * b, double * c);
int EquationSolver (double a, double b, double c, double * x1, double * x2);
int compare_double (double first, double second);
void Output (double x1, double x2, int Roots_count);

int main(void)
{
    printf("Эта программа умеет решать квадратное уравнение вида ax^2 + bx + c = 0.\n\n");
    double kf_a = 0, kf_b = 0, kf_c = 0;
    Interaction (&kf_a, &kf_b, &kf_c);
    double x1 = 0, x2 = 0;
    int Roots_count = EquationSolver (kf_a, kf_b, kf_c, &x1, &x2);
    Output(x1, x2, Roots_count);
    return 0;
}


void Input (double * a, double * b, double * c, int * returned_a, int * returned_b, int * returned_c)
{
    printf("Введите значение коэффициента a: ");
    * returned_a = scanf("%lf", a);
    printf("Введите значение коэффициента b: ");
    * returned_b = scanf("%lf", b);
    printf("Введите значение коэффициента c: ");
    * returned_c = scanf("%lf", c);
}

int compare_double (double first, double second)
{
    const double epsilon = 1e-12;
    if (fabs(first - second) < epsilon)
        return 1;
    else
        return 0;
}

int EquationSolver(double a, double b, double c, double * x1, double * x2)
{
    int a_is_0 = compare_double(a, 0), b_is_0 = compare_double(b, 0), c_is_0 = compare_double(c, 0);

    if (a_is_0)
    {
        if (b_is_0 && c_is_0)
            return -1;
        else if (b_is_0 && (c_is_0 == 0))
            return 0;
        else
        {
            * x1 = -c / b;
            return 1;
        }
    }
    else
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

}

void Interaction(double * a, double * b, double * c)
{
    int returned_a = 0, returned_b = 0, returned_c = 0;
    Input (a, b, c, &returned_a, &returned_b, &returned_c);
    while (returned_a != 1 || returned_b != 1 || returned_c != 1)
    {
        printf("Введены некорректные данные. Введите значения коэффициентов заново.\n");
        Input(a, b, c, &returned_a, &returned_b, &returned_c);
    }
}

void Output(double x1, double x2, int Roots_count)
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

