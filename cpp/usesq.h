// "usesq.h" - header for "usesq.cpp"

#ifndef USESQ_H
#define USESQ_H

struct TEST
{
    int Test_count;
    double a, b, c;
    double x1_ideal, x2_ideal;
    int Roots_count_ideal;
};

void ShowSyntax (char arg0[]);
void basic_solving (void);
void ShowIncorrect (char arg0[]);

void RunAllTests (TEST test[], int nTests);


#endif /* USESQ_H */
