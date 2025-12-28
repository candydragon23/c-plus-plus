#include <iostream>
#include <fstream>
#include <locale.h>
#include <string.h>
using namespace std;
const int STR_LENGTH = 80; // Константа макс длина строки
// Функция чтения строки из файла
// in - ссылка на поток, соответствующий файлу
// buffer - массив куда следует записать результат
// результат - истина если строка прочитана успешно
bool readLine(ifstream& in, char* buffer)
{
    buffer[0] = 0; // Для последующей проверки
    in.getline(buffer, STR_LENGTH + 1, '\n');
    if (in.fail())
    {
        if (buffer[0] > 0)
            cout << "Слишком длинная строка" << endl;
        return false;
    }
    return true;
}
// Функция центрирования строки
// buffer - строка которую центрируем
void centerLine (char* buffer)
{
    int len = strlen(buffer); // Длина строки
    int shift = (STR_LENGTH - len) / 2; // На сколько сдвигаем
    if (shift == 0)
        return;
    // Сдвинуть len символов + ноль-символ начиная с последнего
    for (int i = len; i >= 0; i--)
        buffer[i + shift] = buffer[i];
    for (int i = 0; i < shift; i++)
        buffer[i] = ' ';
}
int main()
{
    setlocale(LC_ALL, "Russian");
    ifstream in("in.txt");
    if (!in.is_open())
    {
        cout << "Не удалось открыть входной файл";
        return -1;
    }
    ofstream out("out.txt");
    if (!out.is_open())
    {
        cout << "Не удалось создать выходной файл";
        return -2;
    }
    char buffer[STR_LENGTH + 1];
    while(readLine(in, buffer))
    {
        centerLine(buffer);
        out << buffer << endl;
    }
    return 0;
}
