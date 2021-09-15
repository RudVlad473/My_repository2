#pragma once
#include <iostream>
using namespace std;

class Figure
{

    int r;
    int a, b, c;
public:
    Figure();
    
    Figure(int);
    Figure(int, int, int);

    float triangle_square() const;
    
    float circle_square() const;
    
    
    
    
};