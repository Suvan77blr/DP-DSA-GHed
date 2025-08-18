
// 2403251305
/* 
    Prog1_2 : Fibonacci Sequence using Tabulation Technique.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int tabFibo(int n)
        {
			if(n<=1) return n;
            vector<int> dp(n+1, -1);
			dp[0] = 0; dp[1] = 1;
			
            for(int i=2; i<=n; i++){
                dp[i] = dp[i-1] + dp[i-2];
            }
            return dp[n];
        }
};

int main(void)
{   
    int num;
    cout << "Enter the target number of the fibo seq : ";
    cin >> num;

    // We take the number input, but send the index value to the function.
    int result = Solution().tabFibo(num-1);

    cout << num << "th Fibo number = " << result << endl;
}
