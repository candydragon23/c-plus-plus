#include <iostream>
#include <fstream> // Библиотека работы с файлами
#include <locale.h>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    ifstream in("in.txt"); // Открытие входного файла
    if (!in.is_open()) // Успешно ли открытие
    {
        cout << "Ошибка: файл in.txt не существует" << endl;
        return -1;
    }
    int a,b,c;
    in >> a >> b >> c; // Ввод 3х чисел из файла
    if (in.fail()) // Не произошла ли ошибка
    {
        cout << "Ошибка: числа не прочитаны" << endl;
        return -2;
    }
    cout << "Прочитаны числа: " << a << " " << b << " " << c << endl;
    ofstream out("out.txt"); // Открытие выходного файла
    if (!out.is_open()) // Успешно ли открытие
    {
        cout << "Ошибка: файл out.txt не существует" << endl;
        return -3;
    }
    out << a << "+" << b << "+" << c << "=" << a + b + c << endl; // Вывод данных в файл
    cout << "Программа завершена успешно" << endl;
    return 0;
}
// in.eof() проверяет достигнут ли конец файла
