#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_set>

int f[100005], sz[100005];

using namespace std;

void init() {
    for (int i = 1; i <= 100001; i++) {
        f[i] = i;
        sz[i] = 1;
    }
}

int find(int x) {//��g�L�`�I�����`�I�]���ڵ��I 
    if (f[x] == x) return x;
    return find(f[x]); //�^��x���ڵ��I 
}

void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    if (sz[x] < sz[y]) swap(x, y);  
    sz[x] += sz[y];//�d�ߤ��� x(�ڵ��I)�Ҧb�����X�j�p�u�ݭn��� x �����X���ڸ`�I
    f[y] = x;//��䤤�@�Ӯڸ`�I�����`�I�]���t�@�Ӯڸ`�I
}

int countComponent(int n) { //��s�q�ƶq (�N�O�۲����X���ƶq) 
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        if (find(i) == i) //�ˬd���� i �O�_�O��ۨ��Ҧb�s�q�����ڸ`�I 
            ret++;
    }
    return ret;
}

int main() {
    int n, m, a, b;
    init();
    cin >> n >> m;
    while (m--) {
        cin >> a >> b;
        merge(a, b);
    }
    cout << countComponent(n)-1 << endl;
//  unordered_set<int> parent;
//  for(int i = 1; i <= n; i++){
//		parent.insert(find(i));
//	}
//	cout << parent.size()-1 << endl;
    return 0;
}

