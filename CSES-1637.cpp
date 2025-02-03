#include<iostream>
#include<vector>
const int MAX = 999999999;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> dp(n + 1, MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        int temp = i;
        while (temp) {
            dp[i] = min(dp[i], dp[i - (temp % 10)] + 1);
            temp /= 10;
        }
    }
    cout << dp[n] << endl;
}
