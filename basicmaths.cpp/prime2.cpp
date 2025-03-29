#include <bits/stdc++.h>
using namespace std;

// Function to find prime numbers up to n using Sieve of Eratosthenes
vector<int> sieveOfEratosthenes(int n)
{
    vector<bool> isPrime(n + 1, true);
    vector<int> primes;

    isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime numbers

    for (int i = 2; i * i <= n; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }

    // Collecting all prime numbers
    for (int i = 2; i <= n; i++)
        if (isPrime[i])
            primes.push_back(i);

    return primes;
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    vector<int> primes = sieveOfEratosthenes(n);

    cout << "Prime numbers up to " << n << ":\n";
    for (int prime : primes)
        cout << prime << " ";
    cout << endl;

    return 0;
}
