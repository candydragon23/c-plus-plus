#include <iostream>
#include <locale.h>
#include <math.h>
using namespace std;
int main()
{
   setlocale (LC_ALL, "Russian");
   cout << "¬ведите a и b : ";
   double a,b,x,y;
   cin >> a >> b;
   for (x = -a; x <= a; x++)
   {
    for (y = -b; y <= b; y++)
    {
       if (pow(x, 2) / pow(a, 2) + pow(y, 2) / pow(b, 2) < 1)
        cout << "(" << x << "," << y << ")";
       else
        cout << "\t";
    }
    cout << endl;
   }
   return 0;
}
