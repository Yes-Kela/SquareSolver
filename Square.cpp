// �������� ���������� ���������.
// ���� �������, ��� ��� �������� ������ ����������, �� ���� �������� �������.

#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>

void Enter (double * a, double * b, double * c);       // ������� �����
int LinearSolver (double b, double c, double * x);            // �������, ��������� ������� ��������� ���������
void SquareSolver (double a, double b, double c);      // �������, ��������� ������� ���������

int main(void)
{
    printf("��� ��������� ����� ������ ���������� ��������� ���� ax^2 + bx + c = 0.\n\n");

    double kf_a = 0, kf_b = 0, kf_c = 0;
    Enter (&kf_a, &kf_b, &kf_c);

    while (isdigit(kf_a) == 0 || isdigit(kf_b) == 0 || isdigit(kf_c) == 0)
    {
        printf("����������� ������� ������. ������� �������� �������� ������������� �����.\n");
        Enter (&kf_a, &kf_b, &kf_c);
    }

    if (kf_a == 0)
    {
        printf("\n��� a = 0 ���������� ��������� ������������� � ���������.\n");
        double root_x = 0;
        int count_Roots = LinearSolver(kf_b, kf_c, &root_x);
        switch (count_Roots)
        {
        case -1:
            printf("�, ������, ������ �������� ��������� ����� ��������� ������ �������������� �����.\n");
            break;
        case 0:
            printf("�, ������, ������ �������� ��������� �� ����� ������� � �������������� ������.\n");
            break;
        case 1:
            printf("�, ������, ������ �������� ��������� ����� ������������ ������� x = %g.\n", root_x);
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
    printf("������� �������� ������������ a: ");
    scanf("%lf", a);
    printf("������� �������� ������������ b: ");
    scanf("%lf", b);
    printf("������� �������� ������������ c: ");
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
        printf("\n������ ���������� ��������� ������� � �������������� ������ �� �����.\n");
    else if (discriminant == 0)
        printf("\n������ ���������� ��������� ����� ������������ ������� x = %g.\n", common);
    else
    {
        double sqrt_discrim_div_dbl_a = sqrt(discriminant) / (2*a);
        printf("\n������ ���������� ��������� ����� ��� ������� � �������������� ������.\n");
        printf("������ �������: � = %g.\n", common - sqrt_discrim_div_dbl_a);
        printf("������ �������: x = %g.\n", common + sqrt_discrim_div_dbl_a);
    }
}




