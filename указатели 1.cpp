#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main()
{
    srand(time(NULL));
    int* p = new int[10];
    *p = rand() % 101 - 50;
    int mini = *p;
    for (int i = 1; i < 10; i++)
    {
        *(p + i) = rand() % 101 - 50;
        cout << *(p + i) << " ";
        mini = min(mini, *(p + i));
    }
    cout << endl <<  mini;
}
