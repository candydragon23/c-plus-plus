#include <iostream>
#include <locale.h>
#include <math.h>
#include <stdint.h>
#define _USES_MATH_DEFINES
using namespace std;
int64_t factorial(int64_t n)
{
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}
int main()
{
    setlocale (LC_ALL, "Russian");
    cout << "¬ведите m и x : ";
    int64_t x = 5,m = 5,binom = 0;
    //cin >> m >> x;
    for (int i = 0; i <= m; i++)
    {
        binom += (factorial(m) / factorial(i) / factorial(m - i)) * pow(x, i);
    }
    cout << "–езультат : " << binom;
    return 0;
}
