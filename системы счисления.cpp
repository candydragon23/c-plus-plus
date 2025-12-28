#include <iostream>
#include <locale.h>
#include <cmath>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "¬ведите систему счислени€: ";
    int n,len;
    cin >> n;
    cout << "¬ведите длину числа: ";
    cin >> len;
    char m[len];
    cout << "¬ведите число дл€ перевода: ";
    cin >> m;
    int anslen = len * log(n) / log(10);
    char ans[anslen];
    for (int i = 0; m[i] != 0; i++)
    {
        int a = (int)m[i];
    }
}
