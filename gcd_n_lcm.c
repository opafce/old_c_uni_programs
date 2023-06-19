#include <stdio.h>

int nod(int a, int b)
{
    while (b)
    {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int nok(int a, int b)
{
    return a / nod(a, b) * b;
}

int main()
{
    int i, n , c, n0k, n0d;
    scanf("%d %d", &n, &n0k);
    n0d = n0k;
    for (i = 0; i < n - 1; i++)
    {
        scanf("%d", &c);
        n0d = nod(c, n0d);
        n0k = nok(n0k, c);
    }
    printf("%d %d\n", n0d, n0k);
    return 0;
}