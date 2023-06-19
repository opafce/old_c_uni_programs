#include <stdio.h>

#define abs(x) ((x) >= 0 ? (x) : -(x))

long unsigned int nod(long unsigned int a, long unsigned int b)
{
    long unsigned int c;
    while (b)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main()
{
    long unsigned int i, q, p, n0d;
    scanf("%lu %lu", &q, &p);
    n0d = nod(q, p);
    if (n0d > 1)
    {
        for(i = 1; i < p; i++)
        {
            if ((i % n0d) != 0)
                printf("%lu ", i);
        }
    }
    else
        printf("-1");
    printf("\n");
    return 0;
}
