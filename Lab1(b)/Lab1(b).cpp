#include "Header.h"



int main()
{
	Figure circle(3);
	cout << circle.compute_square() << endl;

	Figure triangle(3, 4, 5);
	cout << endl << triangle.compute_square();
		
}


