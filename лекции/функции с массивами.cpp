#include <iostream>
#include <assert.h>
#include <fstream>
using namespace std;
//Результат - максимальный элемент массива
//Передаем константный указатель на массив(показывает что сам массив не будет изменен) и длину массива
int findMax(const int* arr, int length)
{
    //Прекратит выполнение программы если условие неверно
    assert(length > 0);
    int max = arr[0];
    for (int i = 1; i < length; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 10, 6};
    int* p = arr;
    cout << findMax(p, 6);
}
