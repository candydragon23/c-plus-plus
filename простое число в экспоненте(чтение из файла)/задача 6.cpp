#include <iostream>
#include <fstream>
#include <locale.h>
#include <cmath>
using namespace std;
int* primeNum (void); // Создание массива простых чисел
unsigned long long toNumber (char* number, unsigned long long value); // Перевод массива char в число
bool primeCheck (unsigned long long value, int* prime); // Является ли число простым
char* arrMove (char* number); // Сдвиг массива
int main()
{
    setlocale(LC_ALL, "Russian");
    ifstream in("e2mil.txt");
    if (!in.is_open())
    {
        cout << "Ошибка открытия";
        return -1;
    }
    char num;
    char* number = new char[11];
    int* prime = primeNum();
    bool isPrime = false;
    int position = 0;
    unsigned long long value = 0;
    for (int i = 0; i < 10; i++)
    {
        in >> num;
        if (num - '0' >= 0 && num - '0' <= 9)
            number[i] = num;
        else
            i--;
    }
    for (int i = 0; !in.eof() && !isPrime; i++)
    {
        value = toNumber(number, value);
        isPrime = primeCheck(value, prime);
        number = arrMove(number);
        position++;
        if (value < 1000000000)
        {
            value *= 10;
            number = arrMove(number);
            position++;
            in >> number[9];
            value += number[9] - '0';
            number = arrMove(number);
            position++;
        }
        in >> number[9];
        if (!(number[9] - '0' >= 0 && number[9] - '0' <= 9))
        {
            in >> number[9];
        }
    }
    cout << "Число: " << value << " Позиция: " << position;
    delete[] number;
    delete[] prime;
    return 0;
}
int* primeNum (void)
{
    int prime_num = 9593;
    int* prime = new int [prime_num];
    int found = 0,current = 2,limit = 1;
    bool isprime = true;
    while (found < prime_num)
    {
        if ((limit + 1) * (limit + 1) <= current)
            limit++;
        for (int i = 0; i < found && prime[i] <= limit; i++)
            if (current % prime[i] == 0)
            {
                isprime = false;
                break;
            }
        if (isprime)
        {
            prime[found++] = current;
        }
        current++;
        isprime = true;
    }
    return prime;
}
unsigned long long toNumber (char* number, unsigned long long value)
{
    unsigned long long power = 1000000000;
    if (value == 0)
    {
        for (int i = 0; i < 10; i++)
        {
            value += (number[i] - '0') * power;
            power /= 10;
        }
        return value;
    }
    else
    {
        value -= (value / power) * power;
        value *= 10;
        value += number[9] - '0';
        return value;
    }
}
bool primeCheck (unsigned long long value, int* prime)
{
    if (value % 2 == 0)
        return false;
    int sqval = pow(value, 0.5);
    for (int i = 1; prime[i] <= sqval; i++)
    {
        if (value % prime[i] == 0)
            return false;
    }
    return true;
}
char* arrMove (char* number)
{
    for(int i = 0; i < 9; i++)
    {
        number[i] = number[i + 1];
    }
    return number;
}
