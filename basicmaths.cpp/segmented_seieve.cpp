#include <bits/stdc++.h>
using namespace std;

// Function to find all primes up to sqrt(n) using simple sieve
vector<int> simpleSieve(int limit)
{
    vector<bool> isPrime(limit + 1, true);
    vector<int> primes;

    for (int i = 2; i <= limit; i++)
    {
        if (isPrime[i])
        {
            primes.push_back(i);
            for (int j = i * i; j <= limit; j += i)
                isPrime[j] = false;
        }
    }
    return primes;
}

// Function to find primes in range [left, right] using segmented sieve
vector<int> segmentedSieve(int left, int right)
{
    if (left < 2)
        left = 2; // Prime numbers start from 2
    int limit = sqrt(right);

    // Step 1: Find small primes up to sqrt(right)
    vector<int> basePrimes = simpleSieve(limit);

    // Step 2: Use these primes to mark non-primes in [left, right]
    vector<bool> isPrime(right - left + 1, true);

    for (int prime : basePrimes)
    {
        int start = max(prime * prime, (left + prime - 1) / prime * prime);
        for (int j = start; j <= right; j += prime)
            isPrime[j - left] = false;
    }

    // Step 3: Collect the remaining primes
    vector<int> primes;
    for (int i = 0; i < isPrime.size(); i++)
        if (isPrime[i])
            primes.push_back(left + i);

    return primes;
}

int main()
{
    int left, right;
    cout << "Enter range (left right): ";
    cin >> left >> right;

    vector<int> primes = segmentedSieve(left, right);

    cout << "Prime numbers in range [" << left << ", " << right << "]:\n";
    for (int prime : primes)
        cout << prime << " ";
    cout << endl;

    return 0;
}
