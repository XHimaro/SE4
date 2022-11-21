#ifndef _COMPLEX_H_
#define _COMPLEX_H_

#include <iostream>

using namespace std;

class Complex
{
    double real;
    double imag;

public:

    Complex (double a_real = 0, double a_imag = 0);
    Complex (const Complex &);
    ~Complex();

    Complex operator + (const Complex &);
    Complex operator - (const Complex &);
    Complex operator * (const Complex &);

    Complex operator + (const double &);
    Complex operator - (const double &);
    Complex operator * (const double &);
    Complex operator / (const double &);

    Complex & operator += (const Complex &);
    Complex & operator -= (const Complex &);
    Complex & operator *= (const Complex &);
    Complex & operator  = (const Complex &);

    Complex & operator += (const double &);
    Complex & operator -= (const double &);
    Complex & operator *= (const double &);
    Complex & operator /= (const double &);
    Complex & operator  = (const double &);

    friend istream & operator >> (istream &, Complex &);
    friend ostream & operator << (ostream &, Complex &);

    friend Complex operator + (const double &, const Complex &);
    friend Complex operator - (const double &, const Complex &);
    friend Complex operator * (const double &, const Complex &);

    void Set (double a_real, double a_imag = 0);
    operator double();
    double abs();
};
#endif

