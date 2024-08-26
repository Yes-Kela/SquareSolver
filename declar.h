// Header file "declaration.h"

struct TEST
{
    int Test_count;
    double a, b, c;
    double x1_ideal, x2_ideal;
    int Roots_count_ideal;
};

enum solutions {INF_ROOTS = -1, NO_ROOTS, ONE_ROOT, TWO_ROOTS};

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

void ShowSyntax (char arg0[]);
void basic_solving (void);
void ShowIncorrect (char arg0[], char arg1[]);
