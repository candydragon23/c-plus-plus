#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    long double r,a;
    int CircleCount,BottomRow;
    cout << "Insert r,a (r,a): ";
    cin >> r >> a;
    BottomRow = (a - r * (sqrt(3) - 1)) / (2 * r);
    CircleCount = ((1 + BottomRow) * BottomRow) / 2;
    cout << "The amount of circles that can be fit inside this triangle is: " << CircleCount;
}
