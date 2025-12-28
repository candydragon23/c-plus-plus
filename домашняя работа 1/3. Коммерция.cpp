#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int nint;
    double k,p,s,nfloat;
    cout << "Insert k p% s (k p% s): ";
    cin >> k >> p >> s;
    p = 1 + p / 100;
    //cout << p;
    nfloat = log(s / k)/log(p);
    cout << "The amount of years to earn " << s << " is: " << nfloat;
}
