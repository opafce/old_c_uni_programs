#include <stdio.h>

int main(void)
{
    int x1, x2, x3, x4, y1, y2, y3, y4;
    scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
    if (x2 < x3 || x1 > x4 || y2 < y3 || y1 > y4)
    {
        printf ( "NO\n" );
    }
    else
    {
        printf ( "YES\n" );
    }
    return 0;
}

