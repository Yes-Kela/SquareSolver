// "tests.h" - header for "tests.cpp"

#ifndef TESTS_H
#define TESTS_H

struct TEST
{
    int Test_count;
    double a, b, c;
    double x1_ideal, x2_ideal;
    int Roots_count_ideal;
};

enum solutions {INF_ROOTS = -1, NO_ROOTS, ONE_ROOT, TWO_ROOTS};

int equal_double (double first, double second);
void RunAllTests (TEST test[], int nTests);
void RunTest (TEST data);
void ShowError (TEST data, double x1, double x2, int Roots_count);
void ShowSuccess (TEST data, double x1, double x2, int Roots_count);
int EquationSolver (double a, double b, double c, double* x1, double* x2);


#endif /* TESTS_H */
