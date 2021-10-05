#include "master_and_dog.h"


//сделать массив мастеров внешним


int main()
{
    setlocale(LC_ALL, "ru");
    Master* masters = nullptr;

    Master m1;
    Master m2;

    m1.set_FIO("Master1");
    m2.set_FIO("Master2");

    m1.add_master(masters, m1);
    m2.add_master(masters, m2);
 
    Dog dog1("1", 1, 1);
    Dog dog2("2", 2, 2);
    Dog dog3("3", 3, 3);

    m1.add_dog(dog1);
    m2.add_dog(dog2);
    m2.add_dog(dog3);

    
    int a;
    while (true)
    {
        a = 0;
        cout << endl << "Выберите функцию:" << endl;
        
        cout << "1 - Показать всех мастеров\n";
        cout << "2 - Показать всех собак\n";
        cout << "3 - Добавить мастера\n";
        cout << "4 - Добавить собаку\n";

        cout << "---> ";
        cin >> a; 

        if (a == 1) m1.show_masters(masters);
        else if (a == 2)
        {
            if (masters == nullptr)
            {
                cout << "\nСписок мастеров пуст.\n";
                exit(0);
            }
            else 
            {
                string mastername = "";
                cout << "\n\tВведите ФИО мастера, собак которого хотите увидеть: ";
                getline(cin, mastername);
                for (int i = 0; i < m1.get_count(); ++i)
                {
                    if (masters[i].get_FIO() == mastername)
                    {
                        for (int j = 0; j < m1.get_dogcount(); ++j)
                        {
                            cout
                                << setw(9)
                                << "Возраст: " << m1.get_dog(j).get_age() << endl
                                << setw(9)
                                << "Кличка: "
                                << m1.get_dog(j).get_name() << endl
                                << setw(9)
                                << "Вес: " << m1.get_dog(j).get_weight() << endl << endl;
                        }

                    }
                    cout << endl << endl;
                }
            }
        }
        //else return;
        else if (a == 3)
        {
            cout << "\nВведите ФИО мастера: ";
            string mastername = "";
            getline(cin, mastername);
            Master master(mastername);
            master.add_master( masters, master);
        }
        
    }
    


    


    
}


