#include <iostream>
using namespace std;
#include "datetime.h"
int Datetime::outputMode = 0;
int Datetime::inputMode = 0;
Datetime::Datetime()
{
    day = 30;
    month = 3;
    year = 2026;
    hour = 0;
    minute = 0;
    second = 0;
    date = julian(day, month, year, hour, minute, second);
}
Datetime::Datetime(int d, int m, int y, int hr, int mnt, int scnd)
{
    if (y < 0 || m < 1 || m > 12 || d < 1 || d > 31 || hr < 0 || hr > 24 || mnt < 0 || mnt > 60 || scnd < 0 || scnd > 60)
        throw DatetimeException();
    bool leap = false;
    if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
        leap = true;
    if (leap && m == 2 && d > 29)
        throw DatetimeException();
    if (!leap)
    {
        int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (d > daysInMonth[m - 1])
            throw DatetimeException();
    }
    day = d;
    month = m;
    year = y;
    hour = hr;
    minute = mnt;
    second = scnd;
    date = julian(day, month, year, hour, minute, second);
}
Datetime::Datetime(int d, int m, int y)
{
    if (y < 0 || m < 1 || m > 12 || d < 1 || d > 31)
        throw DatetimeException();
    bool leap = false;
    if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
        leap = true;
    if (leap && m == 2 && d > 29)
        throw DatetimeException();
    if (!leap)
    {
        int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (d > daysInMonth[m - 1])
            throw DatetimeException();
    }
    day = d;
    month = m;
    year = y;
    hour = 0;
    minute = 0;
    second = 0;
    date = julian(day, month, year, hour, minute, second);
}
double Datetime::julian(int d, int m, int y, int hr, int mnt, int scnd)
{
    if (m <= 2)
    {
        y -= 1;
        m += 12;
    }
    double A = (int)(y / 100);
    double B = 2 - A + (int)(A / 4);
    double time_fraction = (hr / 24.0) + (mnt / (24.0 * 60.0)) + (scnd / (24.0 * 3600.0));
    double date = (int)(365.25 * (y + 4716)) + (int)(30.6001 * (m + 1)) + d + B - 1524.5 + time_fraction;
    return date;
}
Datetime Datetime::toGregorian(double date)
{
    int JD_int = (int)(date + 0.5);
    double frac = (date + 0.5) - JD_int;
    int a = JD_int + 32044;
    int b = (4*a + 3) / 146097;
    int c = a - (146097 * b) / 4;
    int d = (4*c + 3) / 1461;
    int e = c - (1461 * d) / 4;
    int m = (5*e + 2) / 153;
    int day = e - (153*m + 2)/5 + 1;
    int month = m + 3 - 12 * (m/10);
    int year = 100*b + d - 4800 + (m/10);
    int total_seconds = frac * 86400;
    int hour = (int)(total_seconds / 3600);
    int minute = (int)((total_seconds % 3600) / 60);
    int second = total_seconds - hour*3600 - minute*60;
    Datetime data(day, month, year, hour, minute, second);
    return data;
}
int Datetime::getDay() const
{
    return day;
}
int Datetime::getMonth() const
{
    return month;
}
int Datetime::getYear() const
{
    return year;
}
int Datetime::getHour() const
{
    return hour;
}
int Datetime::getMinute() const
{
    return minute;
}
int Datetime::getSecond() const
{
    return second;
}
int Datetime::getinputMode() const
{
    return inputMode;
}
int Datetime::getoutputMode() const
{
    return outputMode;
}
double Datetime::getJD() const
{
    return date;
}
double Datetime::operator - (const Datetime& other) const
{
    return date - other.date;
}
double Datetime::operator + (double days) const
{
    return date + days;
}
bool Datetime::operator == (const Datetime& data) const
{
    return date == data.date;
}
bool Datetime::operator != (const Datetime& data) const
{
    return !(*this == data);
}
bool Datetime::operator > (const Datetime& data) const
{
    return *this - data > 0;
}
bool Datetime::operator < (const Datetime& data) const
{
    return *this - data < 0;
}
bool Datetime::operator >= (const Datetime& data) const
{
    return *this - data >= 0;
}
bool Datetime::operator <= (const Datetime& data) const
{
    return *this - data <= 0;
}
int Datetime::dayOfWeek(Datetime& data)
{
    return (int)data.date % 7;
}
Datetime Datetime::easterDate(int year)
{
    int g = year % 19;
    int i = (19 * g + 15) % 30;
    int j = (year + year / 4 + i) % 7;
    int e = 10;
    if (year < 1583)
        e = 0;
    else if (year > 1600)
        e = e + (year / 100) - 16 - ((year / 100) - 16) / 4;
    int p = i - j + e;
    int day = 1 + (p + 27 + (p + 6) / 40) % 31;
    int month = 3 + (p + 26) / 30;
    return Datetime(day, month, year);
}
void Datetime::switchOutput(int mode)
{
    outputMode = mode;
}
void Datetime::switchInput(int mode)
{
    inputMode = mode;
}
istream& operator >> (istream& in, Datetime& date)
{
    char dash = '-', time = 'T', colon = ':';
    int d = 0, m = 0, y = 0, hour = 0, minute = 0, second = 0;
    switch (Datetime::inputMode)
    {
    case 1:
        in >> d >> dash >> m >> dash >> y;
        break;
    default:
        in >> d >> dash >> m >> dash >> y >> time >> hour >> colon >> minute >> colon >> second;
    }
    Datetime check(d, m, y, hour, minute, second);
    date = check;
    return in;
}
ostream& operator << (ostream& out, const Datetime& date)
{
    switch (Datetime::outputMode)
    {
    case 1:
        out << date.day << "-" << date.month << "-" << date.year;
        break;
    case 2:
        out << date.hour << ":" << date.minute << ":" << date.second;
        break;
    case 3:
        {
        const char* months[] = {"Января", "Февраля", "Марта", "Апреля", "Мая", "Июня", "Июля", "Августа", "Сентября", "Октября", "Ноября", "Декабря"};
        out << date.day << " " << months[date.month - 1] << " " << date.year;
        break;
        }
    default:
        out << date.day << "-" << date.month << "-" << date.year << " " << date.hour << ":" << date.minute << ":" << date.second;
    }
    return out;
}

