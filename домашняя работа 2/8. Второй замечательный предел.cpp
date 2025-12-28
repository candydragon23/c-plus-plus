#include <iostream>
#include <locale.h>
#include <math.h>
#define _USE_MATH_DEFINES
using namespace std;
int main()
{
    setlocale (LC_ALL, "Russian");
    cout << "Введите погрешность epsilon : ";
    double epsilon,n = 1;
    cin >> epsilon;
    cout << pow(1 + 1 / n, n) << " n = " << n << endl;
    while ((pow(1 + 1 / n, n)) < (M_E - epsilon))
    {
        n++;
        cout << pow(1 + 1 / n, n) << " n = " << n << endl;
    }
    cout << "Погрешность будет меньше чем epsilon при n = " << n;
    return 0;
}
