#include<bits/stdc++.h>

const int MaxN = 1000005;
int fact[MaxN];
using namespace std;
int main(){
	int n, cnt ,p;
	for(long long i =2; i<=MaxN;i++){
		if(!fact[i]){
			fact[i]=i;
			for(long long j=i; j<=MaxN; j+=i){
				if(!fact[j]){
					fact[j]=i;
				}
			}
		}
	}
	while(cin>>n && n){
		int temp = n;
		int cnt = 0;
		while(temp != 1){
			int p = fact[temp];
			cnt++;
			while(temp %p ==0){
				temp /=p;
			}
		}
		cout << n <<" : "<<cnt<<endl;
	} 


	return 0;
}
