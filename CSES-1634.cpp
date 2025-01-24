#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 999999999; // 無限大，用於初始化dp陣列

int main()
{
    int n, x;
    cin >> n >> x; // 輸入硬幣數量和目標金額

    vector<int> coin(n, 0);     // 儲存硬幣面值
    vector<int> dp(x + 1, INF); // dp[i] 表示湊出金額 i 所需的最少硬幣數量

    dp[0] = 0; // 基底條件：湊出金額 0 需要 0 枚硬幣

    // 讀取硬幣面值
    for (int i = 0; i < n; ++i)
    {
        cin >> coin[i];
    }

    // 動態規劃
    for (int i = 0; i < n; ++i)
    { // 遍歷每一個硬幣
        for (int j = coin[i]; j <= x; ++j)
        {                                            // 更新金額 j 的最少硬幣數量
            dp[j] = min(dp[j], dp[j - coin[i]] + 1); //+1表示算記錄再加入一個硬幣
        }
    }

    // 輸出結果
    if (dp[x] == INF)
    {
        cout << -1 << endl; // 無法湊出金額 x
    }
    else
    {
        cout << dp[x] << endl; // 輸出最少硬幣數量
    }

    return 0;
}
