#include <iostream>
#include <locale.h>
#include <stdint.h>
using namespace std;
int64_t factorial(int64_t n)
{
    if (n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}
long double division(int x, int num, float div)
{
   if (num % 2 == 1 && x > 0)
   {
      div += 2;
      num++;
      return 1 / (div - division(x - 1, num, div));
   }
   if (num % 2 == 0 && x > 0)
   {
    num++;
    return 1 / (2 + division(x - 1, num, div));
   }
   else
    return 0;
}
int main()
{
  setlocale (LC_ALL, "Russian");
  double exp1 = 2,exp2 = 1;
  int x;
  cout << "¬ведите глубину проверки скорости сходимости x : ";
  cin >> x;
  cout << "ѕроверка через р€д дробей (x = количество дробей)" << endl;
  cout << "2 ; x = 0" << endl;
  for (int i = 2; i <= x + 1; i++)
  {
   exp1 += 1 / (factorial(i) * 1.0);
   cout << exp1 << " ; x = " << i - 1 << endl;
  }
  cout << "ѕроверка через бесконечную дробь (x = глубина бесконечной дроби, количество дробных черт)" << endl;
  for (int i = 1; i <= x + 1 ; i++)
  cout << exp2 + division(i - 1, 1, -1) << " ; x = " << i - 1 << endl;
  return 0;
}
