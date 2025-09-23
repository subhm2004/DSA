#include <bits/stdc++.h>
using namespace std;

class Combinatorics
{
public:
    typedef long long ll;
    const int M = 1e9 + 7; // Prime Modulo
    const int N = 2e5 + 2; // Factorial limit
    vector<ll> fact, invFact;

    ll mod(ll x) { return ((x % M + M) % M); }
    ll add(ll a, ll b) { return mod(a + b); }
    ll mul(ll a, ll b) { return mod(a * b); }

    ll modPow(ll a, ll b)
    {
        ll ans = 1;
        while (b)
        {
            if (b & 1)
                ans = mul(ans, a);
            a = mul(a, a);
            b >>= 1;
        }
        return ans;
    }

    ll inv(ll x) { return modPow(x, M - 2); }
    ll modSub(ll a, ll b) { return mod(a - b); }
    ll modDiv(ll a, ll b) { return mul(a, inv(b)); }

    Combinatorics()
    {
        fact.resize(N, 1);
        invFact.resize(N, 1);
        precalc();
    }

    void precalc()
    {
        // Precompute factorials
        for (int i = 1; i < N; i++)
        {
            fact[i] = mul(fact[i - 1], i);
        }

        // Precompute inverse factorials using Fermat's little theorem
        invFact[N - 1] = inv(fact[N - 1]);
        for (int i = N - 2; i >= 0; i--)
        {
            invFact[i] = mul(invFact[i + 1], i + 1);
        }
    }

    ll nCr(ll n, ll r)
    {
        if (r > n || r < 0)
            return 0;
        return mul(fact[n], mul(invFact[r], invFact[n - r]));
    }

    ll nPr(ll n, ll r)
    {
        if (r > n || r < 0)
            return 0;
        return mul(fact[n], invFact[n - r]);
    }

    ll factorial(ll r)
    {
        if (r < 0)
            return 0;
        return fact[r];
    }

    ll inverse_factorial(ll r)
    {
        if (r < 0)
            return 0;
        return invFact[r];
    }

    // Generic function to compute the number of distinct arrangements
    // of the characters in the given word.
    ll getDistinctWays(const string &word)
    {
        unordered_map<char, ll> freq;
        for (const auto &c : word)
        {
            freq[c]++;
        }

        ll ways = factorial(word.length());
        for (const auto &entry : freq)
        {
            ll count = entry.second;
            ways = mul(ways, invFact[count]); // use precomputed inverse factorial
        }
        return ways;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Combinatorics comb;

    // Sample test cases
    cout << "=== nCr & nPr Test Cases ===\n";
    vector<pair<Combinatorics::ll, Combinatorics::ll>> combTests = {{5, 2}, {10, 3}, {100, 50}};

    for (auto &[n, r] : combTests)
    {
        cout << "nCr(" << n << ", " << r << ") = " << comb.nCr(n, r) << "\n";
        cout << "nPr(" << n << ", " << r << ") = " << comb.nPr(n, r) << "\n";
    }

    cout << "\n=== getDistinctWays Test Cases ===\n";
    vector<string> words = {"aabb", "abc", "aabbcc", "aaaa"};

    for (const string &word : words)
    {
        cout << "Distinct ways to arrange \"" << word << "\": " << comb.getDistinctWays(word) << "\n";
    }

    return 0;
}
