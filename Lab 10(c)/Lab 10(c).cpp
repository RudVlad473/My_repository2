#include "arrayofnums.h"

int main()
{
    srand(time(NULL));
    ArrayOfNums arr1(10);
    arr1.fill_no_repeat();
    arr1.show_arr();

    cout << endl << endl;
    ArrayOfNums arr2(10);
    arr2.fill_no_repeat();
    arr2.show_arr();

    cout << endl << endl;


    ArrayOfNums testarr(arr1.Difference(arr2));
    testarr.show_arr();
}

