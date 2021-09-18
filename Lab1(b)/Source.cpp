#include "Header.h"

Figure::Figure(int a, int b, int c)
{
	if (a < 0) this->a = 0;
	else this->a = a;

	if (b < 0) this->b = 0;
	else this->b = b;

	if (c < 0) this->c = 0;
	else this->c = c;
}

float Figure::compute_square()
{
	if (a != 0 && (b == 0 && c == 0)) { return a * a * 3.141; }
	else {
		int p = (a + b + c) / 2;
		return (sqrt(p * (p - a) * (p - b) * (p - c)));
	}
}