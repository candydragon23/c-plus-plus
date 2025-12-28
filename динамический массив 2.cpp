#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main()
{
    srand(time(NULL));
    int n,m,maxi = 0,amount = 0;
    cin >> n >> m;
    int* arr = new int[n * m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[i * m + j] = rand() % 101;
            cout << arr[i * m + j] << " ";
        }
        cout << endl;
    }
    for (int current = 10; current >= 0; current--)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0 ; j < m; j++)
            {
                if (current == arr[i * m + j])
                    amount++;
                if (amount > 1)
                {
                    cout << current;
                    delete[] arr;
                    return 0;
                }
            }
        amount = 0;
    }
    delete[] arr;
    return 0;
}
