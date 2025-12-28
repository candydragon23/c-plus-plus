#include <iostream>
#include <locale.h>
using namespace std;
int main()
{
    setlocale (LC_ALL, "Russian");
    float n;
    cout << "¬ведите число n: ";
    cin >> n;
    int f = *((int*)&n);
    cout << hex << f;
    }
