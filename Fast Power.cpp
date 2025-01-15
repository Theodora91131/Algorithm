#include<bits/stdc++.h>
using namespace std;
int main(){
	long long a, b, c;
	long long ans=1;
	cin >> a >> b >> c;
	while(b){
		if(b&1){
			ans = (ans * a)%c;
		}
		a = (a * a)%c;
		b >>= 1;
	}
	cout << ans <<endl;
	return 0;
} 
