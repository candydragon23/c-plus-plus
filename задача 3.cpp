#include <iostream>
using namespace std;
int main()
{
    int m,amount = 0,cur,curamount = 0,cur2 = 100;
    cin >> m;
    int giri[] = {100, 50, 20, 10, 5, 2, 1};
    for (int i = 0; i < sizeof(giri) / sizeof(giri[0]); i++)
    {
        cur = giri[i];
        if (cur < cur2 && curamount > 0)
        {
        cout << cur2 << ": " << curamount << endl;
        cur2 = cur;
        curamount = 0;
        }
        if (m - giri[i] >= 0)
        {
            m -= giri[i];
            amount++;
            curamount++;
            i--;
        }
    }
    if (curamount > 0)
    cout << cur2 << ": " << curamount << endl;
    cout << amount;
}
