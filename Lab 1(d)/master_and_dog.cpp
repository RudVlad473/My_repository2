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
    //this->add_master(Master("None"));
}

Master::Master(string name)
{
    this->FIO = name;
}

Master::Master(const Master& master)
{
    this->count = master.count;
    this->dogcount = master.dogcount;
    this->FIO = master.FIO;
    for (int i = 0; i < master.dogcount; ++i) { this->add_dog(master.dogs[i]); }
    //for (int i = 0; i < this->count; ++i) { this->add_master(master.masters1[i]); }
}

Master Master::operator =(const Master& master)
{
    this->count = master.count;
    this->dogcount = master.dogcount;
    this->FIO = master.FIO;
    for (int i = 0; i < master.dogcount; ++i) { this->add_dog(master.dogs[i]); }
    //for (int i = 0; i < this->count; ++i) { this->add_master(master.masters1[i]); }
    return *this;
}

void Master::set_FIO(string theFIO) { FIO = theFIO; }

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

void Master::add_master(Master*& masters, Master master = Master())
{
    if (masters == nullptr)
    {
        ++count;

        masters = new Master[count];
        masters[0] = master;
    }
    else
    {
        Master* dummyArr = new Master[count];
        for (int l = 0; l < count; ++l) { dummyArr[l] = masters[l]; }

        delete[] masters;
        masters = new Master[count + 1];

        for (int l = 0; l < count; ++l) { masters[l] = dummyArr[l]; }

        delete[] dummyArr;
        ++count;
    }
}


Dog Master::get_dog(int i)
{

    return this->dogs[i];
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

void Master::show_masters(Master *masters)
{
    for (int i = 0; i < this->count; ++i) 
    {
        if (i == 0) cout << "\nКол-во членов клуба: " << this->count << endl;
        cout << "\nКол-во собак у мастера:" << masters[i].dogcount;
        cout << "ФИО: " << masters[i].FIO << endl << endl;
    }
    
}

Master::~Master() 
{ 
    delete[] dogs;
    //delete[] masters1;
}











































