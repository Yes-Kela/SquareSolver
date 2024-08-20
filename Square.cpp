// �������� ���������� ���������
// ���� �������, ��� ��� �������� ������ ����������, �� ���� �������� �������

#include <TXLib.h>
#include <stdio.h>
#include <math.h>

void Enter(double * a, double * b, double * c);
void LinearSolve(double a, double b, double c);
void SquareSolve(double a, double b, double c);

int main(void)
{
    printf("��� ��������� ����� ������ ���������� ��������� ���� ax^2 + bx + c = 0.\n\n");

    double kf_a, kf_b, kf_c;
    Enter(&kf_a, &kf_b, &kf_c);        // �������� ������ ���������� � �������, ������ ������� ������� �������� � ����������

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
    printf("������� �������� ������������ a: ");
    scanf("%lf", a);
    printf("������� �������� ������������ b: ");
    scanf("%lf", b);
    printf("������� �������� ������������ c: ");
    scanf("%lf", c);
}

void LinearSolve(double a, double b, double c)
{
    printf("\n��� a = 0 ���������� ��������� ������������� � ���������.\n");
    if (b == 0 && c == 0)
        printf("�, ������, ������ �������� ��������� ����� ��������� ������ �������������� �����.\n");
    if (b == 0 and c != 0)
        printf("�, ������, ������ �������� ��������� �� ����� ������� � �������������� ������.\n");
    else
        printf("�, ������, ������ �������� ��������� ����� ������������ ������� x = %g.\n", -c / b);
}


void SquareSolve(double a, double b, double c)
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




