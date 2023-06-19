#include <stdio.h>
#include <stdlib.h>

int strins(char *t, unsigned int size, const char *s, unsigned int idx)
{
    unsigned int t1, s1, i;
    if (t == NULL || s == NULL)
        return -1;
    for (t1  = 0; t[t1]; t1++);
    for (s1 = 0; s[s1]; s1++);
    if (t1 + s1 >= size)
        return -2;
    if (idx > t1)
        return -3;
    for (i = t1; i + 1 != idx; i--)
        t[i + s1] = t[i];
    for (i = 0; i < s1; i++)
        t[i + idx] = s[i];
    return 0;
}