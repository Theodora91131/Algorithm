#include<algorithm>
#include<iostream>
using namespace std;
const int N=1e5+5;
int arr[N]={};
int ans[N]={};
bool vis[N]={};
int n;
void dfs(int index){
	if(index>n){  // �W�L�}�C�d��
		for(int i=1;i<=n;i++){  // ��X����
			cout<<ans[i]<<" \n"[i==n];
		}
	}
	for(int i=1;i<=n;i++){
    if(!vis[i]){  // �ˬd��e�o���O�_�bans��
        ans[index]=arr[i];  // �N��e�o���[�Jans��
        vis[i]=1;   // �аO�����b�̭�
        dfs(index+1);  // �I�s�U�@�ӻ��j
        ans[index]=0;  // �⵪�ײ���
        vis[i]=0;  // �o�ӻ��j�����Ჾ���аO
    }
}
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    sort(arr+1,arr+n+1);  //�Ƨ�
    dfs(1);  //�I�s���j���
}
