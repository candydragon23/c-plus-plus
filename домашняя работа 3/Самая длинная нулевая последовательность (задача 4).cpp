#include <iostream>
#include <locale.h>
using namespace std;
int main()
{
    setlocale (LC_ALL, "Russian");
    int n;
    cout << "Введите размер массива n: ";
    cin >> n;
    int arr[n];
    cout << "Задайте массив: ";
    int maxlen = 0, curlen = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] == 0)
            curlen++;
        else
        {
            maxlen = max(maxlen, curlen);
            curlen = 0;
        }
    }
    cout << max(maxlen, curlen);
}
