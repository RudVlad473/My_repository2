#include "master_and_dog.h"

Dog::Dog()
{
    name = "";
    weight = 0;
    age = 0;
}

Dog::Dog(string thename, int theweight, int theage)
{
    name = thename;
    weight = theweight;
    age = theage;
}

Dog::Dog(const Dog& obj)
{
    name = obj.name;
    weight = obj.weight;
    age = obj.age;
}

void Dog::set_name(string thename) { name = thename; }
void Dog::set_weight(int theweight) { weight = theweight; }
void Dog::set_age(int theage) { age = theage; }

string Dog::get_name() { return name; }
int Dog::get_weight() { return weight; }
int Dog::get_age() { return age; }


Master::Master()
{
    ++count;
    FIO = "";
    dogcount = 0;
    dogs = nullptr;
    this->add_master();
}

Master::Master(Master& master)
{
    master.count = this->count;
    master.dogcount = this->dogcount;
    master.FIO = this->FIO;
    for (int i = 0; i < this->dogcount; ++i) { master.add_dog(this->dogs[i]); }
    for (int i = 0; i < this->count; ++i) { master.add_master(this->masters[i]); }  
}

void Master::set_FIO(string theFIO, int dogcount) { FIO = theFIO; }

int Master::get_dogcount() { return dogcount; }

void Master::add_dog(Dog dog = Dog())
{
    if (dogs == nullptr)
    {
        ++dogcount;

        dogs = new Dog[dogcount];
        dogs[0] = dog;
    }
    else
    {
        Dog* dummyArr = new Dog[dogcount];
        for (int l = 0; l < dogcount; ++l) { dummyArr[l] = this->dogs[l]; }

        delete[] dogs;
        dogs = new Dog[dogcount + 1];

        for (int l = 0; l < dogcount; ++l) { dogs[l] = dummyArr[l]; }

        delete[] dummyArr;
        ++dogcount;
    }
}

void Master::add_master(Master master = Master())
{
    if (masters == nullptr)
    {
        ++count;

        masters = new Master[count];
        masters[0] = master ;
    }
    else
    {
        Master* dummyArr = new Master[count];
        for (int l = 0; l < count; ++l) { dummyArr[l] = this->masters[l]; }

        delete[] masters;
        masters = new Master[count + 1];

        for (int l = 0; l < count; ++l) { masters[l] = dummyArr[l]; }

        delete[] dummyArr;
        ++count;
    }
}

void Master::show_dogs()
{
    for (int i = 0; i < dogcount; ++i)
    {
        cout 
            << setw(9) 
            << "Возраст: " << dogs[i].get_age() << endl 
            << setw(9) 
            << "Кличка: " 
            << dogs[i].get_name() << endl 
            << setw(9) 
            << "Вес: " << dogs[i].get_weight() << endl;
    }
}

Master::~Master() 
{ 
    delete[] dogs;
    delete[] masters;
}











































