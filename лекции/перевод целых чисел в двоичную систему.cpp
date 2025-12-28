#include <iostream>
#include <locale.h>
using namespace std;
int main()
{
    setlocale (LC_ALL, "Russian");
    cout << "Препобразование в двоичную систему" << endl;
    int num;
    do
    {
        cout << "Введите целое число >0: ";
        cin >> num;
    }
    while (num <= 0);
    cout << "Двоичное число: ";
    int binValue = 0x40000000; // Значение двоичного разряда
    // Делим на 2 пока не получим меньшее число
    while (binValue > num)
        binValue >>= 1;
    while (binValue > 0)
    {
        if (num >= binValue)
        {
            cout << "1";
            num -= binValue;
        }
        else
            cout << "0";
        binValue >>= 1;
    }
    cout << endl;
    return 0;
}
