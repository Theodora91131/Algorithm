#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) // dp[0]=1
    {
        for (int j = 1; j <= 6; ++j) // dp[3]=dp[3-1]+dp[3-2]+dp[3-3]  dp[i]+= dp[i-j]
        {
            if (j > i)
                break;
            dp[i] = (dp[i] + dp[i - j]) % MOD;
        }
    }
    cout << dp[n] << endl;
    return 0;
}