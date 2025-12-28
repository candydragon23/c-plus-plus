#include <iostream>
#include <locale.h>
#include <iomanip>
using namespace std;
int main()
{
    setlocale (LC_ALL, "Russian");
    cout << "Введите диапазон k [0 k]: ";
    int k;
    cin >> k;
    double curmile = 1,curkm,mile = 1.609344;
    cout << "мили \t км" << endl;
    for (curkm = 1; curkm <= k; curkm++)
    {
        if (curkm / mile <= curmile)
           cout << setprecision(4) << fixed << curkm /  mile << "\t " << curkm << endl;
        else
        {
            cout << setprecision(4) << fixed << curmile << "\t " << curmile * mile << endl;
            curmile++;
            curkm--;
        }
    }
    return 0;
}
