#include <iostream>
#include <locale.h>
using namespace std;
int d = 24; //Глобальная переменная которая может быть использована везде
int getNOD (int a, int b)
{
    while (a != b)
    {
        if (a < b)
            b = b - a;
        else
            a = a - b;
    }
    return a;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Поиск НОД 3х чисел" << endl;
    int a = 0, b = 0, c = 0;
    do
    {
        cout << "Введите натуральные A, B, C:" << endl;
        cin >> a >> b >> c;
    } while (a <= 0 || b <= 0 || c <= 0);
    // Функция вызвана дважды (!)
    int result = getNOD(getNOD(a,b) ,d);
    cout << "НОД(" << a << "," << b << "," << d << ")=" << result << endl;
    return 0;
}

