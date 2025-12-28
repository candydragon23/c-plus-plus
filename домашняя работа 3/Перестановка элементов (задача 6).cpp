#include <iostream>
#include <locale.h>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "Задайте размерность массива n: ";
    cin >> n;
    int arr[n];
    cout << "Задайте массив: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int current = 1,k, flag = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0 && flag == 1)
        {
            k = i;
            flag = 0;
        }
        if (arr[i] != 0 && flag == 0)
        {
            arr[k] = arr[i];
            arr[i] = 0;
            i = k;
            flag = 1;
        }
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
