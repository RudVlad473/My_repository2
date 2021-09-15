#include "arrayofnums.h"

ArrayOfNums::ArrayOfNums()
{
    size = 10;
    arr = new int[size];
    for (int i = 0; i < size; ++i)
    {
        arr[i] = (rand() % 41 - 20);
        for (int j = 0; j < i; ++j)
        {
            if (arr[i] == arr[j])
            {
                arr[i] = 0;
                i--;
            }
        }
    }
}

ArrayOfNums::ArrayOfNums(int size)
{  
    this->size = size;
    arr = new int[size] {};
}

ArrayOfNums::ArrayOfNums(int amountofnums, int min, int max)
{
    size = amountofnums;
    arr = new int[amountofnums];
    for (int i = 0; i < size; ++i)
    {
        arr[i] = (rand() % (max - min + 1) + min);
        for (int j = 0; j < i; ++j)
        {
            if (arr[i] == arr[j])
            {
                arr[i] = 0;
                i--;
            }
        }
    }
}

ArrayOfNums::ArrayOfNums(ArrayOfNums& a, int max_value)
{
    this->size = a.size;
    arr = new int[this->size];
    int max_num = find_max();
    for (int i = 0; i < this->size; ++i)
    {
        if (a.arr[i] > max_value) arr[i] = max_num;
        else arr[i] = a.arr[i];
    }
}

ArrayOfNums::ArrayOfNums(const ArrayOfNums& a)
{  
    this->size = a.size;
    this->arr = new int[this->size];
    for (int i = 0; i < this->size; ++i) this->arr[i] = a.arr[i];
   
}

ArrayOfNums::~ArrayOfNums()
{
    delete[]this->arr; 
}

int ArrayOfNums::get_size()
{
    return size;
}

void ArrayOfNums::fill_no_repeat()
{
    for (int i = 0; i < size; ++i)
    {
        arr[i] = (rand() % 41 - 20);
        for (int j = 0; j < i; j++)
        {
            if (arr[i] == arr[j])
            {
                arr[i] = 0;
                i--;
            }
        }
    }
}

void ArrayOfNums::show_arr()
{
    for (int i = 0; i < this->size; ++i)
    {
        if (i % 5 == 0 && i != 0) cout << endl;
        cout << setw(4) << arr[i];

    }
}

int ArrayOfNums::find_max()
{
    int max_value = 0;
    for (int i = 0; i < size; ++i) { if (max_value < arr[i]) max_value = arr[i]; }
    return max_value;
}

ArrayOfNums ArrayOfNums::Union(ArrayOfNums newarr)
{
    
    ArrayOfNums union_arr(this->size + newarr.size);
    for (int i = 0; i < this->size; ++i) { union_arr.arr[i] = this->arr[i]; }
    for (int i = this->size , j = 0; i < newarr.size + this->size; ++i, ++j) { union_arr.arr[i] = newarr.arr[j]; }
    return union_arr;
}

ArrayOfNums ArrayOfNums::Intersection(ArrayOfNums newarr)
{
    int newsize = 0;
    for (int i = 0; i < this->size; ++i)
    {
        for (int j = 0; j < newarr.size; ++j) if (this->arr[i] == newarr.arr[j]) ++newsize;
    }

    ArrayOfNums interarr(newsize);
    for (int i = 0, k = 0; i < this->size; ++i)
    {
        for (int j = 0; j < newarr.size; ++j)
        {
            if (this->arr[i] == newarr.arr[j])
            {
                interarr.arr[k] = this->arr[i];
                ++k;
            }
        }

    }
    return interarr;
}

ArrayOfNums ArrayOfNums::Difference(ArrayOfNums newarr)
{
    ArrayOfNums interarr = this->Intersection(newarr);
    ArrayOfNums differencearr(this->size - interarr.size);

    int temp;

    for (int i = 0; i < this->size; ++i) 
    {
        temp = this->arr[i - 1];

        for (int j = 0; j < interarr.size; ++j)
        {
            if (temp == interarr.arr[j])
            {
                i++;
                goto duplicate; //added this line
            }
        }

        differencearr.arr[i] = this->arr[i - 1];
        duplicate:
        int k = 0;

    }
    

    return differencearr;

   
}
