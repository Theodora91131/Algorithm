#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> treats(n);
    vector<vector<int>> dp(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        cin >> treats[i];   
    }
    int ans =0;
    for(int i=0;i<n;i++){
        dp[i][i]=treats[i]*n; //區間只剩一個點時它一定是第n天賣出
    }

    for(int len =2; len<=n; len++){ 
        for(int l=0; l+len-1<n; l++){
            int r = l+len-1;
            int day = n - len + 1;
            dp[l][r] = max(treats[l]*day+dp[l+1][r], treats[r]*day+dp[l][r-1]);
            ans = max(ans, dp[l][r]);
        }
    }
    cout << ans << endl;
    
    return 0;
}