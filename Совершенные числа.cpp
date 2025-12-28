#include <iostream>
#include <locale.h>
using namespace std;
int main()
{
    int n;
    setlocale(LC_ALL, "Russian");
    cout << "¬ведите максимальное число n : ";
    cin >> n;
    if (n < 6)
    {
        cout << "—овершенных чисел нет";
        return 0;
    }
    for (int i = 6; i <= n; i++)
    {
        int sum = 1;
        for (int j = 2; j <= i / 2; j++)
        {
            if (i % j == 0)
            {
                sum += j;
                if (sum > i)
                    break;
            }
        }
        if (sum != i)
            continue;
        cout << i << "=1+";
        sum = 1;
        for (int j = 2; j <= i / 2; j++)
            if (i % j == 0)
            {
                cout << j;
                sum += j;
                if (sum == i)
                {
                    cout << endl;
                    break;
                }
                else cout << "+";
            }
    }
    return 0;
}
