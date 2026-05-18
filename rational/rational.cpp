#include <iostream>
using namespace std;
#include "rational.h"
Rational::Rational()
{
    numer = 0;
    denom = 1;
}
Rational::Rational(int number)
{
    numer = number;
    denom = 1;
}
Rational::Rational(int n, int d)
{
    numer = n;
    if (d == 0)
        throw RationalException();
    denom = d;
    simplify();
}
Rational::Rational(double number)
{
    numer = number * 100000;
    denom = 100000;
    simplify();
}
int Rational::getNumer() const
{
    return numer;
}
int Rational::getDenom() const
{
    return denom;
}
void Rational::simplify()
{
    int a = abs(numer), b = abs(denom);
    while (b != 0)
    {
        int t = b;
        b = a % b;
        a = t;
    }
    numer /= a;
    denom /= a;
    if (denom < 0)
    {
        numer = -numer;
        denom = -denom;
    }
}
Rational Rational::sqrt(const Rational& r)
{
    int a = r.numer, b = r.denom;
    for (int i = 0; i < 25; i++)
    {
        if (a == 0 || b == 0)
            throw RationalException();
        if (r.numer / a < 0 || r.denom / b < 0)
            throw RationalException();
        a = (a + r.numer / a) / 2;
        b = (b + r.denom / b) / 2;
        if (a < 0 || b < 0)
            throw RationalException();
    }
    return Rational(a, b);
}
Rational& Rational::operator += (const Rational& r)
{
    if (denom == r.denom)
    {
        if (numer > 0 && r.numer > 0 && numer > INT_MAX - r.numer)
            throw RationalException();
        if (numer < 0 && r.numer < 0 && numer < INT_MIN - r.numer)
            throw RationalException();
        numer += r.numer;
        simplify();
        return *this;
    }
    if (abs(numer) > INT_MAX / abs(r.denom) || abs(r.numer) > INT_MAX / abs(denom))
        throw RationalException();
    if (numer * r.denom > 0 && r.numer * denom > 0 && numer * r.denom > INT_MAX - denom * r.numer)
        throw RationalException();
    if (numer * r.denom < 0 && r.numer * denom < 0 && numer * r.denom < INT_MIN - denom * r.numer)
        throw RationalException();
    if (abs(denom) > INT_MAX / abs(r.denom))
        throw RationalException();
    numer = (numer * r.denom + denom * r.numer);
    denom *= r.denom;
    simplify();
    return *this;
}
Rational Rational::operator + (const Rational& r) const
{
    Rational res(*this);
    return res += r;
}
Rational Rational::operator - () const
{
    Rational r(-numer, denom);
    return r;
}
Rational& Rational::operator -= (const Rational& r)
{
    return (*this += (-r));
}
Rational Rational::operator - (const Rational& r) const
{
    Rational res(*this);
    return res -= r;
}
Rational& Rational::operator *= (const Rational& r)
{
    if ((numer != 0 && r.numer != 0 && abs(numer) > INT_MAX / abs(r.numer)) || abs(denom) > INT_MAX / abs(r.denom))
        throw RationalException();
    numer *= r.numer;
    denom *= r.denom;
    simplify();
    return *this;
}
Rational Rational::operator * (const Rational& r) const
{
    Rational res(*this);
    return res *= r;
}
Rational& Rational::operator /= (const Rational& r)
{
    if (r.numer == 0)
        throw RationalException();
    Rational res(r.denom, r.numer);
    return (*this *= res);
}
Rational Rational::operator / (const Rational& r) const
{
    Rational res(*this);
    return res /= r;
}
Rational operator + (int number, const Rational& r)
{
    return (Rational)number + r;
}
Rational operator - (int number, const Rational& r)
{
    return (Rational)number - r;
}
Rational operator * (int number, const Rational& r)
{
    return (Rational)number * r;
}
Rational operator / (int number, const Rational& r)
{
    return (Rational)number / r;
}
Rational& Rational::operator ++ ()
{
    numer += denom;
    return *this;
}
Rational Rational::operator ++ (int)
{
    Rational r(*this);
    numer += denom;
    return r;
}
Rational& Rational::operator -- ()
{
    numer -= denom;
    return *this;
}
Rational Rational:: operator -- (int)
{
    Rational r(*this);
    numer -= denom;
    return r;
}
bool Rational::operator == (const Rational& r) const
{
    return (numer == r.numer) && (denom == r.denom);
}
bool Rational::operator != (const Rational& r) const
{
    return !(*this == r);
}
bool Rational::operator < (const Rational& r) const
{
    if (numer > 0 && r.numer < 0)
        return false;
    if (numer < 0 && r.numer > 0)
        return true;
    return (*this - r).numer < 0;
}
bool Rational::operator <= (const Rational& r) const
{
    if (numer > 0 && r.numer < 0)
        return false;
    if (numer < 0 && r.numer > 0)
        return true;
    return (*this - r).numer <= 0;
}
bool Rational::operator > (const Rational& r) const
{
    return !(*this <= r);
}
bool Rational::operator >= (const Rational& r) const
{
    return !(*this < r);
}
bool operator == (int number, const Rational& r)
{
    return (Rational)number == r;
}
bool operator != (int number, const Rational& r)
{
    return (Rational)number != r;
}
bool operator < (int number, const Rational& r)
{
    return (Rational)number < r;
}
bool operator > (int number, const Rational& r)
{
    return (Rational)number > r;
}
bool operator <= (int number, const Rational& r)
{
    return (Rational)number <= r;
}
bool operator >= (int number, const Rational& r)
{
    return (Rational)number >= r;
}
Rational::operator int() const
{
    return numer / denom;
}
Rational::operator double() const
{
    return ((double) numer) / denom;
}
istream& operator >> (istream& in, Rational& r)
{
    in >> r.numer >> r.denom;
    if (r.denom == 0)
        throw RationalException();
    return in;
}
ostream& operator << (ostream& out, const Rational& r)
{
    out << r.numer << "/" << r.denom;
    return out;
}
