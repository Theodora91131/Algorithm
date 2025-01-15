#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct DisjointSet {
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
    }

    int findSet(int v) {
        if (v == parent[v]) {
            return v;
        }
        return parent[v] = findSet(parent[v]);
    }

    void unionSets(int a, int b) {
        a = findSet(a);
        b = findSet(b);
        if (a != b) {
            if (size[a] < size[b]) {
                swap(a, b);
            }
            parent[b] = a;
            size[a] += size[b];
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    DisjointSet dsu(n);

    set<pair<int, int>> peaceSet;

    for (int i = 0; i < m; ++i) {
        int eventType, x, y;
        cin >> eventType >> x >> y;

        if (eventType == 1) {
            // Check if x and y are in the same set (commonwealth)
            if (dsu.findSet(x) != dsu.findSet(y)) {
                dsu.unionSets(x, y);
            }
            peaceSet.insert({min(x, y), max(x, y)});
        } else {
            // Check if x and y are in the same set (commonwealth)
            if (dsu.findSet(x) == dsu.findSet(y) || peaceSet.count({min(x, y), max(x, y)})) {
                cout << "peace" << endl;
            } else {
                // Compare military power and determine the result
                cout << (dsu.size[dsu.findSet(x)] == dsu.size[dsu.findSet(y)] ? "draw" : (dsu.size[dsu.findSet(x)] > dsu.size[dsu.findSet(y)] ? "win" : "lose")) << endl;
            }
        }
    }

    return 0;
}

