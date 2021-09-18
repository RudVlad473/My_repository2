#include "Header.h"

void Complex::add_complex(const int &r_value, const int &m_value)
{
    r += r_value;
    m += m_value;
}

void Complex::add_complex(const Complex& complex)
{
    this->r += complex.r;
    this->m += complex.m;
}

void Complex::show_complex() const
{
    if (m > 0) { cout << r << " + " << m << "i"; }
    else { cout << r << " - " << -m << "i"; }
}

void Complex::add_to_r(const int &value) { r += value; }
void Complex::add_to_m(const int &value) { m += value; }

Complex::Complex()
{
    r = 0;
    m = 1;
}

Complex::Complex(int r_value, int m_value)
{
    r = r_value;
    m = m_value;
}

void Complex::set_r(const int& r_value) { r = r_value; }
void Complex::set_m(const int& m_value) { m = m_value; }