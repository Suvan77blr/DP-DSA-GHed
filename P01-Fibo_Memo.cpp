
// 2502250145
/* P1 : Fibonacci Sequence using Memorization Technique.
    ( guided by SS! )
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        // void generateFibo(int n)
        // {
        //     vector<int> dp (n+1, -1);
        // }
        int memFibo(int n)
        {
            vector<int> dp(n+1, -1);
            // .... Yet to complete!

        }
        int recFibo(int n)
        {
            if(n<=1) return n;

            return recFibo(n-1)+recFibo(n-2);
        }
};

int main(void)
{   
    int num;
    cout << "Enter the target number of the fibo seq : ";
    cin >> num;

    Solution soln = Solution();
    int result = soln.recFibo(num);

    cout << num << "th Fibo number = " << result << endl;
}