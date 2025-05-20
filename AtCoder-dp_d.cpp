#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
    int n, W;
    cin >> n >> W;
    vector<int>w(n, 0);
    vector<int>v(n, 0);
    vector<long long>dp(W + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> w[i] >> v[i];
    }
    int temp = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = W; j >= w[i]; --j) {  // 逆向迴圈，確保每個物品只使用一次
            dp[j] = max(dp[j], dp[j - w[i]] + (long long)v[i]);
        }
    }
    long long ans = 0;
    for (int j = 0; j <= W; j++) {
        ans = max(ans, dp[j]);
    }
    cout << ans << endl;

    return 0;
}
/***
 * 1. 定義狀態
狀態定義：
設 dp[j] 表示「當背包容量為 j 時，可以取得的最大價值」。
這意味著我們希望在所有不超過 j 的重量限制下，選擇物品組合使得價值總和最大。

2. 考慮物品選擇的兩種情況對於每一個物品 𝑖（假設其重量為 𝑤𝑖 且價值為 𝑣𝑖），當我們考慮是否把它放入背包時，有兩種情況：

不選擇物品
𝑖：此時背包容量 𝑗 下的最大價值保持原狀，即仍為 𝑑𝑝[𝑗]。
選擇物品
𝑖：要能放入該物品，必須保證當前背包容量 𝑗 至少有 𝑤𝑖 的空間（即 𝑗 ≥ 𝑤 ）。放入該物品後，剩餘的容量變為
𝑗 − 𝑤 ，而這部分容量能達到的最大價值已經在 𝑑𝑝[𝑗−𝑤i] 中計算過了。
放入物品 𝑖 後的總價值為：
𝑑𝑝[𝑗−𝑤𝑖]+𝑣𝑖
3. 推導轉移公式
綜合上述兩種情況，當背包容量為 𝑗 時，選擇是否加入物品 𝑖
i 的最優策略應為兩者中的較大者，因此轉移公式可以寫成：
𝑑𝑝[𝑗]=max(𝑑𝑝[𝑗],𝑑𝑝[𝑗−𝑤𝑖]+𝑣𝑖)（當 𝑗≥𝑤𝑖時）
dp[j]=max(dp[j], dp[j−wi]+vi)（當 j≥wi時）
這裡：𝑑𝑝[𝑗] 是不加入物品 i 時的最大價值。

 */