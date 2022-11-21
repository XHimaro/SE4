#include <iostream>
#include <cmath>
#include "complex.h"

using namespace std;

Complex::Complex (double a_real, double a_imag)
{
    cout << "special for third test" << endl;
    real = a_real;
    imag = a_imag;
}

Complex::Complex (const Complex & complex_number)
{
    real = complex_number.real;
    imag = complex_number.imag;
}

Complex::~Complex()
{
    real = 0.0;
    imag = 0.0;
}

void Complex::Set (double a_real, double a_imag)
{
    real = a_real;
    imag = a_imag;
}

Complex::operator double()
{
    return abs();
}

double Complex::abs()
{
    return sqrt (real*real + imag*imag);
}

Complex Complex::operator + (const Complex & complex_number)
{
    Complex result;
    result.real = real + complex_number.real;
    result.imag = imag + complex_number.imag ;
    return result;
}

Complex Complex::operator - (const Complex & complex_number)
{
    Complex result;
    result.real = real - complex_number.real;
    result.imag = imag - complex_number.imag;
    return result;
}

Complex Complex::operator + (const double & real_val)
{
    Complex result;
    result.real = real + real_val;
    result.imag = imag;
    return result;
}

Complex Complex::operator - (const double & real_val)
{
    Complex result (*this);
    result.real = real - real_val;
    return result;
}

Complex Complex::operator * (const Complex & complex_number)
{
    Complex result;
    result.real = real*complex_number.real - imag*complex_number.imag;
    result.imag = real*complex_number.imag + imag*complex_number.real;
    return result;
}

Complex Complex::operator * (const double & real_val)
{
    Complex result;
    result.real = real*real_val;
    result.imag = imag*real_val;
    return result;
}

Complex Complex::operator / (const double & real_val)
{
    Complex result;
    result.real = real/real_val;
    result.imag = imag/real_val;
    return result;
}

Complex & Complex :: operator += (const Complex & complex_number)
{
    real += complex_number.real;
    imag += complex_number.imag;
    return *this;
}

Complex & Complex::operator -= (const Complex & complex_number)
{
    real -= complex_number.real;
    imag -= complex_number.imag;
    return *this;
}

Complex & Complex::operator *= (const Complex & complex_number)
{
    double tmp_real = real;
    real = real*complex_number.real - imag*complex_number.imag;
    imag = imag*complex_number.real + tmp_real*complex_number.imag;
    return *this;
}

Complex & Complex::operator += (const double & real_val)
{
    real += real_val;
    return *this;
}

Complex & Complex::operator -= (const double & real_val)
{
    real -= real_val;
    return *this;
}

Complex & Complex::operator *= (const double & real_val)
{
    real *= real_val;
    imag *= real_val;
    return *this;
}

Complex & Complex::operator /= (const double & real_val)
{
    real /= real_val;
    imag /= real_val;
    return *this;
}

Complex & Complex::operator = (const Complex & complex_number)
{
    real = complex_number.real;
    imag = complex_number.imag;
    return *this;
}

Complex & Complex::operator = (const double & real_val)
{
    real = real_val;
    imag = 0.0;
    return *this;
}

istream & operator >> (istream & stream, Complex & complex_number)
{
    char tmp[256];
    stream >> complex_number.real >> complex_number.imag >> tmp;
    return stream;
}

ostream & operator << (ostream & stream, Complex & complex_number)
{
    stream << complex_number.real;
    if (! (complex_number.imag < 0)) stream << '+';
    stream << complex_number.imag << 'i';
    return stream;
}

Complex operator + (const double & real_val, const Complex & complex_number)
{
    Complex result;
    result.real = real_val + complex_number.real;
    result.imag = complex_number.imag;
    return result;
}

Complex operator - (const double & real_val, const Complex & complex_number)
{
    Complex result;
    result.real = real_val - complex_number.real;
    result.imag = - complex_number.imag;
    return result;
}

Complex operator * (const double & real_val, const Complex & complex_number)
{
    Complex result;
    result.real = real_val*complex_number.real;
    result.imag = real_val*complex_number.imag;
    return result;
}
