#include "Header.h"

void Point::sum_and_multiply(int& sum_var, int& mult_var) const
{
    sum_var = x + y;
    mult_var = x * y;
}
void Point::show_results() const
{
    cout << "\n���������� x = " << x << endl;
    cout << "���������� y = " << y << endl;
    cout << "����� x,y = " << x + y << endl;
    cout << "������������ x,y = " << x * y << endl;
}

void Point::sum_and_multiply(int* sum, int* mult_var) const
{
    *sum = x + y;
    *mult_var = x * y;
}

//Point::Point()
//{
//    cout << "1";
//    x = 0;
//    y = 0;
//}

Point::Point(const int& value_x = 0, const int& value_y = 0)
{
    //cout << "2";
    x = value_x;
    y = value_y;
}

Point::Point(const Point& obj)
{
    x = obj.x;
    y = obj.y;
}

void Point::set_x(const int& value) { x = value; }
void Point::set_y(const int& value) { y = value; }

int Point::get_x() const { return x; }
int Point::get_y() const { return y; }





















