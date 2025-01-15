#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

int MaxiumCrossingarray(vector<int> &vec2,int low,int mid,int high){
	int left_Sum = INT_MIN;
	int sum = 0;
	for(int i = mid; i>=low; i--){
		sum = sum + vec2[i];
		if(sum > left_Sum){
			left_Sum = sum;	
		}
	}
	sum = 0;
	int right_Sum = INT_MIN;
	for(int j = mid+1; j<=high; j++){
		sum = sum + vec2[j];
		if (sum > right_Sum){
			right_Sum = sum;
		}
	}
	return left_Sum + right_Sum;
}
int divide(vector<int> &vec1, int l, int h){
	if(l== h){
		return vec1[l];
	}else
	{
		int mid = (l+h) /2;
   		return std::max(std::max(divide(vec1, l, mid), divide(vec1, mid+1, h)), MaxiumCrossingarray(vec1, l, mid, h));
	}
}
    

int main(){
    vector<int> A;	
	int a,i =0;
	while(cin>>a){	 
		 A.insert(A.end(), a); 
		char ch = getchar();
		if(ch == '\n')
			break;
	}
   int max_sum = divide(A,0, A.size()-1);
    cout << max_sum ;
	cout << endl;
	return 0;
}
