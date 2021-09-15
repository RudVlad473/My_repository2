#include "Header.h"


int main()
{
    setlocale(LC_ALL, "ru");
    Opers OS2("OS/2", "DB2", 130, 22, 3343);
    cout << "\nИнициализация объекта через конструктор:\n";
    OS2.ShowAll();
    cout << endl << endl;

    /*Геттеры*/
    string somename = OS2.GetName();
    string somesubd = OS2.GetSUBD();
    int someoutmem = OS2.Getoutmem();
    int someminram = OS2.GetminRam();
    int somecost = OS2.Getcost();

    cout << "\n\tГеттеры:\n";
    cout << somename << endl;
    cout << somesubd << endl;
    cout << someoutmem << endl;
    cout << someminram << endl;
    cout << somecost << endl << endl;


    /*Сеттеры*/
    cout << "\tСеттеры:\n";
    OS2.SetName("name");
    OS2.SetSUBD("subd");
    OS2.Setoutmem(111);
    OS2.SetminRam(222);
    OS2.Setcost(333);
    OS2.ShowAll();

    cout << endl << endl;
    OS2.ShowAll();
}


