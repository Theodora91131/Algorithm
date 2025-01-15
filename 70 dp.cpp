#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int climbStairs(int n,vector<int>&dp){
	if(n == 1 || n == 0){
		return 1;
	}
	for(int i = 2; i<=n; i++){
		dp[i] = dp[i-1] + dp[i-2]; 
	}
	return dp[n];
}
int main(){
	int n;
	cin >> n;
	vector<int> dp(n);
	dp[0] = dp[1] = 1;
    climbStairs(n,dp); 
    for(int i = 0; i < n; i++){
    	cout << dp[i] <<" ";
	}
	return 0;
} 
