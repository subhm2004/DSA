#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // 🔁 Recursive LIS length
    int solveRE(vector<int> &arr, int curr, int prev)
    {
        if (curr >= arr.size())
            return 0;

        int include = 0;
        if (prev == -1 || arr[curr] > arr[prev])
            include = 1 + solveRE(arr, curr + 1, curr);

        int exclude = solveRE(arr, curr + 1, prev);
        return max(include, exclude);
    }

    // 💾 Memoized LIS length
    int solveME(vector<int> &arr, int curr, int prev, vector<vector<int>> &dp)
    {
        if (curr >= arr.size())
            return 0;

        if (dp[curr][prev + 1] != -1)
            return dp[curr][prev + 1];

        int include = 0;
        if (prev == -1 || arr[curr] > arr[prev])
            include = 1 + solveME(arr, curr + 1, curr, dp);

        int exclude = solveME(arr, curr + 1, prev, dp);
        return dp[curr][prev + 1] = max(include, exclude);
    }

    // 🧠 Memoized LIS + print sequence
    void solveWithPrint(vector<int> &arr, int curr, int prev, vector<vector<int>> &dp,
                        vector<int> &temp, vector<int> &best)
    {
        if (curr >= arr.size())
        {
            if (temp.size() > best.size())
                best = temp;
            return;
        }

        if (prev == -1 || arr[curr] > arr[prev])
        {
            temp.push_back(arr[curr]);
            if (dp[curr][prev + 1] == 1 + solveME(arr, curr + 1, curr, dp))
                solveWithPrint(arr, curr + 1, curr, dp, temp, best);
            temp.pop_back();
        }

        if (dp[curr][prev + 1] == solveME(arr, curr + 1, prev, dp))
            solveWithPrint(arr, curr + 1, prev, dp, temp, best);
    }

    // 🔽 Bottom-up LIS + print sequence
    int lengthOfLIS_bottomUp(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;

        vector<int> dp(n, 1);    // LIS ending at i
        vector<int> prev(n, -1); // store path

        int maxLength = 1;
        int lastIndex = 0;

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i] && dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > maxLength)
            {
                maxLength = dp[i];
                lastIndex = i;
            }
        }

        // Reconstruct LIS
        vector<int> ans_LIS;
        while (lastIndex != -1)
        {
            ans_LIS.push_back(nums[lastIndex]);
            lastIndex = prev[lastIndex];
        }
        reverse(ans_LIS.begin(), ans_LIS.end());

        cout << "LIS (Bottom-Up): ";
        for (int num : ans_LIS)
            cout << num << " ";
        cout << "\n";

        return maxLength;
    }

    // 🔚 Driver function
    void runAllApproaches(vector<int> &nums)
    {
        int n = nums.size();
        int curr = 0, prev = -1;

        // RECURSIVE
        cout << "Recursive LIS Length: " << solveRE(nums, curr, prev) << endl;

        // MEMOIZATION
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        int len = solveME(nums, curr, prev, dp);
        vector<int> temp, best;
        solveWithPrint(nums, curr, prev, dp, temp, best);

        cout << "Memoized LIS Length: " << len << "\n";
        cout << "LIS (Memoized): ";
        for (int x : best)
            cout << x << " ";
        cout << "\n";

        // BOTTOM-UP
        int dpLen = lengthOfLIS_bottomUp(nums);
        cout << "Bottom-Up LIS Length: " << dpLen << endl;
    }
};

// 🔎 Driver
int main()
{
    Solution s;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    s.runAllApproaches(nums);
    return 0;
}
