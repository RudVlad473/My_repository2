#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class Dog
{

    string name;

    int weight;

    int age;

public:
    Dog();

    Dog(string, int, int);
    
    Dog(const Dog&);
    

    void set_name(string);

    void set_weight(int);

    void set_age(int);


    string get_name();

    int get_weight();

    int get_age();
};


class Master
{

    string FIO;

    const int ID = 9999;

    int count;

    int dogcount;

    Dog* dogs;

    Master* masters;

public:
    

    Master();
    
    Master(Master&);

    void set_FIO(string, int);

    int get_dogcount();

    void add_dog(Dog dog);

    void add_master(Master master);

    void show_dogs();
   
    ~Master();

};