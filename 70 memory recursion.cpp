#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int climbStairs(int a,vector<int>&memory){
	if(a == 1 || a == 0){
		return 1;
	}else{
		if(memory[a] != -1){
			return memory[a];
		}
		memory[a]=climbStairs( a - 1, memory) + climbStairs( a - 2,memory );
		return memory[a];
	}	
	
}
int main(){
	int n;
	cin >> n;
	vector<int> memory(n,-1);
	for (int i = 0; i < n; ++i) {  
        	cout << climbStairs(i,memory) << " "; 
    }     
    cout << endl; 
	return 0;
} 
