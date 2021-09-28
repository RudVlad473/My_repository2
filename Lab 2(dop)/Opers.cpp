#include "Opers.h"

int& Opers::operator[](const char* c) const
{
    int count(0);
    for (int i = 0; c[i] != '\0'; ++i) ++count;
    return count;
}

Opers Opers::operator()(const string& name, const string& subd, const int& outmem, const int& minram, const int& cost)
{
    this->Name = name;
    this->SUBD = subd;
    if (outmem < 0) this->outmem = 0;
    else { this->outmem = outmem; }

    if (minram < 0) { this->minRam = 0; }
    else this->minRam = minram;

    if (cost < 0) this->cost = 0;
    else this->cost = cost;

    return *this;
}

void Opers::ShowAll() const
{
    printf("-----------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|                                          Конфигурация програмных средств информационных систем                                        |\n");
    printf("-----------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|   Операционная система  |    СУБД    |Мин.объем внешней памяти (MB)|  Мин.объем оперативной памяти (MB)  |   Приблизительная цена ($) |\n");
    printf("-----------------------------------------------------------------------------------------------------------------------------------------\n");

    cout << "|" << setw(25) << Name << "|" << setw(12) << SUBD << "|" << setw(29) << outmem << "|" << setw(37) << minRam << "|" << setw(28) << cost << "|" << endl;

    printf("-----------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|Примечание: принималась цена лицензии на 8 пользователей                                                                               |\n");
    printf("-----------------------------------------------------------------------------------------------------------------------------------------");
}

Opers::Opers(const string& theName = "None", const string& theSUBD = "None", const int& theoutmem = 0, const int& theminRam = 0, const int& thecost = 0)
{


    Name = theName;
    SUBD = theSUBD;
    if (theoutmem < 0) outmem = 0;
    else { outmem = theoutmem; }

    if (theminRam < 0) { minRam = 0; }
    else minRam = theminRam;

    if (thecost < 0) cost = 0;
    else cost = thecost;


}

string Opers::GetName() const { return Name; }
string Opers::GetSUBD() const { return SUBD; }
int Opers::Getoutmem() const { return outmem; }
int Opers::GetminRam() const { return minRam; }
int Opers::Getcost() const { return cost; }

void Opers::GetAll(string& name, string& subd, int& outmem, int& minram, int& cost) const
{
    name = this->Name;
    subd = this->SUBD;
    outmem = this->outmem;
    minram = this->minRam;
    cost = this->cost;
}

void Opers::SetName(const string& aName) { Name = aName; }
void Opers::SetSUBD(const string& aSUBD) { SUBD = aSUBD; }

void Opers::Setoutmem(const int& valueoutmem)
{
    if (valueoutmem < 0) outmem = 0;
    else outmem = valueoutmem;
}

void Opers::SetminRam(const int& valueminRam)
{
    if (valueminRam < 0) minRam = 0;
    else minRam = valueminRam;
}

void Opers::Setcost(const int& valuecost)
{
    if (valuecost < 0) cost = 0;
    else cost = valuecost;
}

void Opers::SetAll(const string& name, const string& subd, const int& outmem, const int& minram, const int& cost)
{
    this->Name = name;
    this->SUBD = subd;
    this->outmem = outmem;
    this->minRam = minram;
    this->cost = cost;
}

Opers Opers::operator=(const Opers& obj)
{
    this->Name = obj.Name;
    this->SUBD = obj.SUBD;
    this->outmem = obj.outmem;
    this->minRam = obj.minRam;
    this->cost = obj.cost;
    return *this;
}

Opers operator+(Opers& obj1, Opers& obj2)
{
    Opers obj3;
    obj3.Name = obj1.Name + obj2.Name;
    obj3.SUBD = obj1.SUBD + obj2.SUBD;
    obj3.outmem = obj1.outmem + obj2.outmem;
    obj3.minRam = obj1.minRam + obj2.minRam;
    obj3.cost = obj1.cost + obj2.cost;
    return obj3;
}

bool operator==(const Opers& obj1, const Opers& obj2)
{
    return (
        obj1.Name == obj2.Name &&
        obj1.SUBD == obj2.SUBD &&
        obj1.outmem == obj2.outmem &&
        obj1.minRam == obj2.minRam &&
        obj1.cost == obj2.cost
        );
}

ostream& operator << (ostream& out, const Opers& obj)
{


    printf("-----------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|                                          Конфигурация програмных средств информационных систем                                        |\n");
    printf("-----------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|   Операционная система  |    СУБД    |Мин.объем внешней памяти (MB)|  Мин.объем оперативной памяти (MB)  |   Приблизительная цена ($) |\n");
    printf("-----------------------------------------------------------------------------------------------------------------------------------------\n");

    out << "|" << setw(25) << obj.Name << "|" << setw(12) << obj.SUBD << "|"
        << setw(29) << obj.outmem << "|" << setw(37) << obj.minRam << "|" << setw(28) << obj.cost << "|" << endl;

    printf("-----------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|Примечание: принималась цена лицензии на 8 пользователей                                                                               |\n");
    printf("-----------------------------------------------------------------------------------------------------------------------------------------");
    return out;
}

istream& operator >> (istream& in, Opers& obj)
{
    cout << "\tВведите следующие параметры\n";

    cout << "Имя: ";
    getline(cin, obj.Name);

    cout << "\nСУБД: ";
    getline(cin, obj.SUBD);

    cout << "\nМин. объем опер. памяти: ";
    in >> obj.minRam;

    cout << "\nМин. объем внешней памяти: ";
    in >> obj.outmem;

    cout << "\nЦена: ";
    in >> obj.cost;

    return in;
}