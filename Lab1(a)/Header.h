#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

class Point
{

    int x;
    int y;
public:
    //Point();

    Point(const int& , const int& );

    Point(const Point& obj);
    void set_x(const int& value);
    void set_y(const int& value);

    int get_x() const;
    int get_y() const;


    void sum_and_multiply(int& sum_var, int& mult_var) const;
    void sum_and_multiply(int* sum_var, int* mult_var) const;

    void show_results() const;
    
};