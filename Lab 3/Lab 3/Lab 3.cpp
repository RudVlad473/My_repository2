#include <iostream>
using namespace std;

class B
{
protected:
    int b;
public:
    B(int bvalue) :b(bvalue) {};
    virtual void show() { cout << "b = " << b << endl; }
    virtual ~B() {};
};

class D1 :virtual public B
{
protected:
    int d1;
public:
    D1(int bvalue, int d1value) :B(bvalue), d1(d1value) {};
    virtual void show() override
    {
        cout << "d1 = " << d1 << endl << "b = " << b << endl;
        
    }
    virtual ~D1() {};
};

class D2 :virtual public B
{
protected:
    int d2;
public:
    D2(int bvalue, int d2value) :B(bvalue), d2(d2value) {};
    virtual void show() override
    {
        cout << "d2 = " << d2 << endl << "b = " << b << endl;
        
    }
    virtual ~D2() {};
};

class D3 :virtual private B
{
protected:
    int d3;
public:
    D3(int bvalue, int d3value) :B(bvalue), d3(d3value) {};
    virtual void show() override
    {
        cout << "d3 = " << d3 << endl << "b = " << b << endl;
        
    }
    virtual ~D3() {};
};

class D4 :private D1, virtual public D2
{
protected:
    int d4;
public:
    D4(int bvalue, int d1value, int d2value, int d4value) :B::B(bvalue), D1(0, d1value), D2(0, d2value), d4(d4value) {};
    virtual void show() override
    {
        cout << "d4 = " << d4 << endl << "d1 = " << d1 << endl << "d2 = " << d2 << endl;
        
    }
    virtual ~D4() {};
};

class D5 :virtual public D2, private D3
{
protected:
    int d5;
public:
    D5(int bvalue, int d2value, int d3value, int d5value) :B::B(bvalue), D2(0, d2value), D3(0, d3value), d5(d5value){};
    virtual void show() override
    {
        cout << "d5 = " << d5 << endl << "d2 = " << d2 << endl << "d3 = " << d3 << endl;
        
    }
    virtual ~D5() {};
};

int main()
{
    D4 d4(0,1,2,4);
    D5 d5(0, 2, 3, 5);
    d4.show();
    d5.show();
    
}


