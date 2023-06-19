#include <math.h>
#define xcv(a, b, c, d) (((a) - (b)) * ((a) - (b)) + ((c) - (d)) * ((c) - (d)))
double perimeter(double x1, double y1, double x2, double y2, double x3, double y3)
{
    return sqrt(xcv(x1, x2, y1, y2)) + sqrt(xcv(x1, x3, y1, y3)) + sqrt(xcv(x2, x3, y2, y3));
}