#include<bits/stdc++.h>

using namespace std;
int g(int n){
    if(n<10) return n;
    int digit = 1;
    while(n>0){
        if(n%10 !=0) digit *=n%10;
        n /= 10;
    }
    return g(digit);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    const int MAXN = 1e6;
    vector<vector<int>>cnt(10,vector<int>(MAXN+1,0));
    for(int i=1;i<=MAXN;i++){
        int val = g(i);
        for(int k=1;k<=9;k++){
            cnt[k][i] = cnt[k][i-1];
        }
        cnt[val][i]++;
    }
    int q;
    cin >> q;
    while(q--){
        
        int l, r, k;
        cin >> l >> r >> k;
        cout << cnt[k][r] - cnt[k][l-1] << "\n";
    }
    return 0;
}