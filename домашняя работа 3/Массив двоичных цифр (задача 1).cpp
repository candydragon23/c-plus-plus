#include <iostream>
#include <locale.h>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    int n,m = 0;
    cout << "¬ведите наибольшую степень двойки использующуюс€ дл€ задани€ числа M: ";
    cin >> n;
    int num[n];
    cout << "¬ведите массив двоичных чисел дл€ задани€ M: ";
    for(int i = 0; i < n; i++)
        cin >> num[i];
    int current = 1;
    for(int i = n - 1; i >= 0; i--)
    {
        if (num[i] == 1)
           m += current;
        current *= 2;
    }
    m++;
    current = 1;
    //cout << m << endl;
    int amount = 1;
    while (current * 2 <= m)
    {
        current *= 2;
        amount++;
    }
    //cout << current << endl;
    int numM1[amount];
    for(int i = 0; i < amount; i++)
    {
        if (m - current >= 0)
        {
           m -= current;
           numM1[i] = 1;
        }
        else
            numM1[i] = 0;
        current /= 2;
    }
    for (int i = 0; i < amount; i++)
        cout << numM1[i] << " ";
}
