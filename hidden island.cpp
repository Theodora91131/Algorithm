#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class UnionFind {
public:
    vector<int> parent, rank, setSize;

    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 1);
        setSize.resize(n, 1);

        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y, unordered_map<int, int>& islandRoots, int& num) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
                setSize[rootX] += setSize[rootY];
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
                setSize[rootY] += setSize[rootX];
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
                setSize[rootX] += setSize[rootY];
            }

            islandRoots.erase(rootX);
            islandRoots.erase(rootY);
            islandRoots[rootX] = setSize[rootX];

            num--;
        }
    }
};

int main() {
    int n;
    cin >> n;

    vector<vector<int>> grid(1001, vector<int>(1001, 0));
    UnionFind uf(1001 * 1001);
    unordered_map<int, int> islandRoots;
    int num = 0;

    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;

        if (grid[x][y] == 0) {
            // If the square is not adjacent to any existing island, treat it as a new island
            islandRoots[x * 1001 + y] = 1;
            num++;
        }

        grid[x][y] = 1;

        // Check adjacent squares
        int nx, ny;

        // Check up
        nx = x - 1;
        ny = y;
        if (nx >= 1 && grid[nx][ny] == 1) {
            uf.unite(x * 1001 + y, nx * 1001 + ny, islandRoots, num);
        }

        // Check down
        nx = x + 1;
        ny = y;
        if (nx <= 1000 && grid[nx][ny] == 1) {
            uf.unite(x * 1001 + y, nx * 1001 + ny, islandRoots, num);
        }

        // Check left
        nx = x;
        ny = y - 1;
        if (ny >= 1 && grid[nx][ny] == 1) {
            uf.unite(x * 1001 + y, nx * 1001 + ny, islandRoots, num);
        }

        // Check right
        nx = x;
        ny = y + 1;
        if (ny <= 1000 && grid[nx][ny] == 1) {
            uf.unite(x * 1001 + y, nx * 1001 + ny, islandRoots, num);
        }

        cout << num << endl;
    }

    return 0;
}

