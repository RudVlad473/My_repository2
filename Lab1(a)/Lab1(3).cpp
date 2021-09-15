#include "Header.h"

int main()
{
    setlocale(LC_ALL, "ru");
    Point dot(2, 3);
    Point dot2(3, 22);
    
    int sum;
    int multiply;
    dot.sum_and_multiply(sum, multiply);
    cout << "Сумма: " << sum << endl;
    cout << "Произведение: " << multiply << endl;
    dot2.show_results();

    dot.show_results();

   
    
   
}

