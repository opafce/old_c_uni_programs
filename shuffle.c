#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// copyright by Ivan Ivanin 23.11.2017 10:17
int main()
{
    int n, i, r, j;
    int* p = NULL;
    scanf("%d", &n);
    if (n > 0)
    {
        srand((unsigned)time(NULL));
        p = (int*) malloc(n * sizeof(int));
        for (i = 0; i < n; i++)
        {
            scanf("%d", &p[i]);
        }
        for(i = n; i > 0; i--)
        {
            r = rand() % i;
            printf("%d ", p[r]);
            p[r] = p[0];
            p++;
        }
        printf("\n");
        free(p - n);
    }
    return 0;
}

