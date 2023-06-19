#include <stdio.h>


int main()
{
    char st[1001];
    int c, n, i;
    c = 0;
    n = 0;
    gets(st);
    for (i = 0; st[i]; i++)
    {
        if (i % 2 == 1)
        {
            c = c + st[i] - '0';
        }
        else
        {
            n = n + st[i] - '0';
        }
    }
    if (((c - n) % 11) == 0)
    {
        puts("YES");
    }
    else
    {
        puts("NO");
    }
    return 0;
}
