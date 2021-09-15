#include "Header.h"




int main()
{
    Complex n(5, -4);
    n.show_complex();

    cout << endl;

    n.set_r(3);
    n.set_m(10);
    n.show_complex();

    cout << endl;

    n.add_to_r(3);
    n.add_to_m(2);   
    n.show_complex();

    cout << endl;

    n.add_complex(5, 4);
    n.show_complex();
}

