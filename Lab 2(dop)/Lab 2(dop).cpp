#include "Opers.h"


int main()
{
    setlocale(LC_ALL, "ru");
    Opers OS2("OS/2", "DB2", 130, 22, 3343);
    Opers OS3("OS/3", "DB3", 130, 22, 3343);

    Opers OS4 = OS2 + OS3;
    cout << "\n\tСложение:\n";
    cout << OS4;
    cout << endl << endl;

    if (OS2 == OS3) cout << "\nЭкземпляры класса равны\n";
    else cout << "\n\tЭкземпляры класса НЕ равны\n";

    cout << "\nВызов оператора [] для строки 'OS/2': " << OS2["OS/2"] << endl;
    
}
