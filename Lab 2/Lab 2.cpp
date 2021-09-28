#include "Opers.h"

int main()
{
    setlocale(LC_ALL, "ru");
    Opers OS2("OS/2", "DB2", 130, 22, 3343);
    Opers OS3("OS/3", "DB3", 130, 22, 3343);
    if (OS2 == OS3) cout << "\nЭкземпляры класса равны\n";
    else cout << "\n\tЭкземпляры класса НЕ равны\n";


    Opers OS4 = OS2 + OS3;
    cout << "\n\tСложение:\n";
    cout << OS4;
    cout << endl << endl;


    cout << "\n\tПрисваивание (OS2 = OS3):\n";
    OS2 = OS3;
    cout << OS2;
    cout << endl << endl;


    cout << "\n\tПотоковый ввод\n";
    cin >> OS2;
    cout << OS2;
    


}

