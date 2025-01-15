#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

unordered_map<string, string> f; // �ڸ`�I
unordered_map<string, int> sz;   // �ŧi sz �}�C�A�����C�Ӹ`�I�����ڪ����X�j�p

string find(string x) {
    if (f[x] == x) return x;
    f[x] = find(f[x]);
    return f[x];
}

void merge(string a, string b) {
    a = find(a), b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    f[b] = a;
}

int main() {
    int t; // ���եΨҪ��ƶq
    cin >> t;

    while (t--) {
        int n; // �s���Y���ƶq
        cin >> n;
		f = unordered_map<string,string>();
		sz = unordered_map<string,int>();
        for (int i = 0; i < n; ++i) {
            string a, b;
            cin >> a >> b;

            if (f.find(a) == f.end()) {
                f[a] = a;    
            }
            if (f.find(b) == f.end()) {
                f[b] = b;
            }
            if(sz.find(a) == sz.end()){
            	sz[a] = 1;
			}
			if(sz.find(b) == sz.end()){
            	sz[b] = 1;
			}
            merge(a, b);
            cout << sz[find(a)] << endl; //�d�ߤ��� x�Ҧb�����X�j�p�u�ݭn��� x �����X���ڸ`�I
//�d�߶��X�j�p���D 

        }
    }

    return 0;
}

