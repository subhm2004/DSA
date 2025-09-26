#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// ==========================
// Fenwick Tree (BIT) : Point Update + Range Query
// ==========================
class BIT
{
public:
    int n;
    vector<ll> bit;

    BIT(int n)
    {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    // ✅ Point Update
    void update(int i, ll x)
    {
        for (; i <= n; i += (i & -i))
            bit[i] += x;
    }

    // ✅ Prefix Sum Query
    ll prefixSum(int i)
    {
        ll total = 0;
        for (; i > 0; i -= (i & -i))
            total += bit[i];
        return total;
    }

    // ✅ Range Sum Query [l..r]
    ll rangeSum(int l, int r)
    {
        return prefixSum(r) - prefixSum(l - 1);
    }
};

// ==========================
// Inversion Count using BIT
// ==========================
ll countInversions(vector<int> &arr)
{
    int n = arr.size();

    // Step 1: Coordinate compression
    vector<int> sorted = arr;
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

    auto getRank = [&](int x)
    {
        return int(lower_bound(sorted.begin(), sorted.end(), x) - sorted.begin() + 1);
    };

    BIT bit(n);
    ll cnt = 0;

    // Step 2: Traverse Left → Right
    for (int i = 0; i < n; i++)
    {
        int rank = getRank(arr[i]);
        // Count bigger elements already seen
        cnt += bit.rangeSum(rank + 1, n); // 🔹 now using rangeSum()
        bit.update(rank, 1);
    }
    return cnt;
}

// ==========================
// Main with Examples
// ==========================
int main()
{
    vector<vector<int>> tests = {
        {8, 4, 2, 1},                 // Expected = 6
        {3, 1, 2},                    // Expected = 2
        {1, 20, 6, 4, 5},             // Expected = 5
        {10, 9, 8, 7, 6, 5},          // Expected = 15
        {1, 2, 3, 4, 5},              // Expected = 0
        {1000000, 999999, 2, 1, 5000} // Expected = 8
    };

    for (auto &arr : tests)
    {
        cout << "Array: ";
        for (int x : arr)
            cout << x << " ";
        cout << "\nInversions = " << countInversions(arr) << "\n\n";
    }

    return 0;
}
