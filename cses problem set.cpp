#include<iostream>
#include<algorithm>
#include<string> 
using namespace std;
int f[100000005], sz[100000005];
char arr[100000005];
int n, m, k, a;
void init(){
	for(int i = 0; i < n * m; i++){
		f[i] = i;
		sz[i] = 1;
	}
}
int find(int x){
	if(f[x] == x) return x;
	return find(f[x]);
}
void merge(int x, int y){
	x = find(x), y = find(y);
	if(x == y) return;
	if(sz[x] < sz[y]) swap(x,y);
	sz[x] += sz[y];
	f[y] = x;
}
int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> arr[i * m + j];//�N�G���a�ϬM�g��@���}�C�A�ڭ̱N�C�@�檺�r�Ũ̦��s�x�b�@���}�C���C�b�s�x�C�@��ɡA�C�@�C���r�Ŧb�@���}�C�������ޱN�O�Ӧ檺�����q�C
			//�]���A�b�s�x�a�Ϥ����C�@��ɡA�ڭ̱N�C�@�C���r�ū��Ӷ��Ǧs�x��@���}�C���A�ݭn�N�C�� m �Ҽ{�b���A�q�L�N i ���H�a�Ϫ��C�� m�A�M��[�W j�A�o��b�@���}�C arr �����������ޡA�Y i * m + j�C
		}
	}
	init();

	for(int k = 0; k < n * m; k++){
		if(arr[k] == '#'){
			f[k] = 0;
		}
		else if(arr[k] == '.'){
			if(arr[ k + 1] == '.'&&k%m != (m-1)){  //k % m != (m - 1) �ˬd���O�a�Ϥ����C�@�檺�̫�@�Ӧr�šA
				merge(k, k+1); //�H�T�O�b���� k + 1 �ާ@�ɤ��|�W�X�a�Ϫ��d��C
			}					//����a�Ak % m ��� k �b��e�檺�C���ޡA(m - 1) �O��e�檺�̫�@�C�����ޡC
			if(arr[k+m] == '.'){ //�]���Ak % m != (m - 1) ��� k ���O��e�檺�̫�@�Ӧr�šA�o�˥i�H�T�O k + 1 �ާ@���|��V��U�@��C
				merge(k, k+m);//arr[ k + 1] == '.' ��e�r�Ū��k��@�Ӧ�m�O�Ŧa�]floor�^ �O�_�i�V�k�� 
							//arr[k + m] == '.': ��ܦb�a�Ϥ��A��e�r�Ū��U���@�Ӧ�m�O�Ŧa �O�_�i�V�U�� 
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < m*n; i++){ //��s�q�ƶq (�N�O�۲����X���ƶq) 
		if(find(i) == i){
			ans++;
		}
	}
	if(arr[0] == '.'){  //arr[0] == '.': �p�G�a�Ϫ��_�l��m�O�a�O�A�h������X�p��o�쪺�ж��ƶq ans�C
		cout << ans << endl;//�]���_�l��m�O�a�O�A���ݭn��h����ж��ƶq�C 
	}else {
		cout << ans - 1 << endl;//ans - 1: �p�G�a�Ϫ��_�l��m�O����A�h�ݭn��h�@�өж��ƶq�A�]���_�l��m���ݩ����@�өж��C
	}							//�ҥH�o�̱N�p��o�쪺�ж��ƶq ans ��h 1�A�M���X���G�C
	return 0;
}
