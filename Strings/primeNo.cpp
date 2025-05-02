#include <iostream>
#include <vector>
#include <string>
using namespace std;

// brute force approach
string isPrime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return "Non Prime";
        }
    }
    return "Prime";
}

// optimized approach - Sieve of Eratosthenes
int countPrimes(int n)
{
    vector<bool> isPrime(n + 1, true);
    int count = 0;

    for (int i = 2; i < n; i++)
    {
        if (isPrime[i])
        {
            count++;
            for (int j = i * 2; j < n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    return count;
}

int main()
{
    int n = 50;

    cout << isPrime(n) << endl;
    cout << countPrimes(n) << endl;
    return 0;
}