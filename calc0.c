#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double calc0(char *a)
{
    char *i;
    if (i = strrchr(a, '+'))
    {
        *i = '\0';
        return calc0(a) + calc0(i + 1);
    }
    if (i = strrchr(a, '-'))
    {
        *i = '\0';
        return calc0(a) - calc0(i + 1);
    }
    if (i = strrchr(a, '*'))
    {
        *i = '\0';
        return calc0(a) * calc0(i + 1);
    }
    if (i = strrchr(a, '/'))
    {
        *i = '\0';
        return calc0(a) / calc0(i + 1);
    }
    if (i = strrchr(a, '^'))
    {
        *i = '\0';
        return pow(calc0(a), calc0(i + 1));
    }
    if (i = strrchr(a, '#'))
    {
        *i = '\0';
        return sqrt(calc0(i + 1));
    }
    return atof(a);
}

int main(void)
{
    char s[1024];
    scanf("%s", s);
    printf("%lg\n", calc0(s));
    return 0;
}
