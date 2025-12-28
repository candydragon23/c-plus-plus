#include <iostream>
using namespace std;
int main()
{
    cout << "Insert a, b, c (a b c): ";
    double x0, y0, a, b, c;
    cin >> a >> b >> c;
    x0 = -b / (2.0 * a);
    y0 = a * x0 * x0 + b * x0 + c;
    cout << "The coordinates of the top of the parabola are: " << x0 << " " << y0;
    return 0;
}
