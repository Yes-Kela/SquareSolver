// "usecmd.h" - header for "usecmd.cpp"

void MainInput (double* cf_a, double* cf_b, double* cf_c);
int EquationSolver (double a, double b, double c, double* x1, double* x2);
void Output (double x1, double x2, int Roots_count);
void ShowSyntax (char arg0[]);
void basic_solving (void);
void ShowIncorrect (char arg0[]);
