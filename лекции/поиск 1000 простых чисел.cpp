#include <iostream>
using namespace std;
int main()
{
    const int prime_num = 1000;
    int found = 0,current = 2,limit = 1;
    int prime[prime_num];
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
            cout << current << endl;
            prime[found++] = current;
        }
        current++;
        isprime = true;
    }
    return 0;
}
