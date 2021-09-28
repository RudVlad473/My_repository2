#include <iostream>
#include <iomanip>
using namespace std;

class two_d_matr
{
    int** matr;
    int strokes;
    int columns;
public:

    two_d_matr(two_d_matr& obj)
    {
        this->strokes = obj.strokes;
        this->columns = obj.columns;
        if (this->matr != nullptr)
        {
            for (int i = 0; i < this->strokes; ++i) delete[] matr[i];
            delete[] matr;
        }
        matr = new int* [this->strokes]{};
        for (int i = 0; i < this->strokes; ++i) matr[i] = new int[this->columns]{};
    }

    two_d_matr(int strokes, int columns)
    {
        this->strokes = strokes;
        this->columns = columns;
        matr = new int* [strokes] {};
        for (int i = 0; i < strokes; ++i) matr[i] = new int[columns] {};
    }

    two_d_matr take_out_submatr(int stroke_pos, int column_pos, int stroke_num, int column_num)
    {

        if (stroke_pos < 0 || stroke_pos > this->strokes 
            || column_pos < 0 || column_pos > this->columns 
            || stroke_num > this->strokes || column_num > this->columns) exit(0);
       
        two_d_matr temp(stroke_num, column_num);

        for (int i = stroke_pos, n = 0; i < stroke_num; ++i,++n)
        {
            for (int j = column_pos, m = 0; j < column_num; ++j, ++m) temp.set_num_by_coords(n, m, this->matr[i][j]);
        }




        return temp;
        
    }

    void generate_matr()
    {
        for (int i = 0; i < this->strokes; ++i)
        {
            for (int j = 0; j < this->columns; ++j)  this->matr[i][j] = rand() % 11;
        }

    }

    void show_matr()
    {
        for (int i = 0; i < strokes; ++i)
        {
            for (int j = 0; j < columns; ++j)  cout << setw(4) << matr[i][j];
            cout << endl;
        }
    }

    void find_min_coords(int& stroke_num, int& column_num)
    {
        int min(0);
        for (int i = 0; i < strokes; ++i)
        {
            for (int j = 0; j < columns; ++j)
            {
                if (min < matr[i][j])
                {
                    stroke_num = i;
                    column_num = j;
                }
            }
        }
    }

    int get_num_by_coords(int stroke, int column)
    {
        if (stroke < 0 || stroke > this->strokes || column < 0 || column > this->columns) return 0;
        else return matr[stroke][column];
    }

    void set_num_by_coords(int stroke, int column, int value)
    {
        if (stroke < 0 || stroke > this->strokes || column < 0 || column > this->columns) return;
        else matr[stroke][column] = value;
    }


    ~two_d_matr() 
    {
        for (int i = 0; i < this->strokes; ++i) delete[] matr[i];         
        delete[] matr;
    }
};



int main()
{
    srand(time(NULL));
    
    two_d_matr matr1(4, 4);
    matr1.generate_matr();
    matr1.show_matr();
    
    two_d_matr matr2(1, 1);
    matr2 = matr1.take_out_submatr(1, 1, 3, 2);
    matr2.show_matr();
    
}

