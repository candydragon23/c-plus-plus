#include <iostream>
#include <locale.h>
using namespace std;
#include "datetime.cpp"
int main()
{
    setlocale(LC_ALL, "Russian");
    Datetime a;
    cout << "Введите дату в формате 'dd-mm-yyyyThh:mm:ss': ";
    cin >> a;
    cout << a << " " << a.getJD() << " " << Datetime::toGregorian(a.getJD()) << endl;
    Datetime::switchOutput(3);
    cout << a << endl;
    cout << a.getDay() << " " << a.getMonth() << " " << a.getYear() << " " << a.getHour() << " " << a.getMinute() << " " << a.getSecond() << " " << a.getinputMode() << " " << a.getoutputMode() << endl;
    Datetime::switchOutput(1);
    cout << "День недели: " << Datetime::dayOfWeek(a) << endl;
    cout << "Дата пасхи: " << Datetime::easterDate(a.getYear()) << endl;
    Datetime::switchOutput(0);
    Datetime b(3, 3, 4000, 12, 0, 0), c(2, 3, 4000, 0, 0, 0);
    cout << "b = " << b << " c = " << c << " b - c = " << b - c << endl;
    double days = 31.57;
    cout << "b = " << b << " days = " << days << " b + days = " << Datetime::toGregorian(b + days) << endl;
    cout << "b = " << b << " c = " << c << " b != c = " << (b != c) << endl;
    cout << "b >= c = " << (b >= c) << endl;
    cout << "b <= c = " << (b <= c) << endl;
    return 0;
}
