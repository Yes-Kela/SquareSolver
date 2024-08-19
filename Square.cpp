// Решатель квадратных уравнений

#include <TXLib.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    double a, b, c, discriminant;
    int returned_a, returned_b, returned_c, counter;

    counter = 0;
    printf("Эта программа умеет решать квадратное уравнение вида ax^2 + bx + c = 0.\n\n");

    do
    {
        if (counter >= 1)
        {
            printf("\nВведите новые значения коэффициентов для продолжения\n");
            printf("(или введите любое нечисловое значение для выхода).\n");
        }
        printf("Введите значение коэффициента a: ");
        returned_a = scanf("%lf", &a);
        printf("Введите значение коэффициента b: ");
        returned_b = scanf("%lf", &b);
        printf("Введите значение коэффициента с: ");
        returned_c = scanf("%lf", &c);

        if (returned_a == 1 && returned_b == 1 && returned_c == 1)
        {
            while (a == 0)
            {
                printf("\nНекорректно введено значение коэффицианта а (а = 0).\n");
                printf("При a = 0 квадратное уравнение преобразуется к линейному.\n");
                if (b == 0 && c == 0)
                    printf("И, кстати, данное линейное уравнение имеет решениями всякое действительное число.\n");
                if (b == 0 and c != 0)
                    printf("И, кстати, данное линейное уравнение не имеет решений в действительных числах.\n");
                else
                    printf("И, кстати, данное линейное уравнение имеет единственное решение x = %g.\n", -c/b);
                printf("Чтобы решить всё-таки квадратное уравнение, введите ненулевое значение а заново: ");
                returned_a = scanf("%lf", &a);
            }

            discriminant = b*b - 4*a*c;

            if (discriminant < 0)
                printf("\nДанное квадратное уравнение решений в действительных числах не имеет.\n");
            else if (discriminant == 0)
                printf("\nДанное квадратное уравнение имеет единственное решение x = %g.\n", -b/(2*a));
            else
            {
                printf("\nДанное квадратное уравнение имеет два решения в действительных числах.\n");
                printf("Первое решение: х = %g.\n", (-b - sqrt(discriminant)) / (2*a));
                printf("Второе решение: x = %g.\n", (-b + sqrt(discriminant)) / (2*a));
            }
            counter++;
        }
    } while (returned_a == 1 && returned_b == 1 && returned_c == 1);

    printf("\n\nВы ввели нечисловое значение. Программа завершена.\n");

    return 0;
}







