#include <stdio.h>
#include <math.h>
#define gy(x) ((x) > -1e-10 && (x) < 1e-10 ? 0 : (x))
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
int main(void)
{
    double a, b, c, disk, x1, x2;

    scanf("%lf %lf %lf", &a, &b, &c );
    if (a != 0)
    {
        disk = b * b - 4 * a * c;
        if (disk < 0)
        {
            printf("NO\n");
        }
        if (disk == 0)
        {
            printf("%lf\n", gy((-b)/2/a));
        }
        if (disk > 0)
        {
            disk = sqrt(disk);
            x1 = ((- b - disk)/2/a);
            x2 = ((- b + disk)/2/a);
            printf("%lf %lf\n", min(x1, x2), max(x1, x2));
        }
    }
    else
    {
        if (b != 0)
        {
            printf("%lf\n", gy(-(c / b)));
        }
        else
        {
            if (c == 0)
            {
                printf("R\n");
            }
            else
            {
                printf("NO\n");
            }
        }
    }
    return 0;
}
