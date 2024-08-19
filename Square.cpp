// �������� ���������� ���������

#include <TXLib.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    double a, b, c, discriminant;
    int returned_a, returned_b, returned_c, counter;

    counter = 0;
    printf("��� ��������� ����� ������ ���������� ��������� ���� ax^2 + bx + c = 0.\n\n");

    do
    {
        if (counter >= 1)
        {
            printf("\n������� ����� �������� ������������� ��� �����������\n");
            printf("(��� ������� ����� ���������� �������� ��� ������).\n");
        }
        printf("������� �������� ������������ a: ");
        returned_a = scanf("%lf", &a);
        printf("������� �������� ������������ b: ");
        returned_b = scanf("%lf", &b);
        printf("������� �������� ������������ �: ");
        returned_c = scanf("%lf", &c);

        if (returned_a == 1 && returned_b == 1 && returned_c == 1)
        {
            while (a == 0)
            {
                printf("\n����������� ������� �������� ������������ � (� = 0).\n");
                printf("��� a = 0 ���������� ��������� ������������� � ���������.\n");
                if (b == 0 && c == 0)
                    printf("�, ������, ������ �������� ��������� ����� ��������� ������ �������������� �����.\n");
                if (b == 0 and c != 0)
                    printf("�, ������, ������ �������� ��������� �� ����� ������� � �������������� ������.\n");
                else
                    printf("�, ������, ������ �������� ��������� ����� ������������ ������� x = %g.\n", -c/b);
                printf("����� ������ ��-���� ���������� ���������, ������� ��������� �������� � ������: ");
                returned_a = scanf("%lf", &a);
            }

            discriminant = b*b - 4*a*c;

            if (discriminant < 0)
                printf("\n������ ���������� ��������� ������� � �������������� ������ �� �����.\n");
            else if (discriminant == 0)
                printf("\n������ ���������� ��������� ����� ������������ ������� x = %g.\n", -b/(2*a));
            else
            {
                printf("\n������ ���������� ��������� ����� ��� ������� � �������������� ������.\n");
                printf("������ �������: � = %g.\n", (-b - sqrt(discriminant)) / (2*a));
                printf("������ �������: x = %g.\n", (-b + sqrt(discriminant)) / (2*a));
            }
            counter++;
        }
    } while (returned_a == 1 && returned_b == 1 && returned_c == 1);

    printf("\n\n�� ����� ���������� ��������. ��������� ���������.\n");

    return 0;
}







