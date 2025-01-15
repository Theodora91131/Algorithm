#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int climbStairs(int n){
	if(n == 1 || n == 0){
		return 1;
	}
	int prev = 1, curr =1;
	for(int i = 2; i <= n; i++){
		int temp = curr;
		curr = prev + curr;
		prev = temp;
	}
	return curr;
}
int main(){
	int n;
	cin >> n;
	for(int i = 0; i<n; i++){
	    cout << climbStairs(i) << " ";
	}
     
	return 0;
} 
