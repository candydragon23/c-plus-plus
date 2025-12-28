#include <iostream>
#include <math.h>
#define _USE_MATH_DEFINES
#include <locale.h>
using namespace std;
int main()
{
    setlocale (LC_ALL, "Russian");
    int flag1 = 1,flag2 = 1,flag3 = 1;
    double t,T,x,inter;
    cout << "Введите период T и интервал x [0 x*T] : ";
    cin >> T >> x;
    inter = T * x;
    for (t = 0; t <= inter - T; t += T)
    {
        if (flag1 == 1 && pow(sin(M_PI * (t + 0.5)), 2) != pow(sin(M_PI * (t + T + 0.5)), 2))
         flag1 = 0;
        if (flag2 == 1 && (float)tan(M_PI * (t + 0.25)) != (float)tan(M_PI * (t + T + 0.25)))
            flag2 = 0;
    }
    T *= 2;
    inter *= 2;
    for (t = 0; t <= inter - T; t += T)
        if (flag3 == 1 && t != -0.5 && sin((t + 0.5) * M_PI) / ((t + 0.5) * M_PI) != sin((t + T + 0.5) * M_PI) / ((t + T + 0.5) * M_PI))
            flag3 = 0;
    if (flag1 == 1)
        cout << "Функция sin^2(x) периодична" << endl;
    else
        cout << "Функция sin^2(x) не периодична" << endl;
    if (flag2 == 1)
        cout << "Функция tg(x) периодична" << endl;
    else
        cout << "Функция tg(x) не периодична" << endl;
    if (flag3 == 1)
        cout << "Функция sin(x)/x периодична";
    else
        cout << "Функция sin(x)/x не периодична";
    return 0;
}
