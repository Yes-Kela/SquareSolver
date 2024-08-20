// Решатель квадратных уравнений.
// Пока считаем, что все введённые данные корректные, то есть являются числами.

#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>

void Enter (double * a, double * b, double * c);       // функция ввода
int LinearSolver (double b, double c, double * x);            // функция, выводящая решение линейного уравнения
void SquareSolver (double a, double b, double c);      // функция, выводящая решения квадратки

int main(void)
{
    printf("Эта программа умеет решать квадратное уравнение вида ax^2 + bx + c = 0.\n\n");

    double kf_a = 0, kf_b = 0, kf_c = 0;
    Enter (&kf_a, &kf_b, &kf_c);

    while (isdigit(kf_a) == 0 || isdigit(kf_b) == 0 || isdigit(kf_c) == 0)
    {
        printf("Некорректно введены данные. Введите ЧИСЛОВЫЕ значения коэффициентов снова.\n");
        Enter (&kf_a, &kf_b, &kf_c);
    }

    if (kf_a == 0)
    {
        printf("\nПри a = 0 квадратное уравнение преобразуется к линейному.\n");
        double root_x = 0;
        int count_Roots = LinearSolver(kf_b, kf_c, &root_x);
        switch (count_Roots)
        {
        case -1:
            printf("И, кстати, данное линейное уравнение имеет решениями всякое действительное число.\n");
            break;
        case 0:
            printf("И, кстати, данное линейное уравнение не имеет решений в действительных числах.\n");
            break;
        case 1:
            printf("И, кстати, данное линейное уравнение имеет единственное решение x = %g.\n", root_x);
            break;
        default:
            printf("main(): ERROR: count_Roots = %d", count_Roots);
            return 1;
        }
    }
    else
        SquareSolver(kf_a, kf_b, kf_c);

    return 0;
}


void Enter (double * a, double * b, double * c)
{
    printf("Введите значение коэффициента a: ");
    scanf("%lf", a);
    printf("Введите значение коэффициента b: ");
    scanf("%lf", b);
    printf("Введите значение коэффициента c: ");
    scanf("%lf", c);
}

int LinearSolver (double b, double c, double * x)
{
    if (b == 0 && c == 0)
        return -1;
    if (b == 0 and c != 0)
        return 0;
    else
        * x = - c / b;
        return 1;
}


void SquareSolver (double a, double b, double c)
{
    double common = -b / (2 * a);
    double discriminant = b*b - 4*a*c;

    if (discriminant < 0)
        printf("\nДанное квадратное уравнение решений в действительных числах не имеет.\n");
    else if (discriminant == 0)
        printf("\nДанное квадратное уравнение имеет единственное решение x = %g.\n", common);
    else
    {
        double sqrt_discrim_div_dbl_a = sqrt(discriminant) / (2*a);
        printf("\nДанное квадратное уравнение имеет два решения в действительных числах.\n");
        printf("Первое решение: х = %g.\n", common - sqrt_discrim_div_dbl_a);
        printf("Второе решение: x = %g.\n", common + sqrt_discrim_div_dbl_a);
    }
}




