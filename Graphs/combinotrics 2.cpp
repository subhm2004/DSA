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
    ll findRank(const string &s)
    {
        int n = s.size();
        vector<int> freq(256, 0);
        for (char c : s)
            freq[c]++;

        ll rank = 1;

        for (int i = 0; i < n; i++)
        {
            // Count characters smaller than s[i] that are still available
            ll smaller = 0;
            for (int ch = 0; ch < s[i]; ch++)
                if (freq[ch] > 0)
                    smaller += freq[ch];

            if (smaller > 0)
            {
                // Remove current character temporarily
                freq[s[i]]--;

                // Compute product of inverse factorials of remaining frequencies
                ll inv_product = 1;
                for (int ch = 0; ch < 256; ch++)
                    if (freq[ch] > 0)
                        inv_product = mul(inv_product, inverse_factorial(freq[ch]));

                // Calculate contribution of smaller characters
                ll term = mul(smaller, mul(factorial(n - i - 1), inv_product));
                rank = add(rank, term);
            }
            else
            {
                freq[s[i]]--; // just remove current character
            }
        }

        return rank % M;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Combinatorics comb;

    // =======================
    // nCr & nPr Test Cases
    // =======================
    cout << "=== nCr & nPr Test Cases ===\n";
    vector<pair<Combinatorics::ll, Combinatorics::ll>> combTests = {{5, 2}, {10, 3}, {100, 50}};

    for (auto &[n, r] : combTests)
    {
        cout << "nCr(" << n << ", " << r << ") = " << comb.nCr(n, r) << "\n";
        cout << "nPr(" << n << ", " << r << ") = " << comb.nPr(n, r) << "\n";
    }

    // =======================
    // Factorial & Inverse Factorial Test Cases
    // =======================
    cout << "\n=== Factorial & Inverse Factorial Test Cases ===\n";
    vector<int> factTests = {0, 1, 5, 10, 20};

    for (int x : factTests)
    {
        cout << x << "! = " << comb.factorial(x) << ", inverse_factorial(" << x << ") = " << comb.inverse_factorial(x) << "\n";
    }

    // =======================
    // getDistinctWays Test Cases
    // =======================
    cout << "\n=== getDistinctWays Test Cases ===\n";
    vector<string> words = {"aabb", "abc", "aabbcc", "aaaa"};

    for (const string &word : words)
    {
        cout << "Distinct ways to arrange \"" << word << "\": " << comb.getDistinctWays(word) << "\n";
    }

    // =======================
    // findRank Test Cases
    // =======================
    cout << "\n=== findRank Test Cases ===\n";
    vector<string> rankTests = {"CAB", "AAB", "ABA", "BAA", "STRING"};

    for (const string &s : rankTests)
    {
        cout << "Lexicographic rank of \"" << s << "\": " << comb.findRank(s) << "\n";
    }

    return 0;
}
