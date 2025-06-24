// 2400625
/*
    Frog Jump:
        - Frog on the 1st Step of 'N' stairs.
        - Aim: To reach 'N'th stair.

        - heights[i]: height of (i+1)th stair.
        - Jump from i->j th stair = energy loss of | H[i-1] - H[j-1] |.
        - Frog, from i'th stair can jump to (i+1)th or (i+2)th stair.

        - To find: Minimum total energy used by the frog, in travelling from 1st to Nth stair.
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
    public:
    int frogJump(vector<int>& heights, int n) {
    
        // return recFunc(n-1, heights);
    
        // vector<int> dp (n, -1);
        // return dpMemo(n-1, heights, dp);

        // return dpTabu(heights, n);

        return spaceOptized(heights, n);
    }

    private:
    int recFunc(int idx, vector<int>& heights);
    int dpMemo(int idx, vector<int>& heights, vector<int>& dp); 
    int dpTabu(vector<int>& heights, int n);
    int spaceOptized(vector<int>& heights, int n);
};

int Solution :: recFunc(int idx, vector<int>& heights)
{
    if(idx == 0)    { return 0; }

    int left = recFunc(idx-1, heights) + abs(heights[idx] - heights[idx-1] );
    int right = INT_MAX;
    if( idx > 1) {
        right = recFunc(idx-2, heights) + abs(heights[idx] - heights[idx-2]);
    }

    return min(left, right);
}

int Solution :: dpMemo(int idx, vector<int>& heights, vector<int>& dp)
{
    if(dp[idx] != -1) {
        return dp[idx];
    }
    if(idx == 0) {
        return 0;
    }

    int left = dpMemo(idx-1, heights, dp) + abs( heights[idx] - heights[idx-1]);
    
    int right = INT_MAX;
    if(idx > 1) {
        right = dpMemo(idx-2, heights, dp) + abs(heights[idx] - heights[idx-2]);
    }

    dp[idx] = min(left, right);
    return dp[idx];
}

int Solution :: dpTabu(vector<int>& heights, int n)
{
    vector<int> dp(n, 0);
    dp[0] = 0;
    int left, right;
    for(int i=1; i<n; i++) {
        left = dp[i-1] + abs(heights[i] - heights[i-1]);
        right = INT_MAX;
        if(i > 1) {
            right = dp[i-2] + abs(heights[i] - heights[i-2]);
        }
        dp[i] = min(left, right);
    }
    return dp[n-1];
}

int Solution :: spaceOptized(vector<int>& heights, int n) 
{
    int dpM1 = 0, dpM2=0, curr = 0;
    int jumpOne, jumpTwo;
    for(int i=1; i<n; i++) {

        jumpOne = dpM1 + abs(heights[i] - heights[i-1]);
        jumpTwo = INT_MAX;
        if(i > 1) {
            jumpTwo = dpM2 + abs(heights[i] - heights[i-2]);
        }
        curr = min(jumpOne, jumpTwo);
        dpM2 = dpM1;
        dpM1 = curr;
    }
    return curr;
}

int main(void) {
    int n;
    cin >> n;

    vector<int> heights (n);
    for(int i=0; i<n; i++) {
        cin >> heights[i];
    }

    int minEnergy = Solution().frogJump(heights, n);
    cout << "Minimum Energy in 1 -> " << n << "-th Stair jumping = " << minEnergy << endl;
    
    return 0;
}

/*
    TCs:
    4, [10, 20, 30, 10]                 => 20
    6, [10, 30, 40, 50, 20, 10]         => 60
    6, [30, 10, 60, 10, 60, 50]         => 40
*/