#include <iostream>
#include <locale.h>
using namespace std;
const int AMOUNT = 94;
unsigned long long* fib(void)
{
    unsigned long long* arr = new unsigned long long[AMOUNT];
    arr[0] = arr[1] = 1;
    for (int i = 2; i < AMOUNT; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
        if (arr[i - 1] > ULONG_LONG_MAX - arr[i - 2])
        {
            cout << "Переполнение переменной" << endl;
            abort();
        }

    }
    return arr;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    unsigned long long* fibarr = fib();
    for (int i = 0; i < AMOUNT; i++)
        cout << fibarr[i] << endl;
    delete[] fibarr;
    return 0;
}
