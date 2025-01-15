#include<algorithm>
#include<iostream>
using namespace std;
const int N=1e5+5;
int arr[N]={};
int ans[N]={};
bool vis[N]={};
int n;
void dfs(int index){
	if(index>n){  // 超過陣列範圍
		for(int i=1;i<=n;i++){  // 輸出答案
			cout<<ans[i]<<" \n"[i==n];
		}
	}
	for(int i=1;i<=n;i++){
    if(!vis[i]){  // 檢查當前這項是否在ans裡
        ans[index]=arr[i];  // 將當前這項加入ans裡
        vis[i]=1;   // 標記為有在裡面
        dfs(index+1);  // 呼叫下一個遞迴
        ans[index]=0;  // 把答案移除
        vis[i]=0;  // 這個遞迴結束後移除標記
    }
}
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    sort(arr+1,arr+n+1);  //排序
    dfs(1);  //呼叫遞迴函數
}
