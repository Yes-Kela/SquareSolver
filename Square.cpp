// �������� ���������� ���������

#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
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
void ShowError (TEST data, double x1, double x2, int Roots_count);
void ShowSuccess (TEST data, double x1, double x2, int Roots_count);


int main(void)
{
    const int nTests = 10;
    TEST test[nTests] =
    {
    {.Test_count = 1,  .a = 1,      .b = -12,    .c = 35,     .x1_ideal = 5,              .x2_ideal = 7,      .Roots_count_ideal = 2},
    {.Test_count = 2,  .a = 5,      .b = 9,      .c = -14,    .x1_ideal = -2.8,           .x2_ideal = 1,      .Roots_count_ideal = 2},
    {.Test_count = 3,  .a = 0,      .b = 0,      .c = 0,      .x1_ideal = NAN,            .x2_ideal = NAN,    .Roots_count_ideal = -1},
    {.Test_count = 4,  .a = 1,      .b = 0,      .c = 5,      .x1_ideal = NAN,              .x2_ideal = NAN,      .Roots_count_ideal = 0},
    {.Test_count = 5,  .a = 0,      .b = 2,      .c = -6,     .x1_ideal = 3,              .x2_ideal = NAN,      .Roots_count_ideal = 1},
    {.Test_count = 6,  .a = 0.0001, .b = 1.2345, .c = 1.2344, .x1_ideal = -12344,         .x2_ideal = -1,     .Roots_count_ideal = 2},
    {.Test_count = 7,  .a = 0.05,   .b = 0.09,   .c = -0.14,  .x1_ideal = -2.8,           .x2_ideal = 1,      .Roots_count_ideal = 2},
    {.Test_count = 8,  .a = -15,    .b = 0,      .c = -2,     .x1_ideal = NAN,              .x2_ideal = NAN,      .Roots_count_ideal = 0},
    {.Test_count = 9,  .a = 3,      .b = 4,      .c = -4,     .x1_ideal = -2,             .x2_ideal = 2.0/3,  .Roots_count_ideal = 2},
    {.Test_count = 10, .a = 3.44,   .b = 1008,   .c = 0,      .x1_ideal = -1008.0/3.44,   .x2_ideal = 0,      .Roots_count_ideal = 2}
    };
    printf("��� ��������� ����� ������ ���������� ��������� ���� ax^2 + bx + c = 0.\n\n");
    double cf_a = 0, cf_b = 0, cf_c = 0;
    printf("������� �������� ������������� a, b � c � ���� �������.\n");
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
    assert (cf_a != NULL);
    assert (cf_b != NULL);
    assert (cf_c != NULL);

    printf("����������� a (������� ����� � ������� <Enter>): ");
    Input(cf_a);
    printf("����������� b (������� ����� � ������� <Enter>): ");
    Input(cf_b);
    printf("����������� c (������� ����� � ������� <Enter>): ");
    Input(cf_c);
}

void Input (double* cf)
{
    int ch = 0;
    int returned_cf = scanf("%lf", cf);
    assert (* cf != NAN);
    while (returned_cf != 1 || (ch = getchar()) != '\n')
    {
        while ((ch = getchar()) != '\n'){ ; }
        printf("\n������� ������������ ������ (��������, �� ��������������� �������� ��� ������ ������������ ��������)."
               "\n������� �������� ������������ ������: ");
        returned_cf = scanf("%lf", cf);
    }
}

int EquationSolver (double a, double b, double c, double* x1, double* x2)
{
    assert (x1 != NULL);
    assert (x2 != NULL);

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
    {
        * x1 = * x2 = NAN;
        return -1;
    }
    else if (b_is_0 && !c_is_0)
    {
        * x1 = * x2 = NAN;
        return 0;
    }
    else
    {
        * x1 = -c / b;
        * x2 = NAN;
        return 1;
    }
}

int Square (double a, double b, double c, double* x1, double* x2)
{
    double common = -b / (2*a);
    double discriminant = b*b - 4*a*c;
    assert (x1 != NULL);
    assert (x2 != NULL);
    if (discriminant < 0)
    {
        * x1 = * x2 =  NAN;
        return 0;
    }
    else if (equal_double(discriminant, 0))
    {
        * x1 = common;
        * x2 = NAN;
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
    printf("\n");
    switch(Roots_count)
    {
        case -1:
            printf("�������� ������� ��������� �������� ����� �������������� �����.\n");
            break;
        case 0:
            printf("������ ��������� ������ �� �����.\n");
            break;
        case 1:
            printf("������ ��������� ����� ������������ ������ � = %lg.\n", x1);
            break;
        case 2:
            printf("������ ��������� ����� ��� ������� � �������������� ������:\n"
                   "x1 = %lg\n" "x2 = %lg\n", x1, x2);
            break;
        default:
            printf("# ERROR: Roots_count = %d\n", Roots_count);
    }
}


// ����-������������

void RunTest (TEST data)
{
    double x1 = 0, x2 = 0;
    int Roots_count = EquationSolver(data.a, data.b, data.c, &x1, &x2);

    // ����������!
    if ((isnan(x1) || isnan(x2)) && Roots_count == data.Roots_count_ideal)
    {
        if (isnan(x1) && isnan(x2) && (Roots_count == -1 || Roots_count == 0))
            ShowSuccess(data, x1, x2, Roots_count);
        else if (Roots_count == 1 && x1 == data.x1_ideal && isnan(x2))
            ShowSuccess(data, x1, x2, Roots_count);
        else
            ShowError(data, x1, x2, Roots_count);
    }
    else if (Roots_count == data.Roots_count_ideal && x1 == data.x1_ideal && x2 == data.x2_ideal)
        ShowSuccess(data, x1, x2, Roots_count);
    else
        ShowError(data, x1, x2, Roots_count);
}

void RunAllTests (TEST test[], int nTests)
{
    printf("\n");
    for (int i = 0; i < nTests; i++)
        RunTest (test[i]);
}


void ShowError (TEST data, double x1, double x2, int Roots_count)
{
    printf("# SUCCESS: Test %d: a = %lg, b = %lg, c = %lg, Roots_count = %d, x1 = %lg, x2 = %lg\n",
            data.Test_count, data.a, data.b, data.c, Roots_count, x1, x2);
}

void ShowSuccess (TEST data, double x1, double x2, int Roots_count)
{
    printf("# ERROR: Test %d: a = %lg, b = %lg, c = %lg, Roots_count = %d, x1 = %lg, x2 = %lg\n"
           "  Expected: Roots_count = %d, x1 = %lg, x2 = %lg\n",
            data.Test_count, data.a, data.b, data.c, Roots_count, x1, x2,
            data.Roots_count_ideal, data.x1_ideal, data.x2_ideal);
}
