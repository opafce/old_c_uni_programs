#include <stdio.h>
#include <math.h>

#define STEP 2e-6
int main()
{
    int a, b, sig = 1;
    double s = 0, ar, br , i;
    scanf("%d %d", &a, &b);
    ar = a * M_PI / 180;
    br = b * M_PI / 180;
    if (ar > br)
    {
        i = br;
        br = ar;
        ar = i;
        sig = -1;
    }
    for (i = ar; i < br; i += STEP)
    {
        s += sig * STEP * cos(i * i);
    }
    printf("%lg\n", s);
    return 0;
}
