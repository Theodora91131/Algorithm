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
        for (int j = W; j >= w[i]; --j) {
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