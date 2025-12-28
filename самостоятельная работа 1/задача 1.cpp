#include <iostream>
#include <locale.h>
#include <string.h>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "¬ведите снилс в формате 111-111-111 11: ";
    string str;
    int mult = 9,contsum = 0,check;
    char a = "-";
    cin >> str >> check;
    char snils[12];
    for (int i = 0; i < 12; i++)
    {
        snils[i] = str[i];
        //cout << snils[i];
    }
    for (int i = 0; i < 12; i++)
    {
        if (snils[i] != a)
        {
            contsum += mult * (int) snils[i];
            mult--;
        }
    }
    cout << contsum;
}
