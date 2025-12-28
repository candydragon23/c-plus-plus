#include <iostream>
#include <locale.h>
#include <math.h>
using namespace std;
int main()
{
    double epsilon, x = 1;
    setlocale (LC_ALL, "Russian");
    cout << "Введите погрешность epsilon : ";
    cin >> epsilon;
    cout << sin(x) / x << " x = " << x << endl;
    while ((sin(x) / x) < (1 - epsilon))
    {
        x /= 2;
        cout << sin(x) / x << " x = " << x << endl;
    }
    cout << "Погрешность будет меньше чем epsilon при x = " << x;
    return 0;
}
