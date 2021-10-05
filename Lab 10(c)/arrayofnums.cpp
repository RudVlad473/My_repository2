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

ArrayOfNums::ArrayOfNums(const int &size)
{  
    //if (this->arr != nullptr) this->~ArrayOfNums();
    if (size < 0) exit(0);
    this->size = size;
    this->arr = new int[this->size] {};
}

ArrayOfNums::ArrayOfNums(const int &amountofnums, const int &min, const int &max)
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

ArrayOfNums::ArrayOfNums(const ArrayOfNums& a, const int &max_value)
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
    //if (this->arr != nullptr) this->~ArrayOfNums();
    this->size = a.size;
    this->arr = new int[this->size];
    for (int i = 0; i < this->size; ++i) this->arr[i] = a.arr[i];
   
}

ArrayOfNums::~ArrayOfNums()
{
    delete[]this->arr; 
    this->arr = nullptr;
}

int ArrayOfNums::get_size() const
{
    return size;
}

void ArrayOfNums::fill_no_repeat()
{
    for (int i = 0; i < size; ++i)
    {
        arr[i] = (rand() % 11);
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

void ArrayOfNums::show_arr() const
{
    
    
    for (int i = 0; i < this->size; ++i)
    {
        
        if (i % 5 == 0 && i != 0) cout << endl;
        cout << setw(4) << arr[i];

    }
}

int ArrayOfNums::find_max() const
{
    int max_value = 0;
    for (int i = 0; i < size; ++i) { if (max_value < arr[i]) max_value = arr[i]; }
    return max_value;
}

ArrayOfNums& ArrayOfNums::operator = (const ArrayOfNums& obj)
{
    if (this->arr != nullptr) this->~ArrayOfNums();
    this->size = obj.size;
    this->arr = new int[this->size];
    for (int i = 0; i < this->size; ++i) this->arr[i] = obj.arr[i];
    return *this;
}

ArrayOfNums ArrayOfNums::Union(const ArrayOfNums &newarr)
{
    
    ArrayOfNums union_arr(this->size + newarr.size);
    for (int i = 0; i < this->size; ++i) { union_arr.arr[i] = this->arr[i]; }
    for (int i = this->size , j = 0; i < newarr.size + this->size; ++i, ++j) { union_arr.arr[i] = newarr.arr[j]; }
    return union_arr;
}

ArrayOfNums ArrayOfNums::Intersection(const ArrayOfNums &newarr)
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

void ArrayOfNums::Difference(const ArrayOfNums &newarr, ArrayOfNums &to_arr)
{
    //ArrayOfNums interarr = this->Intersection(newarr);
    //ArrayOfNums differencearr(this->size - interarr.size);

    //int temp;

    //for (int i = 0; i < this->size; ++i) 
    //{
    //    temp = this->arr[i - 1];

    //    for (int j = 0; j < interarr.size; ++j)
    //    {
    //        if (temp == interarr.arr[j])
    //        {
    //            i++;
    //            goto duplicate; //added this line
    //        }
    //    }

    //    differencearr.arr[i] = this->arr[i - 1];
    //    duplicate:
    //    int k = 0;

    //}
    //

    //return differencearr;

    /*Нахождение массива, содержащего дубликаты*/
    int duplics_count = 0;
    for (int i = 0; i < this->size; ++i)
    {
        for (int j = 0; j < newarr.size; ++j)
        {
            if (this->arr[i] == newarr.arr[j]) ++duplics_count;
        }
    }

    if (duplics_count == 0)
    {
        to_arr = *this;
        return;
    }

    ArrayOfNums duplics_arr(duplics_count);
   
    for (int i = 0, k = 0; i < this->size; ++i)
    {
        for (int j = 0; j < newarr.size; ++j)
        {
            if (this->arr[i] == newarr.arr[j])
            {
                duplics_arr.arr[k] = this->arr[i];
                ++k;
            }
        }
    }
    /*------------------------------------*/
    /*cout << "\nМассив дублов:\n";
    duplics_arr.show_arr();
    cout << endl;*/

    ArrayOfNums differarr(this->size - duplics_count);

    for (int i = 0, k = 0; i < this->size; ++i)
    {
        
        for (int j = 0; j < newarr.size; ++j)
        {
            if (this->arr[i] == duplics_arr.arr[j])
            {
                break;
            }
            else if (j == (newarr.size-1))
            {
                differarr.arr[k] = this->arr[i];
                ++k;
            }
            
        }
    }

    to_arr = differarr;


   
}

void ArrayOfNums::Disjunctive_sum(const ArrayOfNums& newarr, ArrayOfNums& to_arr)
{
    ArrayOfNums intersec = this->Intersection(newarr);
    /*cout << "\nМассив пересеч.:\n";
    intersec.show_arr();
    cout << endl;*/


    ArrayOfNums unionarr = this->Union(newarr);
    /*cout << "\nМассив объед.:\n";
    unionarr.show_arr();
    cout << endl;*/
    ArrayOfNums resultarr(unionarr.size - 2*intersec.size);
    for (int i = 0, k = 0; i < unionarr.size; ++i)
    {

        for (int j = 0; j < intersec.size; ++j)
        {
            if (unionarr.arr[i] == intersec.arr[j])
            {
                break;
            }
            else if (j == (intersec.size - 1))
            {
                resultarr.arr[k] = unionarr.arr[i];
                ++k;
            }

        }
    }

    to_arr = resultarr;
}
