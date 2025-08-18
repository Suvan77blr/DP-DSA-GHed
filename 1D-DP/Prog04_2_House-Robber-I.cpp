
// 180825
/*
    House Robber I
        - There is a professional robber planning to rob houses along a street. 
        - Each house has a certain amount of money stashed.

        - The ADJ houses adjacent houses have a security system connected. 
            => It will automatically contact the police if two adjacent houses were broken into on the same night.

        Return the maximum amount of money that can be robbed tonight without alerting the police.
*/

#include <iostream>
#include <vector>
using namespace std;
using vi = vector<int>;

class Solution {
public:
    int func(int idx, vi& arr, vi& dp) {
        if(idx < 0) {   return 0;   }
        if(dp[idx] != -1) return dp[idx];

        int left = arr[idx] + func(idx-2, arr, dp);
        int right = 0 + func(idx-1, arr, dp);

        dp[idx] = max(left, right);
        return dp[idx];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vi dp(n, -1);
        return func(n-1, nums, dp);
    }
};

int main(void) {
    int n;  cin >> n;

    vi nums (n);
    for(int i=0; i<n; i++)  { cin >> nums[i];   }

    int maxAmountRobbable = Solution().rob(nums);
    cout << "Max Amt Robbable: " << maxAmountRobbable << endl;

    return 0;
}