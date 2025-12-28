#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
    cout << "Insert the amount of degrees, minutes, seconds (deg, min, sec): ";
    long double deg,minu,sec,degconv,minconv,rad;
    int degint,znak;
    cin >> deg >> minu >> sec;
    minconv = sec / 60;
    degconv = (minu + minconv) / 60;
    //cout << degconv;
    degint = deg;
    znak = degint / sqrt(pow(degint, 2));
    deg = znak * (sqrt(pow(deg, 2)) + degconv);
    //cout << znak << " " << deg;
    rad = deg * M_PI / 180;
    cout << "The amount of radians is: " << fixed << setprecision(15) << rad;
}
