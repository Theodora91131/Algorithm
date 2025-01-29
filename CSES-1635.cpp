#include <iostream>
#include <vector>

using namespace std;
const int MOD = 1e9 + 7;
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> coin(n);
    vector<int> dp(x, 0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> coin[i];
    }
    dp[0] = 1;

    for (int i = 1; i <= x; ++i)
    {
        long long sum = 0;
        for (int j = 1; j <= n; ++j)
        {
            if (i - coin[j] >= 0)
            {
                dp[i] = (dp[i] + dp[i - coin[j]]) % MOD;
            }
        }
    }
    cout << dp[x] << endl;
    return 0;
}