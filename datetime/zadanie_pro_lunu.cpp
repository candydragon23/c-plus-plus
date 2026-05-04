#include <iostream>
#include <chrono>
#include <locale.h>
#include <string>
#include <fstream>
using namespace std;
#include "datetime.cpp"
int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Введите дату в формате: dd-mm-yyyy" << endl;
    Datetime moonDate;
    Datetime::switchInput(1);
    cin >> moonDate;
    auto start = chrono::steady_clock::now();
    string fileName = "Moon/moon" + to_string(moonDate.getYear()) + ".dat";
    ifstream file(fileName);
    if (!file)
    {
        cout << "Ошибка открытия файла или данных для данного года нет";
        return -1;
    }
    if (moonDate.getYear() == 2017 && moonDate.getMonth() < 3)
    {
        cout << "Данных нет";
        return -1;
    }
    char skipLine[100];
    file.getline(skipLine, 100);
    int date;
    file >> date;
    Datetime checkDate(date % 100, (date % 10000) / 100, date / 10000); // проверка если первая дата в файле нужная
    while (moonDate - checkDate != 0) // пропуск строчек до нужной даты
    {
        file.getline(skipLine, 100);
        file >> date;
        checkDate = Datetime(date % 100, (date % 10000) / 100, date / 10000);
    }
    int time, curdate = date;
    double timefrac, distance, deg, az, fi, lg, prevdeg = 0, maxdeg = -100;
    Datetime rise, culmination, set;
    bool flagCurDate = true, flagFirst = true;
    while (date == curdate && !file.eof()) // проходит по всем значениям данной даты
    {
        if (moonDate.getYear() == 2007 || moonDate.getYear() == 2008)
        {
            if (flagFirst) // дата уже задана в цикле для пропуска строчек
            {
                file >> time >> distance >> deg >> az >> fi >> lg;
                flagFirst = false;
            }
            else
                file >> date >> time >> distance >> deg >> az >> fi >> lg;
        }
        else
        {
            if (flagFirst)
            {
                file >> time >> timefrac >> distance >> deg >> az >> fi >> lg;
                flagFirst = false;
            }
            else
                file >> date >> time >> timefrac >> distance >> deg >> az >> fi >> lg;
        }
        if (prevdeg < 0 && deg > 0)
        {
            rise = Datetime(1, 1, 1, time / 10000, (time % 10000) / 100, time % 100);
        }
        if (deg > maxdeg)
        {
            culmination = Datetime(1, 1, 1, time / 10000, (time % 10000) / 100, time % 100);
            maxdeg = deg;
        }
        if (prevdeg > 0 && deg < 0)
            {
            set = Datetime(1, 1, 1, time / 10000, (time % 10000) / 100, time % 100);
        }
        prevdeg = deg;
        if (flagCurDate)
        {
            curdate = date;
            flagCurDate = false;
        }
    }
    Datetime::switchOutput(2);
    auto end = chrono::steady_clock::now();
    cout << "Восход луны: " << rise << endl;
    cout << "Кульминация луны: " << culmination << endl;
    cout << "Заход луны: " << set << endl;
    cout << "Время выполнения: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " миллисекунд";
    file.close();
    return 0;
}
