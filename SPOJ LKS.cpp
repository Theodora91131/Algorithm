#include<bits/stdc++.h>
using namespace std;
struct backpack{
    int weight;
    int value;
};
int main(){
    int k,n;
    cin>>k>>n;
    vector<backpack> items(n);
    vector<vector<int>> dp(n+1,vector<int>(k+1,0));
    for(int i=0;i<n;i++){
        cin>>items[i].value>>items[i].weight;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<=k;j++){
            if(j-items[i].weight<0){
                dp[i+1][j]=dp[i][j];
            }else{
                dp[i+1][j]=max(dp[i][j],dp[i][j-items[i].weight]+items[i].value);
            }
        }
    }
    cout<<dp[n][k]<<endl;
    return 0;
}