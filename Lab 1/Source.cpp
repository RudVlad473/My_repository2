#include "Header.h"
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
    outmem = theoutmem;
    minRam = theminRam;
    cost = thecost;
}

string Opers::GetName() const { return Name; }
string Opers::GetSUBD() const { return SUBD; }
int Opers::Getoutmem() const { return outmem; }
int Opers::GetminRam() const { return minRam; }
int Opers::Getcost() const { return cost; }


void Opers::SetName(const string& aName) { Name = aName; }
void Opers::SetSUBD(const string& aSUBD) { SUBD = aSUBD; }
void Opers::Setoutmem(const int& valueoutmem) { outmem = valueoutmem; }
void Opers::SetminRam(const int& valueminRam) { minRam = valueminRam; }
void Opers::Setcost(const int& valuecost) { cost = valuecost; }