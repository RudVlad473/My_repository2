#include "Opers.h"

void Opers::ShowAll() const
{
    printf("-----------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|                                          ???????????? ?????????? ??????? ?????????????? ??????                                        |\n");
    printf("-----------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|   ???????????? ???????  |    ????    |???.????? ??????? ?????? (MB)|  ???.????? ??????????? ?????? (MB)  |   ??????????????? ???? ($) |\n");
    printf("-----------------------------------------------------------------------------------------------------------------------------------------\n");

    cout << "|" << setw(25) << Name << "|" << setw(12) << SUBD << "|" << setw(29) << outmem << "|" << setw(37) << minRam << "|" << setw(28) << cost << "|" << endl;

    printf("-----------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|??????????: ??????????? ???? ???????? ?? 8 ?????????????                                                                               |\n");
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

Opers Opers::operator+(const Opers& obj)
{
    this->Name += obj.Name;
    this->SUBD += obj.SUBD;
    this->outmem += obj.outmem;
    this->minRam += obj.minRam;
    this->cost += obj.cost;
    return *this;
}

bool Opers::operator==(const Opers& obj) const
{
    return (
        this->Name == obj.Name &&
        this->SUBD == obj.SUBD &&
        this->outmem == obj.outmem &&
        this->minRam == obj.minRam &&
        this->cost == obj.cost
        );
}

ostream& operator << (ostream& out, const Opers& obj)
{


    printf("-----------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|                                          ???????????? ?????????? ??????? ?????????????? ??????                                        |\n");
    printf("-----------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|   ???????????? ???????  |    ????    |???.????? ??????? ?????? (MB)|  ???.????? ??????????? ?????? (MB)  |   ??????????????? ???? ($) |\n");
    printf("-----------------------------------------------------------------------------------------------------------------------------------------\n");

    out << "|" << setw(25) << obj.Name << "|" << setw(12) << obj.SUBD << "|"
        << setw(29) << obj.outmem << "|" << setw(37) << obj.minRam << "|" << setw(28) << obj.cost << "|" << endl;

    printf("-----------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|??????????: ??????????? ???? ???????? ?? 8 ?????????????                                                                               |\n");
    printf("-----------------------------------------------------------------------------------------------------------------------------------------");
    return out;
}

istream& operator >> (istream& in, Opers& obj)
{
    cout << "\t??????? ????????? ?????????\n";

    cout << "???: ";
    getline(cin, obj.Name);

    cout << "\n????: ";
    getline(cin, obj.SUBD);

    cout << "\n???. ????? ????. ??????: ";
    in >> obj.minRam;

    cout << "\n???. ????? ??????? ??????: ";
    in >> obj.outmem;

    cout << "\n????: ";
    in >> obj.cost;

    return in;
}