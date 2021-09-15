#pragma once
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Opers
{
    string Name;
    string SUBD;
    int outmem;
    int minRam;
    int cost;
public:
    Opers(const string&, const string&, const int&, const int&, const int&);

    string GetName() const;
    string GetSUBD() const;
    int Getoutmem() const;
    int GetminRam() const;
    int Getcost() const;


    void SetName(const string&);
    void SetSUBD(const string&);
    void Setoutmem(const int&);
    void SetminRam(const int&);
    void Setcost(const int&);
   


    void ShowAll() const;
    
};