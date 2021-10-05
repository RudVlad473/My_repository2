#include "arrayofnums.h"

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "ru");


    cout << "\n\tМассив 1:\n";
    ArrayOfNums arr1(5);
    arr1.fill_no_repeat();
    arr1.show_arr();

    cout << endl << endl;
    cout << "\n\tМассив 2:\n";
    ArrayOfNums arr2(5);
    arr2.fill_no_repeat();
    arr2.show_arr();

    cout << endl << endl;

    cout << "\nНахождение макс. элемента в массиве 1: " << arr1.find_max();
    cout << "\nНахождение макс. элемента в массиве 2: " << arr2.find_max();
    


    cout << endl << endl;
    
    ArrayOfNums testarr1;
    testarr1 = arr1.Union(arr2);
    cout << "\n\tМассив-объединение:\n";
    testarr1.show_arr();
    cout << endl;


    ArrayOfNums testarr2;
    testarr2 = arr1.Intersection(arr2);
    cout << "\n\tМассив-пересечение:\n";
    testarr2.show_arr();
    cout << endl;



    ArrayOfNums testarr3;
    arr1.Difference(arr2, testarr3);
    cout << "\n\tМассив-разница:\n";
    testarr3.show_arr();
    cout << endl;



    ArrayOfNums testarr4;
    arr1.Disjunctive_sum(arr2, testarr4);
    cout << "\n\tМассив-дизъюнктивная сумма:\n";
    testarr4.show_arr();
}

