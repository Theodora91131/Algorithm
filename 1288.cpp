#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>

using namespace std;
bool cmp(pair<int,int>p1, pair<int,int>p2){
	if(p1.first == p2.first){
		return p2.second > p1.second;
	}else{
		return p2.first > p1.first;
	}
}
int main(){
	int a;
	cin >> a;
	vector<pair<int,int>> intervals(a);
	for(int i = 0; i < a ; i++){
		cin >> intervals[i].first >> intervals[i].second;
	}
	int end = -1, length = 0, e=0, s=0, cnt = 0;
	sort(intervals.begin(),intervals.end(),cmp);
	for(int i = 0; i < intervals.size(); i++){
		s = intervals[i].first;
		e = intervals[i].second;
		 if(e > end){
			cnt++;
			end = e;
		}
	}
	cout << cnt << endl;
	return 0;
} 
