#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> dp;

    int solve(int i, int j, const vector<int> &arr)
    {
        if (i == j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int mini = INT_MAX;

        for (int k = i; k < j; ++k)
        {
            int cost = solve(i, k, arr) + solve(k + 1, j, arr) + arr[i - 1] * arr[k] * arr[j];

            mini = min(mini, cost);
        }

        return dp[i][j] = mini;
    }

    int matrixMultiplication(int N, const vector<int> &arr)
    {
        dp.assign(N, vector<int>(N, -1));
        return solve(1, N - 1, arr);
    }
};
int main()
{
    vector<int> arr = {10, 20, 30, 40};
    Solution sol;
    cout << "Minimum multiplications: " << sol.matrixMultiplication(arr.size(), arr) << endl;
    return 0;
}
