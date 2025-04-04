#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
    }

    int maxSubarraySumHelper(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN; 
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            maxi = max(maxi, sum);
            if (sum < 0) {
                sum = 0;
            }
        }
        return maxi;
    }

    int maxSubArray(vector<int>& nums) {
       return maxSubarraySumHelper(nums);
    }
};

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution sol;
    cout << sol.maxSubArray(nums) << endl;
    return 0;
}
