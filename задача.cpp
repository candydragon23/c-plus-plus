#include <iostream>
using namespace std;
int main()
{
    int n,m,cur,countt = 0;
    cin >> n >> m;
    if (m >= 0 && m < 10)
    while (n > 0)
    {
        cur = n % 10;
        n /= 10;
        if (cur == m)
            countt++;
    }
    cout << countt;
    return 0;
}
