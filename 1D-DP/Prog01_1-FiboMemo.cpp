
// 2403251307
/* 
    Prog1_1 : Fibonacci Sequence using Memorization Technique.
    ( guided by SS! )
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int memFibo(vector<int>& dp, int n)
        {
            if(n<=1) 
                return n;

            if(dp[n] != -1)
                return dp[n];
            
            dp[n] = memFibo(dp, n-1)+memFibo(dp, n-2);
            return dp[n];
        }
};

int main(void)
{   
    int num;
    cout << "Enter the target number of the fibo seq : ";
    cin >> num;

    // We take the number input, but send the index value to the function.
    vector<int> dp (num, -1);
    int result = Solution().memFibo(dp, num-1);

    cout << num << "th Fibo number = " << result << endl;
}
