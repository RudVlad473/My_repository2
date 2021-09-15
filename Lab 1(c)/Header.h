#pragma once
#include <iostream>
using namespace std;


class Complex
{
    int r;
    int m;
public:

    Complex();

    Complex(int, int);
    void set_r(const int&);
    void set_m(const int&);

    void add_to_r(const int&);
    void add_to_m(const int&);

    void add_complex(const int&, const int&);
   
    void show_complex() const;
    

};