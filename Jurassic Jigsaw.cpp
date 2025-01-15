/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int f[1005], sz[1005];

struct Edge {
    int u, v, w;
    bool operator < (const Edge& rhs) const {
        return w < rhs.w;
    }
};

void init() {
    for(int i = 0; i < 1005; i++) {
        f[i] = i; 
        sz[i] = 1;
    }
}

int find(int x) {
    if(f[x] == x) return x;
    return f[x] = find(f[x]);
}

void merge(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return;
    if(sz[x] < sz[y]) swap(x, y);
    sz[x] += sz[y];
    f[y] = x;
}

int differ(string &a, string &b) {
    int sum = 0;
    for(int i = 0; i < a.length(); i++) {
        if(a[i] != b[i]) sum++;
    } 
    return sum;
} 

int main() {
    init();
    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> output;
    vector<string> samples(n);
    vector<Edge> graph;
    
    for(int i = 0; i < n; i++) {
        cin >> samples[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int weight = differ(samples[i], samples[j]);
            graph.push_back({i, j, weight});
        }
    }
    
    sort(graph.begin(), graph.end());
    
    int ans = 0;
    for(int i = 0; i < graph.size(); i++) {
        if(find(graph[i].u) != find(graph[i].v)) { // 如果兩點未聯通
            merge(graph[i].u, graph[i].v); // 將兩點設成同一個集合
            ans += graph[i].w; // 權重加進答案
            output.push_back({graph[i].u, graph[i].v});
            if(sz[find(graph[i].u)] == n) break; //當並查集大小等價於樹內點的數量
        }
    }
    
    cout << ans << endl;
    
    for(int i = 0; i < output.size(); i++) {
        cout << output[i].first << " " << output[i].second << endl;
    }
    
    return 0;
}

