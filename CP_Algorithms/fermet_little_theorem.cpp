#include <bits/stdc++.h>
#include <cmath>
using namespace std;

// Function to calculate a^b % mod using exponentiation by squaring
int modExp(int a, int b, int mod)
{
    int result = 1;
    a = a % mod; // To handle cases where a >= mod

    while (b > 0)
    {
        if (b % 2 == 1) // If b is odd, multiply by a
            result = (result * a) % mod;
        a = (a * a) % mod; // Square the base
        b /= 2;            // Reduce exponent by half
    }

    return result;
}

// Function to verify Fermat's Little Theorem: a^(p-1) % p == 1 if gcd(a, p) == 1
bool fermatLittleTheorem(int a, int p)
{
    // Check if p is prime
    if (p <= 1)
    {
        cout << "p must be a prime number." << endl;
        return false;
    }

    // Check if gcd(a, p) == 1
    if (std::gcd(a, p) == 1)
    {
        // Verify Fermat's Little Theorem: a^(p-1) % p should be 1
        int result = modExp(a, p - 1, p);
        return result == 1;
    }
    else
    {
        return false; // If a and p are not coprime, Fermat's Little Theorem does not apply
    }
}

int main()
{
    int a, p;
    cout << "Enter a number (a) and a prime number (p): ";
    cin >> a >> p;

    if (fermatLittleTheorem(a, p))
    {
        cout << "Fermat's Little Theorem holds: a^(p-1) ≡ 1 (mod p)" << endl;
    }
    else
    {
        cout << "Fermat's Little Theorem does not hold" << endl;
    }

    return 0;
}
