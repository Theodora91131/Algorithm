#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
using namespace std;
bool cmp(int a, int b){
	return(to_string(a)+to_string(b) > to_string(b)+to_string(a));
}


int main(){
	string n, tmp,ans;
	getline(cin, n);
	istringstream ss (n);
	vector<int>nums;
	while(ss >> tmp){
		nums.push_back(stoi(tmp));
	}
	sort(nums.begin(),nums.end(),cmp);
	for(const auto& a: nums){
		ans += to_string(a);
	}
	cout << ans<< endl;
	return 0;
	
} 
