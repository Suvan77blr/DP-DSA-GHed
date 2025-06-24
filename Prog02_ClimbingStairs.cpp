
// 240325
/*
    Prog02 - Climbing Stairs.
    
    You are climbing a staircase. It takes n steps to reach the top.
    Each time you can either climb 1 or 2 steps. 
    In how many distinct ways can you climb to the top?
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n<=1)
            return 1;

        int prev=1, prev2=1, ans;
        for(int i=2; i<=n; i++) {
            ans = prev + prev2;
            prev2 = prev;
            prev = ans;
        }
        return ans;
    }
};

int main(void) {
    int nStairs;
    // cout << "Enter the number of steps of the stairs : ";
    cin >> nStairs;

    int numOfWays = Solution().climbStairs(nStairs);
    cout << "\nNumber of ways of climbing " << nStairs << " : " << numOfWays << endl;
}