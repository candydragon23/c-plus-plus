#include <iostream>
#include <locale.h>
using namespace std;
//Надо быть очень осторожным при выводе массива и работать с динамической памятью
//Функция создает массив из первых чисел Фибоначчи
const int FIB_NUMBER = 10; //Константы принято записывать капсом
int* createFib (void) //void означает что мы ничего не вводим также можно сделать void как тип возвращаемого значения если ничего не выводим
{
    int* arr = new int [FIB_NUMBER]; //Создаем массив в динамической памяти
    arr[0] = arr[1] = 1;
    for (int i = 2; i < FIB_NUMBER; i++)
        arr[i] = arr[i - 1] + arr[i - 2];
        //Только после использования массива надо будет освободить память
    return arr;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    int* fibArr = createFib();
    cout << "Числа Фибоначчи: ";
    for (int i = 0; i < FIB_NUMBER; i++)
        cout << fibArr[i] << " ";
    cout << endl;
    delete[] fibArr; //Удаление динамического массива из памяти
    return 0;

}
