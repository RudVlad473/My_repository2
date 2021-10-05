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
    
    ArrayOfNums(const int &size);

    ArrayOfNums(const int &amountofnums, const int &min, const int &max);
    
    ArrayOfNums(const ArrayOfNums& a);

    ArrayOfNums(const ArrayOfNums& a, const int &max_value);
    
    ~ArrayOfNums();


    int get_size() const;

    void fill_no_repeat();
    
    void show_arr() const;
    
    int find_max() const;

    
    ArrayOfNums& operator = (const ArrayOfNums& obj);

    ArrayOfNums Union(const ArrayOfNums &newarr);
    
    ArrayOfNums Intersection(const ArrayOfNums &newarr);
    
    void Difference(const ArrayOfNums &newarr, ArrayOfNums& to_arr);

    void Disjunctive_sum(const ArrayOfNums& newarr, ArrayOfNums& to_arr);

    

};