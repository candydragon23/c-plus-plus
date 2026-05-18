#ifndef RATIONAL_H
#define RATIONAL_H
class RationalException {};
class Rational
{
private:
    int numer;
    int denom;
    void simplify();
public:
    Rational ();
    Rational (int number);
    Rational (int n, int d);
    Rational (double number);
    int getNumer() const;
    int getDenom() const;
    Rational& operator += (const Rational& r);
    Rational operator + (const Rational& r) const;
    Rational operator - () const;
    Rational& operator -= (const Rational& r);
    Rational operator - (const Rational& r) const;
    Rational& operator *= (const Rational& r);
    Rational operator * (const Rational& r) const;
    Rational& operator /= (const Rational& r);
    Rational operator / (const Rational& r) const;
    friend Rational operator + (int number, const Rational& r);
    friend Rational operator - (int number, const Rational& r);
    friend Rational operator * (int number, const Rational& r);
    friend Rational operator / (int number, const Rational& r);
    static Rational sqrt(const Rational& r);
    Rational& operator ++ ();
    Rational operator ++ (int);
    Rational& operator -- ();
    Rational operator -- (int);
    bool operator == (const Rational& r) const;
    bool operator != (const Rational& r) const;
    bool operator < (const Rational& r) const;
    bool operator > (const Rational& r) const;
    bool operator <= (const Rational& r) const;
    bool operator >= (const Rational& r) const;
    friend bool operator == (int number, const Rational& r);
    friend bool operator != (int number, const Rational& r);
    friend bool operator < (int number, const Rational& r);
    friend bool operator > (int number, const Rational& r);
    friend bool operator <= (int number, const Rational& r);
    friend bool operator >= (int number, const Rational& r);
    explicit operator int() const;
    explicit operator double() const;
    friend istream& operator >> (istream& in, Rational& r);
    friend ostream& operator << (ostream& out, const Rational& r);
};
#endif // RATIONAL_H
