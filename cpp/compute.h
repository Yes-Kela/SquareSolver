// "compute.h" - header for "compute.cpp"
#ifndef COMPUTE_H
#define COMPUTE_H

struct TEST
{
    int Test_count;
    double a, b, c;
    double x1_ideal, x2_ideal;
    int Roots_count_ideal;
};

enum solutions {INF_ROOTS = -1, NO_ROOTS, ONE_ROOT, TWO_ROOTS};

int equal_double (double first, double second);
int EquationSolver (double a, double b, double c, double* x1, double* x2);
int Linear (double b, double c, double* x1, double* x2);
int Square (double a, double b, double c, double* x1, double* x2);


#endif  /* COMPUTE_H */
