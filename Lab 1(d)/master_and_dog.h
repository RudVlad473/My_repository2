#pragma once
#include <iostream>
#include <iomanip>
#include <string>
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

    

public:
    

    Master();

    Master(string name);
    
    Master(const Master&);

    Master operator =(const Master&);

    void set_FIO(string);
    
    int get_count() { return count; }

    int get_dogcount();

    string get_FIO() { return FIO; }

    //Master get_master(int i);

    Dog get_dog(int i);

    void add_dog(Dog dog);

    void add_master(Master, Master*&);

    void show_masters(Master*);

    void show_dogs();
   
    ~Master();

};