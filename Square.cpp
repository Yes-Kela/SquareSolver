// Решатель квадратных уравнений
// Пока считаем, что все введённые данные корректные, то есть являются числами

#include <TXLib.h>
#include <stdio.h>
#include <math.h>

void Enter(double * a, double * b, double * c);
void LinearSolve(double a, double b, double c);
void SquareSolve(double a, double b, double c);

int main(void)
{
    printf("Эта программа умеет решать квадратное уравнение вида ax^2 + bx + c = 0.\n\n");

    double kf_a, kf_b, kf_c;
    Enter(&kf_a, &kf_b, &kf_c);        // передали адреса переменных в функцию, дальше функция считала значения с клавиатуры

    if (kf_a == 0)
    {
        LinearSolve(kf_a, kf_b, kf_c);
    }
    else
    {
        SquareSolve(kf_a, kf_b, kf_c);
    }
    return 0;
}


void Enter(double * a, double * b, double * c)
{
    printf("Введите значение коэффициента a: ");
    scanf("%lf", a);
    printf("Введите значение коэффициента b: ");
    scanf("%lf", b);
    printf("Введите значение коэффициента c: ");
    scanf("%lf", c);
}

void LinearSolve(double a, double b, double c)
{
    printf("\nПри a = 0 квадратное уравнение преобразуется к линейному.\n");
    if (b == 0 && c == 0)
        printf("И, кстати, данное линейное уравнение имеет решениями всякое действительное число.\n");
    if (b == 0 and c != 0)
        printf("И, кстати, данное линейное уравнение не имеет решений в действительных числах.\n");
    else
        printf("И, кстати, данное линейное уравнение имеет единственное решение x = %g.\n", -c / b);
}


void SquareSolve(double a, double b, double c)
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




