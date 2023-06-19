#include <stdio.h>
#include <math.h>

#define POG 1e-10
#define gy(x) ((x) > -1e-7 && (x) < 1e-7 ? 0 : (x))

int main()
{
    double a, b, x;
    int count = 0;
    scanf("%lf %lf", &a, &b);
    if (tan(a) > a || tan(b) < b)
        printf("-1\n");
    else
    {
        while (b - a > POG)
        {
            x = (a + b) / 2;
            count++;
            if (tan(x) > x)
                b = x;
            else
                a = x;
        }
        printf("%.10lf %d\n", gy(a), count);
    }
    return 0;
}
