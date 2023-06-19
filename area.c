#define ags(x) ((x) > 0 ? (x) : -(x))
double area(double x1, double y1, double x2, double y2, double x3, double y3)
{
    return ags(((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2));
}