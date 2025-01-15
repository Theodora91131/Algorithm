#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

unordered_map<string, string> f; // 根節點
unordered_map<string, int> sz;   // 宣告 sz 陣列，紀錄每個節點的為根的集合大小

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
    int t; // 測試用例的數量
    cin >> t;

    while (t--) {
        int n; // 新關係的數量
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
            cout << sz[find(a)] << endl; //查詢元素 x所在的集合大小只需要找到 x 的集合的根節點
//查詢集合大小問題 

        }
    }

    return 0;
}

