#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int climbStairs(int a){
	if(a == 1 || a == 0){
		return 1;
	}else{
		return climbStairs( a - 1 ) + climbStairs( a - 2 );
	}	
	
}
int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {  
       	cout << climbStairs(i) << " ";
    }     
    cout << endl; 
	return 0;
} 
