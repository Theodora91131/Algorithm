#include<bits/stdc++.h>
# define int long long
using namespace std;
string str;

vector<int> arr(12,0);
int d,t,ans,sum=0,len=0;

void dfs(int index){
	if(index==len){
		if(ans%d==0){
			sum++;
		}
		return;
	}
	for(int i=0; i<10; i++){
		if(arr[i]>0){
			ans = ans*10+i; //���@�� 
			arr[i]--;
			dfs(index+1);
			ans/=10; //�k�@�� 
			arr[i]++;
		}
	}
}


int32_t main(){
	cin >> t;
	while(t--){	
		sum = 0;
		ans=0;
		str.clear();
		for(int i=0; i<10; i++){
			arr[i]=0 ;
		}
		cin >> str >> d;
	
		len = str.size();
		for(int i=0; i<len; i++){ //����p�⥲���Ҽ{���ƪ����� 
			arr[str[i]-'0']++;
		}
		dfs(0);
		cout << sum << endl; 
	}
	return 0; 
}
