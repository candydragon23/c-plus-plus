#include <iostream>
#include <fstream>
using namespace std;
int readArray (const char* fileName, int* arr, int length)
{
    ifstream in(fileName);
    if (!in.is_open()) //Проверка открылся ли файл
        return 0;
    int elem; //Читаемый элемент
    for (int i = 0; i < length; i++)
    {
        in >> elem; //Чтение элемента из файла
        if (in.fail()) //Если не удалось прочитать
            return i;
        arr[i] = elem;
    }
    return length;
}
int main()
{
    //Код здесь
}
