// Control module "usesq.cpp"

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "usesq.h"

int main(int argc, char* argv[])
{
    const int nTests = 10;
    TEST test[nTests] =
    {
    {.Test_count = 1,  .a = 1,      .b = -12,    .c = 35,     .x1_ideal = 5,              .x2_ideal = 7,      .Roots_count_ideal = 2},
    {.Test_count = 2,  .a = 5,      .b = 9,      .c = -14,    .x1_ideal = -2.8,           .x2_ideal = 1,      .Roots_count_ideal = 2},
    {.Test_count = 3,  .a = 0,      .b = 0,      .c = 0,      .x1_ideal = NAN,            .x2_ideal = NAN,    .Roots_count_ideal = -1},
    {.Test_count = 4,  .a = 1,      .b = 0,      .c = 5,      .x1_ideal = NAN,            .x2_ideal = NAN,    .Roots_count_ideal = 0},
    {.Test_count = 5,  .a = 0,      .b = 2,      .c = -6,     .x1_ideal = 3,              .x2_ideal = NAN,    .Roots_count_ideal = 1},
    {.Test_count = 6,  .a = 0.0001, .b = 1.2345, .c = 1.2344, .x1_ideal = -12344,         .x2_ideal = -1,     .Roots_count_ideal = 2},
    {.Test_count = 7,  .a = 0.05,   .b = 0.09,   .c = -0.14,  .x1_ideal = -2.8,           .x2_ideal = 1,      .Roots_count_ideal = 2},
    {.Test_count = 8,  .a = -15,    .b = 0,      .c = -2,     .x1_ideal = NAN,            .x2_ideal = NAN,    .Roots_count_ideal = 0},
    {.Test_count = 9,  .a = 3,      .b = 4,      .c = -4,     .x1_ideal = -2,             .x2_ideal = 2.0/3,  .Roots_count_ideal = 2},
    {.Test_count = 10, .a = 3.44,   .b = 1008,   .c = 0,      .x1_ideal = -1008.0/3.44,   .x2_ideal = 0,      .Roots_count_ideal = 2}
    };

    if (argc <= 1)
    {
        ShowSyntax(argv[0]);
    }
    else if (!strcmp(argv[1], "--solve"))
    {
        basic_solving();
    }
    else if (!strcmp(argv[1], "--test"))
    {
        printf("\n");
        RunAllTests(test, nTests);
    }
    else
    {
        ShowIncorrect(argv[0]);
    }
    return 0;
}
