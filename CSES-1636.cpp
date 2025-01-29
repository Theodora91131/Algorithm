#include<iostream>
#include<vector>

using namespace std;
const int MOD = 1e9 + 7;
int main() {
    int n, x;
    cin >> n >> x;
    vector<int>coin(n, 0);
    vector<int>dp(x, 0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> coin[i];
    }
    dp[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= x; ++j)
        {
            if (j - coin[i] >= 0)
            {
                dp[j] = (dp[j] + dp[j - coin[i]]) % MOD;
            }
        }
    }
    cout << dp[x] << endl;
    return 0;
}