#include "Header.h"

float Figure:: triangle_square() const
{
    int p = (a + b + c) / 2;
    return (sqrt(p * (p - a) * (p - b) * (p - c)));
}

float Figure:: circle_square() const { return (r * r * 3.141); }

Figure::Figure() { r = a = b = c = 0; }

Figure::Figure(int radius = 0) { r = radius; a = b = c = 0; }
Figure::Figure(int a1, int b1, int c1)
{
    r = 0;
    a = a1;
    b = b1;
    c = c1;
}