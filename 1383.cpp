#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
const int MOD = 1000000007;
int main(){
	int n,k;
	cin >> n >> k;
	vector<int>speed(n);
	vector<int>effc(n);
	for(int i = 0; i < n; i++){
		cin >> speed[i];	
	}
	for(int i = 0; i < n; i++){
		cin >> effc[i];	
	}
	vector<pair<int,int>> sp;
	for(int i = 0; i < n; i++){
		sp.emplace_back(effc[i],speed[i]);// Sort by efficiency in descending order
	}
	sort(sp.rbegin(),sp.rend());
  	priority_queue<int, vector<int>, greater<int>> pq;// Min heap for speeds
	long long maxPer = -1;
    long long sumSpeed = 0;
	for(int i = 0; i < n; i++){
		int sp_pq = sp[i].second;
		int eff = sp[i].first;
		sumSpeed += sp_pq;
		pq.push(sp_pq);
		if(pq.size() > k){
			sumSpeed -= pq.top();
			pq.pop();
		}
		maxPer = max(maxPer,sumSpeed*eff);	
	}
	cout << maxPer % MOD << endl;
	return 0;
} 
