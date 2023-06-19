#include <stdio.h>
#include <stdlib.h>

void asc (int *a, double *b)
{
    int c;
    if (a && b)
    {
        if (*a > *b)
        {
            int c = *a;
            *a = (int) *b;
            *b = c;
        }
    }
}