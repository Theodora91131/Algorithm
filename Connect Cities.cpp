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

int find(int x) {//把經過節點的父節點設成根結點 
    if (f[x] == x) return x;
    return find(f[x]); //回傳x的根結點 
}

void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    if (sz[x] < sz[y]) swap(x, y);  
    sz[x] += sz[y];//查詢元素 x(根結點)所在的集合大小只需要找到 x 的集合的根節點
    f[y] = x;//把其中一個根節點的父節點設為另一個根節點
}

int countComponent(int n) { //算連通數量 (就是相異集合的數量) 
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        if (find(i) == i) //檢查城市 i 是否是其自身所在連通塊的根節點 
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

