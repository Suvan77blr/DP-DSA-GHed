
// 180825.
/*
    House Robber II
        - There is a professional robber planning to rob houses along a street. 
        - Each house has a certain amount of money stashed.
        - All houses at this place are arranged in a circle. 
            => meaning the first house is the neighbor of the last one.

        - The ADJ houses adjacent houses have a security system connected. 
            => It will automatically contact the police if two adjacent houses were broken into on the same night.

        Return the maximum amount of money that can be robbed tonight without alerting the police.
*/

#include <iostream>
#include <vecotor>
using namespace std;
using vi = vector<int>;

class Solution {
public:
    int func(int idx, const int start, const vi& arr, vi& dp) {
        if(idx < start) return 0;
        if(idx == 0 || idx == 1) return arr
        if(dp[idx] != -1) return dp[idx];

        int ch1 = arr[idx] + func(idx-2, start, arr, dp);
        int ch2 = 0 + func(idx-1, start, arr, dp);

        return dp[idx] = max(ch1, ch2);
    }

    int robFunc(const vi& arr, int start, int end) {
        vi dp (arr.size(), -1);
        return func(end, start, arr, dp);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        int first = robFunc(nums, 0, n-2);
        int last = robFunc(nums, 1, n-1);
        return max(first, last);
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