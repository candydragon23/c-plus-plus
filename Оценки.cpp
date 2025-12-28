#include <iostream>
#include <locale.h>
using namespace std;
int main()
{
    setlocale (LC_ALL, "Russian");
    cout << "Введите оценку : ";
    int n;
    cin >> n;
    switch (n)
    {
    case 1:
    cout << "Ваша оценка 1";
    break;
    case 2:
    cout << "Ваша оценка 2";
    break;
    case 3:
    cout << "Ваша оценка 3";
    break;
    case 4:
    cout << "Ваша оценка 4";
    break;
    case 5:
    cout << "Ваша оценка 5";
    break;
    default:
    cout << "Такой оценки нет";
    break;
    }
}
