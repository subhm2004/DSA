#include <iostream>
#include <vector>

using namespace std;

// Recursive function with memoization
long long sumOfSubsetsHelper(const string &num, int i, vector<long long> &dp)
{
    // Base case: If i < 0, there are no subsets
    if (i < 0)
        return 0;

    // If already computed, return stored result
    if (dp[i] != -1)
        return dp[i];

    int digit = num[i] - '0';

    // Recurrence relation: Sum of subsets including current digit
    return dp[i] = 2 * sumOfSubsetsHelper(num, i - 1, dp) + digit;
}

// Wrapper function to initialize DP and call the helper function
long long sumOfSubsets(const string &num)
{
    int n = num.length();
    vector<long long> dp(n, -1); // Memoization vector initialized with -1
    return sumOfSubsetsHelper(num, n - 1, dp);
}

// Driver code
int main()
{
    string num;
    cout << "Enter a number: ";
    cin >> num;

    cout << "Sum of all subsets: " << sumOfSubsets(num) << endl;

    return 0;
}
