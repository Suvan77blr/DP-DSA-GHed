
// 2403251340
/* 
    Prog1_03 : Fibonacci Sequence in a Space-Optimized way.
    ( Striver Special)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int optiFibo(int n)
        {
			if(n<=1) return n;			
            int prev1 = 1, prev2 = 0, ans;

            for(int i=2; i<=n; i++){
                // dp[i] = dp[i-1] + dp[i-2];
                ans = prev1 + prev2;
                prev2 = prev1;
                prev1 = ans;
            }
            return prev1;
        }
};

int main(void)
{   
    int num;
    cout << "Enter the target number of the fibo seq : ";
    cin >> num;

    // We take the number input, but send the index value to the function.
    int result = Solution().optiFibo(num);

    cout << num << "th Fibo number = " << result << endl;
}
