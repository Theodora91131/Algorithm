#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int buttom_up(int n, vector<int>& prices) {
    vector<int> dp(n+1, 0);
    for(int i=1; i<=n; i++){
        int max_val = INT_MIN;
        for(int j=1; j<=i; j++){
            max_val = max(max_val, prices[j] + dp[i-j]);
        }
        dp[i] = max_val;
    }
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    vector<int> prices(n+1, 0); // 長度為 i 的賣價，初始化為 0
    for(int i=1; i<=n; i++){
        int len, price;
        cin >> len >> price;
        prices[len] = price; // 將長度為 len 的賣價更新
    }
    cout << buttom_up(n, prices) << endl;
    return 0;
}
