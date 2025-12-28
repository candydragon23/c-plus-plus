#include <iostream>
using namespace std;
int main()
{
    int a = 1, b = 3;
    a--;
    ++b;
    cout << a << " " << b << endl; // a = 0, b = 4
    a = b++;
    cout << a << " " << b << endl; // a = 4, b = 5
    b= --a;
    cout << a << " " << b << endl; // a = 3, b = 3
}
