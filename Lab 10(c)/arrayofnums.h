#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class ArrayOfNums
{
private:
    int size;

    int* arr;

public:
    ArrayOfNums();
    
    ArrayOfNums(int size);

    ArrayOfNums(int amountofnums, int min, int max);
    
    ArrayOfNums(const ArrayOfNums& a);

    ArrayOfNums(ArrayOfNums& a, int max_value);
    
    ~ArrayOfNums();


    int get_size();

    void fill_no_repeat();
    
    void show_arr();
    
    int find_max();
    

    ArrayOfNums Union(ArrayOfNums newarr);
    
    ArrayOfNums Intersection(ArrayOfNums newarr);
    
    ArrayOfNums Difference(ArrayOfNums newarr);

    

};