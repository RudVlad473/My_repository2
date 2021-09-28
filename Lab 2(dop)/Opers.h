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
    void GetAll(string&, string&, int&, int&, int&) const;


    void SetName(const string&);
    void SetSUBD(const string&);
    void Setoutmem(const int&);
    void SetminRam(const int&);
    void Setcost(const int&);
    void SetAll(const string&, const string&, const int&, const int&, const int&);

    Opers operator=(const Opers&);

    friend Opers operator+(Opers&, Opers&);
    friend bool operator==(const Opers&, const Opers&);

    friend ostream& operator << (ostream&, const Opers&);
    friend istream& operator >> (istream&, Opers&);

    int& operator[](const char* c) const;

    Opers operator() (const string&, const string&, const int&, const int&, const int&);

    void ShowAll() const;

};















