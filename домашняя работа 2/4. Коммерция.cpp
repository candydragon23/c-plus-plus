#include <iostream>
#include <locale.h>
using namespace std;
int main()
{
    setlocale (LC_ALL, "Russian");
    double k,p,r;
    int years = 0;
    cout << "¬ведите размер кредита k, процент p и годовую прибыль r : ";
    cin >> k >> p >> r;
    p = p / 100;
    if (k * p >= r)
    {
        cout << " редит не может быть выплачен" << endl;
        return 0;
    }
    p++;
    while (k > 0)
    {
     k *= p;
     k -= r;
     years++;
    }
    cout << " редит будет выплачен через " <<  years << " лет";
    return 0;
}
