#include <iostream>
using namespace std;
class DatetimeException {};
class Datetime
{
private:
    int day, month, year, hour, minute, second;
    double date;
    double julian(int d, int m, int y, int hr, int mnt, int scnd);
    static int outputMode;
    static int inputMode;
public:
    Datetime();
    Datetime(int d, int m, int y, int hr, int mnt, int scnd);
    Datetime(int d, int m, int y);
    static Datetime toGregorian(double date);
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    int getHour() const;
    int getMinute() const;
    int getSecond() const;
    int getinputMode() const;
    int getoutputMode() const;
    double getJD() const;
    double operator - (const Datetime& other) const;
    double operator + (double days) const;
    bool operator > (const Datetime& data) const;
    bool operator < (const Datetime& data) const;
    bool operator >= (const Datetime& data) const;
    bool operator <= (const Datetime& data) const;
    bool operator == (const Datetime& data) const;
    bool operator != (const Datetime& data) const;
    static int dayOfWeek(Datetime& date);
    static Datetime easterDate(int year);
    static void switchOutput(int mode);
    static void switchInput(int mode);
    friend istream& operator >> (istream& in, Datetime& date);
    friend ostream& operator << (ostream& out, const Datetime& date);
};
