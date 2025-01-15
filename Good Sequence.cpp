# include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<int>s(n);
	map<int,int>ss;
	for(int i=0; i<n; i++){
		cin >> s[i];
	}
	for(int i=0; i<n; i++){
		ss[s[i]]++;
	}
	int rm=0;
	for(int i=0; i<n; i++){
		if(ss[s[i]]>s[i]){
			rm += ss[s[i]]-s[i];
			ss[s[i]] = s[i];
		
		}else if(ss[s[i]]<s[i]){
			rm += ss[s[i]];
			ss[s[i]] = s[i];
		}
	} 
	cout << rm;
	 
	return 0;
}
