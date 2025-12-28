#include <iostream>
#include <locale.h>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Перевод из p-ричной системы счисления в 10-ную" << endl;
    int p;
    do
    {
        cout << "Ведите основание системы p (2...36): ";
        cin >> p;
    } while(p < 2 || p > 36);
    const int MAX_LEN = 30; // Максимальная длина числа
    cout << "Введите число (не более " << MAX_LEN << " знаков): ";
    char x[MAX_LEN + 1];
    cin.getline(x, 1, '\n');
    cin.getline(x, MAX_LEN + 1, '\n'); //Ввод числа
    int n = 0;
    for (int i = 0; x[i] != 0; i++) // Перебор знаков числа до ноль символа
    {
        n *= p;
        int d = -1; // Цифра
        if (x[i] >= '0' && x[i] <= '9')
            d = x[i] - '0'; // '0'...'9' => 0...9
        else if (x[i] >= 'a' && x[i] <= 'z')
            d = 10 + x[i] - 'a'; // 'a'...'z' => 10...35
        else if (x[i] >= 'A' && x[i] <= 'Z')
            d = 10 + x[i] - 'A'; // 'A'...'Z' => 10...35
        if (d < 0 || d >= p)
        {
            cout << "Цифра " << x[i] << " некорректна" << endl;
            return -1;
        }
        n += d;
    }
    cout << "Число в десятичной системе счисления: " << n << endl;
    return 0;
}
