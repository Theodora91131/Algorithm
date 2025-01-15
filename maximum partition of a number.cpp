#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    string x;
    cin >> x;

    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        int maxS = 0;
        for (int j = 1; j <= m && i - j >= 0; j++) {
            maxS = max(maxS, stoi(x.substr(i - j, j))); //stoi(x.substr(i - j, j)) 的意思是將 x 中由 i - j 開始的 j 個字符的子字串轉換為整數。這樣的操作主要是為了獲取切割後的每個部分的數值，以便進行比較和計算
            dp[i] = max(dp[i], dp[i - j] + maxS);
        }
    }

    cout << dp[n] << endl;

    return 0;
}

