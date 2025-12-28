#include <iostream>
#include <math.h>
#define _USE_MATH_DEFINES
#include <locale.h>
using namespace std;
int main()
{
    setlocale (LC_ALL, "Russian");
    double y,x,minx;
    int flageven1 = 1,flageven2 = 1,flageven3 = 1, flagodd1 = 1, flagodd2 = 1, flagodd3 = 1;
    cout << "Введите интервал x : ";
    cin >> x;
    for (minx = -x; minx <= x; minx += 0.1)
    {
       if (flageven1 == 1 && pow(x, 4) != pow(-x, 4))
           flageven1 = 0;
       if (flagodd1 == 1 && pow(-x, 4) != -(pow(x, 4)))
        flagodd1 = 0;
       if (x != 0 && flageven2 == 1 && (float)tan(x) != (float)tan(-x))
        flageven2 = 0;
       if (x != 0 && flagodd2 == 1 && (float)tan(-x) != (float)-(tan(x)))
        flagodd2 = 0;
       if (flageven3 == 1 && exp(x) != exp(-x))
        flageven3 = 0;
       if (flagodd3 == 1 && exp(-x) != -(exp(x)))
        flagodd3 = 0;
    }
       if (flageven1 == 1)
        cout << "Функция y = x^4 четная" << endl;
       else if (flagodd1 == 1)
        cout << "Функция y = x^4 нечетная" << endl;
       else
        cout << "Функция y = x^4 общего вида" << endl;
       if (flageven2 == 1)
        cout << "Функция y = tg(x) четная" << endl;
       else if (flagodd2 == 1)
        cout << "Функция y = tg(x) нечетная" << endl;
       else
        cout << "Функция y = tg(x) общего вида" << endl;
       if (flageven3 == 1)
        cout << "Функция y = e^x четная";
       else if (flagodd3 == 1)
        cout << "Функция y = e^x нечетная";
       else
        cout << "Функция y = e^x общего вида";
        return 0;
}
