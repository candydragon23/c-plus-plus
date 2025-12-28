#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
    long double rad,degree;
    cout << "Insert the amount of radians: ";
    cin >> rad;
    degree = (rad * 180) / M_PI;
    cout << "The amount of degrees is: " << fixed << setprecision(15) << degree;
}
