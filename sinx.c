#include <stdio.h>
#include <math.h>
#define N 1000
int main()
{
    int i;
    double x, q, t;
    scanf("%lf", &x);
    x *= M_PI / 180;
    q = t = x;
    for (i = 1; i < N; i++)
    {
        t *= -x * x / (2 * i * (2 * i + 1));
        q += t;

    }
    printf("%lg\n", q);
    return 0;
}