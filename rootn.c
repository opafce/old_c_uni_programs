#include <stdio.h>
#include <stdlib.h>

#define gy(x) ((x) > -1e-10 && (x) < 1e-10 ? 0 : (x))
#define abs(x) ((x) >= 0 ? (x) : -(x))

double pw(double q, int n)
{
    int i;
    double b = 1;
    for (i = 0; i < n; ++i)
    {
        b *= q;
    }
    return b;
}

int main()
{
    int n;
    double a, c = 1, d, e = 1;
    scanf("%d %lf", &n, &a);
    while(abs(e) >= 1e-6)
    {
        d = c;
        c = (d * (n - 1) + a / pw(d, n - 1)) / n;
        e = c - d;
    }
    printf("%lg\n", gy(c));
    return 0;
}
