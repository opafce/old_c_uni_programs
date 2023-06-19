#include <stdio.h>
#include <stdlib.h>
#define max(x, y) ((x) > (y) ? (x) : (y))

//copyright by Ivan Ivanin from 23.11.2017 12:48
int main()
{
    int r[2][100] = {{0}};
    int i, n, c, m = 0;
    scanf("%d %d", &n, &r[1][0]);
    for (i = 1; i < n; i++)
    {
        for (c = 0; c <= i; c++)
        {
            scanf("%d", &r[(i + 1) % 2][c]);
            if ((c < i) && (c > 0))
            {
                r[(i + 1) % 2][c] += max(r[i % 2][c - 1], r[i % 2][c]);
            }
        }
        r[(i + 1) % 2][0] += r[i % 2][0];
        r[(i + 1) % 2][i] += r[i % 2][i - 1];
    }
    for (i = 0; i < n; i++)
    {
        m = max(r[n % 2][i], m);
    }
    printf("%d\n", m);
    return 0;
}
