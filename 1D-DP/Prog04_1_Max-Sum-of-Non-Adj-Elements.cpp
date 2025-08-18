// 280625
/*
    Prob: To find the maximum sum of non-adjacent elements.
        => to find of sub-sequence sum, having no two-elements adjacent, as in the original array.
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
    public:
    int getMaxSumOfNonAdjElements(vector<int>& arr, int n) {
        // int maxSum = recFunc(n-1, arr);
        
        // vector<int> dp (n, -1);
        // int maxSum = dpMemo(n-1, arr, dp);
        // dpMemo(n-1, arr, dp, currSum);
        
        // int maxSum = dpTabu(arr, n);
        
        int maxSum = spaceOptized(arr, n);
        return maxSum;
    }
    private:
    int recFunc(int idx, vector<int>& arr);
    int dpMemo(int idx, vector<int>& arr, vector<int>& dp);
    int dpTabu(vector<int>& arr, int n);
    int spaceOptized(vector<int>& arr, int n);
};

int Solution :: recFunc(int idx, vector<int>& arr) {
    if(idx < 0) {
        return 0;
    }
    if(idx == 0 || idx == 1) {
        return arr[idx];
    }

    int pick = arr[idx] + recFunc(idx-2, arr);

    int notPick = 0 + recFunc(idx-1, arr);

    return max(pick, notPick);

}

int Solution :: dpMemo(int idx, vector<int>& arr, vector<int>& dp) 
{
    if(idx < 0) { 
        cout << "\nFunc bypassed.";
        return 0; 
    }

    if(dp[idx] != -1) { 
        cout << "\nFunc bypassed via DP.";
        return dp[idx]; 
    }

    int pick = arr[idx] + dpMemo(idx-2, arr, dp);
    int notPick = 0 + dpMemo(idx-1, arr, dp);
    cout << "\nFunc entered.";
    dp[idx] = max(pick, notPick);
    return dp[idx];
}

int Solution :: dpTabu(vector<int>& arr, int n) 
{
    vector<int> dp (n, -1);
    dp[0] = arr[0];

    for(int i=1; i<n; i++) {
        int left = arr[i];
        if(i-2 >= 0) {
            left += dp[i-2];
        }
        int right = dp[i-1];

        dp[i] = max(left, right);
    }
    return dp[n-1];
}

int Solution :: spaceOptized(vector<int>& arr, int n) {
    int prev=arr[0], prev2=0;
    int pick, notPick, curr;

    for(int i=1; i<n; i++) {
        pick = arr[i] + prev2;
        notPick = 0 + prev;

        curr = max(pick, notPick);
        prev2 = prev;
        prev = curr;
    }
    return prev;        // At i==n, 'prev' will have the answer ... not 'curr'
}

int main(void) {
    int n;
    cin >> n;       // Input size.

    vector<int> arr (n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int maxSumPossible = Solution().getMaxSumOfNonAdjElements(arr, n);
    cout << "Max sum of non adjacent elements: " << maxSumPossible << endl;

    return 0;
}

/*
    TCs:
    [1 2 4] => 5.
    [2 1 4 9] => 11.
*/