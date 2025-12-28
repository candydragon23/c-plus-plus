#include <iostream>
using namespace std;
int main()
{
    int h,m,s,roundmin,roundhour;
    float ostsec,ostmin;
    cout << "Insert the time (h m s): ";
    cin >> h >> m >> s;
    ostsec = (s % 60) * 1.0 / 60;
    roundmin = m + s / 60 + ostsec * 2;
    cout << "Time rounded up to minutes: " << h + roundmin / 60 << "h " << roundmin << "m" << endl;
    ostmin = (roundmin % 60) * 1.0 / 60;
    roundhour = h + roundmin / 60 + ostmin * 2;
    //cout << ostsec << " " << roundmin << " " << ostmin <<  " " << roundhour;
    cout << "Time rounded up to hours: " << roundhour << "h";
}
