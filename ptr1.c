#include <stdio.h>
void order(char *c, short *a1, int *a, long *l, long long *ll, float *f, double *d, long double *e, char *s);
int main()
{
    char a;
    short b;
    int c;
    long d;
    long long e;
    float f;
    double g;
    long double h;
    char i[21];
    scanf("%hhd %hd %d %ld %lld %f %lf %Lf %s", &a, &b, &c, &d, &e, &f, &g, &h, i);
    order( &a, &b, &c, &d, &e, &f, &g, &h, i);
    printf("%hhd %hd %d %ld %lld %.0f %.0lf %.0Lf %s\n", a, b, c, d, e, f, g, h, i);
    return 0;
}