#include <iostream>
#include <locale.h>
using namespace std;
#include "rational.h"
int main()
{
    setlocale(LC_ALL, "Russian");
    Rational u, v;
    cout << "Введите значение u = m / n в формате: m n" << endl;
    cin >> u;
    cout << "Введите значение v = m / n в формате: m n" << endl;
    cin >> v;
    try {
        cout << "u + v = " << u + v << endl;
        cout << "u - v = " << u - v << endl;
        cout << "u * v = " << u * v << endl;
        cout << "u / v = " << u / v << endl;
    } catch (RationalException) {
        cout << "Ошибка переполнения или деление на 0" << endl;
    }
    Rational z(28, 1);
    double x = 0.5;
    cout << Rational::sqrt(z) << endl;
    cout << "z = " << z << " (double)z = " << (double)z << " x = " << x << " (Rational)x = " << (Rational)x << endl;
    Rational a(1, 2), b(-1, 6);
    cout << "a = " << a << " b = " << b << " a + b = " << a + b << endl;
    cout << "a(" << a << ") *= b(" << b << ")" << endl;
    a *= b;
    cout << "a = " << a << " b = " << b << " a - b = " << a - b << endl;
    Rational c = 3;
    cout << "b = " << b << " c = " << c << " b / c = " << b / c << endl;
    Rational e(7,8), f(5,12);
    cout << "e = " << e << " f = " << f << " e + f = ?" << endl;
    cout << "Введите результат g = m / n в формате: m n" << endl;
    Rational g;
    cin >> g;
    if (e + f != g)
        cout << "Неправильно! e + f = "<< e + f << endl;
    else
        cout << "Правильно!" << endl;
    Rational h, i, j;
    cout << "Введите значение a = m / n квадратного уравнения в формате: m n" << endl;
    cin >> h;
    cout << "Введите значение b = m / n квадратного уравнения в формате: m n" << endl;
    cin >> i;
    cout << "Введите значение c = m / n квадратного уравнения в формате: m n" << endl;
    cin >> j;
    try {
        Rational D;
        if (j.getDenom() * h.getDenom() == i.getDenom())
        {
            D = Rational((i.getNumer() * i.getNumer()) - (4 * h.getNumer() * j.getNumer() * i.getDenom()), i.getDenom() * i.getDenom());
        }
        else
            D = (i * i) - (4 * h * j);
        cout << D << endl;
        if (0 > D)
            cout << "Корней нет" << endl;
        else if (D == 0)
            cout << "Корень уравнения равен: x = " << -i / (2 * h) << endl;
        else
            cout << "Корни квадратного уравнения равны: x1 =  " << ((Rational::sqrt(D)) - i) / (2 * h) << ", x2 = "  << (-(Rational::sqrt(D)) - i) / (2 * h)<< endl;
    } catch (RationalException) {
        cout << "Ошибка переполнения или деление на 0" << endl;
    }
    Rational k(2, 3), l(3, 2);
    cout << "k = " << k << " l = " << l << " k < l?" << endl;
    if (k < l)
        cout << "Верно" << endl;
    else
        cout << "Неверно" << endl;
    cout << "k = " << k << " l = " << l << " k > l?" << endl;
    if (k > l)
        cout << "Верно" << endl;
    else
        cout << "Неверно" << endl;
    k = l;
    cout << "k = " << k << " l = " << l << " k <= l?" << endl;
    if (k <= l)
        cout << "Верно" << endl;
    else
        cout << "Неверно" << endl;
    return 0;
}
