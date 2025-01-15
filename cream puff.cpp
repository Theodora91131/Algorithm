#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<long long> arr;
	long long n;
	cin >> n;
	for(int i=1; i<=sqrt(n); i++){
		if(n%i==0){
			arr.push_back(n/i);
			arr.push_back(i);
		}
	}
	sort(arr.begin(),arr.end());
	for(int i=0; i<arr.size(); i++){
		if(arr[i]==arr[i-1]){
			continue;
		}else{
			cout << arr[i] << endl;
		}
		
	}
	return 0;
}	


