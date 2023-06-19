#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int sumN(unsigned n, ...)
{
    va_list ap;
    int sum = 0;
    unsigned int j;
    va_start(ap, n);
    for (j = 0; j < n; j++) 
    {
        sum += va_arg(ap, int);
    }
    va_end(ap);
    return sum;
}