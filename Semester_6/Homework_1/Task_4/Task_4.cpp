#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

static vector<int> primeNumbers;

void findPrimesLessThanN(int n)
{
    vector<int> primes;
    if (n < 3)
    {
        return;
    }
    int i = 2;
    primes.push_back(2);
    while (i*i <= n)
    {
        bool isPrime = true;
        for (int j = 0; j < primes.size(); j++)
        {
            if (!(i % primes[j]))
            {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
            primes.push_back(i);
        i++;
    }
    primeNumbers = vector<int>(primes);
    return;
}

bool isSemiprime(int n)
{
    for (int i = 0; i < primeNumbers.size() && primeNumbers[i] < n; i++)
    {
        for (int j = 0; j < primeNumbers.size() && primeNumbers[j] < n; j++)
            if (primeNumbers[i] * primeNumbers[j] == n)
            {
                return true;
            }
    }
    return false;
}

bool isSumOfTwoSemiprimes(int n)
{
    findPrimesLessThanN(n);
    if (!primeNumbers.size())
        return false;
    for (int i = n / 2; i <= n - 4; i++)
        if (isSemiprime(i) && isSemiprime(n - i))
            return true;
    return false;
}

int main()
{
    int n = 0;
    cin >> n;
    bool isNSumOfTwoSemiprimes = isSumOfTwoSemiprimes(n);
    cout << n << " is" << (isNSumOfTwoSemiprimes ? "" : " not") << " sum of two semiprime numbers";
    return 0;
}

