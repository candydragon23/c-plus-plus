#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main()
{
    srand(time(NULL));
    int board[8][8];
    int sum = 0,i,j,contrsum = 0;
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
           board[i][j] = rand() % 2;
           cout << board[i][j] << " ";
        }
        cout << endl;
    }
    for (i = 4; i < 8; i++)
        for (j = 0; j < 8; j++)
          sum += board[i][j];
    cout << sum % 2 << endl;
    contrsum = sum % 2;
    contrsum <<= contrsum;
    sum = 0;
    for (i = 2; i < 8; i++)
        if (i != 4 && i != 5)
           for (j = 0; j < 8; j++)
              sum += board[i][j];
    cout << sum % 2 << endl;
    contrsum += sum % 2;
    contrsum <<= contrsum;
    sum = 0;
    for (i = 1; i < 8; i += 2)
        for (j = 0; j < 8; j++)
           sum += board[i][j];
    cout << sum % 2 << endl;
    contrsum += sum % 2;
    contrsum <<= contrsum;
    sum = 0;
    for (i = 0; i < 8; i++)
        for (j = 4; j < 8; j++)
           sum += board[i][j];
    cout << sum % 2 << endl;
    contrsum += sum % 2;
    contrsum <<= contrsum;
    sum = 0;
    for (i = 0; i < 8; i++)
        for (j = 2; j < 8; j++)
           if (j != 4 && j != 5)
              sum += board[i][j];
    cout << sum % 2 << endl;
    contrsum += sum % 2;
    contrsum <<= contrsum;
    sum = 0;
    for (i = 0; i < 8; i++)
        for (j = 1; j < 8; j += 2)
          sum += board[i][j];
    cout << sum % 2 << endl;
    contrsum += sum % 2;
    contrsum <<= contrsum;
    cout << contrsum;
}
