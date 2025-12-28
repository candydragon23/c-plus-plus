#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main()
{
   srand(time(NULL));
   int n,m,amount = 0;
   cin >> n >> m;
   bool isZero = false;
   int** arr = new int* [n];
   for (int i = 0; i < n; i++)\
      arr[i] = new int[m];
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
        arr[i][j] = rand() % 6;
        cout << arr[i][j] << " ";
      }
      cout << endl;
   }
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
          if (!isZero && arr[i][j] == 0)
              isZero = true;
      if (!isZero)
        amount++;
      else
        isZero = false;
   }
   cout << amount;
   for (int i = 0; i < n; i++)
      delete[] arr[i];
   delete[] arr;
   return 0;
}
