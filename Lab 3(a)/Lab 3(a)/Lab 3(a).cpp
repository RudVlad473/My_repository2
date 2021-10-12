#include <iostream>
using namespace std;
class Dog
{
    int weight;
    int age;

public:

    Dog(int weight = 0, int age = 0)
    {
        this->weight = weight;
        this->age = age;
        cout << "\nВызвался конструктор класса Dog\n";
    }

    string golos()
    {
        if (weight >= 10) return "GAV";
        else return "gav";
    }

    friend ostream& operator<<(ostream& out, const Dog& obj)
    {
        out << "\nВес: " << obj.weight;
        out << "\nВозраст: " << obj.age << endl;
        return out;
    }

    virtual ~Dog() { cout << "\nВызвался деструктор класса Dog\n"; }
};

class Spaniel :public Dog
{
    string color;
public:
    Spaniel(int weight, int age, string color) :Dog(weight, age), color(color) { cout << "\nВызвался конструктор класса Spaniel" << endl; };



    friend ostream& operator<<(ostream& out, const Spaniel& obj)
    {
        out << (Dog&)obj << "\nЦвет: " << obj.color << endl;
        return out;
    }

    virtual ~Spaniel() { cout << "\nВызвался деструктор класса Spaniel\n"; }
};

int main()
{
    setlocale(LC_ALL, "ru");
    Dog dog(15, 5);
    Spaniel spaniel(15, 5, "pink");
    cout << dog << endl;
    cout << spaniel;
}

