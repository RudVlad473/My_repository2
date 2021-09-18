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
    if (theoutmem < 0) outmem = 0;
    else{ outmem = theoutmem; }
   
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