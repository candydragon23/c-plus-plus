#include <iostream>
using namespace std;
int main()
{
    float n;
    cin >> n;
    int binvalue = 0x40000000;
    while (binvalue > n)
        binvalue >>= 1;
    while (binvalue > 0)
    {
        if (n >= binvalue)
        {
            cout << "1";
            n -= binvalue;
        }
        else
            cout << "0";
        binvalue >>= 1;
    }
    return 0;
}
