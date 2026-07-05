#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> numbers(105);
    vector<int> dp(105);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> numbers(n);
        int total = 0;
        for(int i=0;i<n;i++){
            cin >> numbers[i];
            total += numbers[i];    
        }
        vector<bool> dp(total + 1, false);
        dp[0] = true;
        for(int x :numbers){
            for(int s = total; s >= x; s--){
                dp[s] = dp[s] || dp[s - x];
            }
        }
        long long ans = 0;
        for(int s = 0; s <= total; s++){
            if(dp[s]){
                ans += s;
            }
        }
        cout << ans << endl;
    }
    return 0;
}