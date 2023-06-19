#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n, i;
    double m, d;
    double a[1000];
    m = 0;
    d = 0;
    scanf("%d", &n);
    for (i = 0; i < n; ++i)
    {
        scanf("%lf", &a[i]);
        m += a[i];
    }
    m /= n;
    for (i = 0; i < n; i++)
    {
        d += (m - a[i]) * (m - a[i]);
    }
    printf("%lg %lg\n", m, sqrt(d / n));
    return 0;
}
