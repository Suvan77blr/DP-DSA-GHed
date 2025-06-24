// 240625
/*
    Frog Jump with K Jmps:
        - Frog on the 1st Step of 'N' stairs.
        - Aim: To reach 'N'th stair.

        - heights[i]: height of (i+1)th stair.
        - Jump from i->j th stair = energy loss of | H[i-1] - H[j-1] |.
        
        - Frog can jump from i -> i+1, i+2, ... i+k th stair.

        - To find: Minimum total energy used by the frog, in travelling from 1st to Nth stair.
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
    public:
    int frogJump(vector<int>& heights, int n, int k) {
    
        // return recFunc(n-1, heights, k);
    
        // vector<int> dp (n, -1);
        // return dpMemo(n-1, heights, dp, k);

        return dpTabu(heights, n, k);

        // return spaceOptized(heights, n);
    }

    private:
    int recFunc(int idx, vector<int>& heights, int k);
    int dpMemo(int idx, vector<int>& heights, vector<int>& dp, int k); 
    int dpTabu(vector<int>& heights, int n, int k);
};

int Solution :: recFunc(int idx, vector<int>& heights, int k)
{
    if(idx == 0)    { return 0; }

    int minEnergy = INT_MAX, currJmpEnergy;

    for(int jmps = 1; jmps<=k; jmps++) {
        if(idx-jmps >= 0) {
            currJmpEnergy = recFunc(idx-jmps, heights, k) + abs(heights[idx] - heights[idx-jmps]);
            minEnergy = min(minEnergy, currJmpEnergy);
        }
        else {
            break;
        }
    }
    // if( idx > 1) {
        // right = recFunc(idx-2, heights) + abs(heights[idx] - heights[idx-2]);
    // }

    return minEnergy;
}

int Solution :: dpMemo(int idx, vector<int>& heights, vector<int>& dp, int k)
{
    if(dp[idx] != -1) {
        return dp[idx];
    }
    if(idx == 0) {
        return 0;
    }

    int minEnergy = INT_MAX, currJmpEnergy;
    for(int jmps=1; jmps<=k; jmps++) {
        if(idx-jmps >= 0) {
            currJmpEnergy = dpMemo(idx-jmps, heights, dp, k) + abs(heights[idx] - heights[idx-jmps]);
            minEnergy = min(minEnergy, currJmpEnergy);
        }
        else { break; }
    }
    dp[idx] = minEnergy;
    return dp[idx];
}

int Solution :: dpTabu(vector<int>& heights, int n, int k)
{
    vector<int> dp(n, 0);
    dp[0] = 0;

    // int left, right;
    int minEnergy=INT_MAX, currJmpEnergy;
    for(int i=1; i<n; i++) {
        minEnergy=INT_MAX;
        for(int jmps=1; jmps<=k; jmps++) {
            if(i-jmps >= 0) {
                currJmpEnergy = dp[i-jmps] + abs(heights[i] - heights[i-jmps]);
                minEnergy = min(minEnergy, currJmpEnergy);
            }
            else { break; }
        }
        dp[i] = minEnergy;
    }
    return dp[n-1];
}

int main(void) {
    int n;
    cin >> n;

    vector<int> heights (n);
    for(int i=0; i<n; i++) {
        cin >> heights[i];
    }

    int k;
    cin >> k;

    int minEnergy = Solution().frogJump(heights, n, k);
    cout << "Minimum Energy in 1 -> " << n << "-th Stair jumping = " << minEnergy << endl;
    
    return 0;
}

/*
    TCs:
    4, [10, 20, 30, 10]                 => 20
    6, [10, 30, 40, 50, 20, 10]         => 60
    6, [30, 10, 60, 10, 60, 50]         => 40
*/