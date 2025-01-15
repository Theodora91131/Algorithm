#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
using namespace std;

bool isSafe(vector<vector<int>>& mat, vector<vector<bool>>& visited, int x, int y) {
    return (x >= 0 && x < mat.size() && y >= 0 && y < mat[0].size()) &&
           mat[x][y] == 0 && !visited[x][y];
}

void findShortestPath(vector<vector<int>>& mat, vector<vector<bool>>& visited,
                      int i, int j, int x, int y, int& min_dist, int dist) {
    if (i == x && j == y) {
        min_dist = min(dist, min_dist);
        return;
    }

    visited[i][j] = true;

    if (isSafe(mat, visited, i - 1, j)) {
        findShortestPath(mat, visited, i - 1, j, x, y, min_dist, dist + 1);
    }

    if (isSafe(mat, visited, i, j + 1)) {
        findShortestPath(mat, visited, i, j + 1, x, y, min_dist, dist + 1);
    }

    if (isSafe(mat, visited, i + 1, j)) {
        findShortestPath(mat, visited, i + 1, j, x, y, min_dist, dist + 1);
    }

    if (isSafe(mat, visited, i, j - 1)) {
        findShortestPath(mat, visited, i, j - 1, x, y, min_dist, dist + 1);
    }

    visited[i][j] = false;
}

int findShortestPathLength(vector<vector<int>>& mat, pair<int, int>& src, pair<int, int>& dest) {
    if (mat.size() == 0 || mat[src.first][src.second] == 1 ||
        mat[dest.first][dest.second] == 1) {
        return -1;
    }

    int M = mat.size();
    int N = mat[0].size();

    vector<vector<bool>> visited(M, vector<bool>(N));

    int min_dist = INT_MAX;
    findShortestPath(mat, visited, src.first, src.second, dest.first, dest.second, min_dist, 0);

    if (min_dist != INT_MAX) {
        return min_dist;
    }

    return -1;
}

int main() {
    int mazeRows, mazeCols, startX, startY, endX, endY;
    cin >> mazeRows >> mazeCols >> startX >> startY >> endX >> endY;

    vector<vector<int>> maze(mazeRows, vector<int>(mazeCols));

    for (int i = 0; i < mazeRows; i++) {
        for (int j = 0; j < mazeCols; j++) {
            char c;
            cin >> c;
            maze[i][j] = c - '0';
        }
    }

    pair<int, int> src(startX - 1, startY - 1);
    pair<int, int> dest(endX - 1, endY - 1);

    int min_dist = findShortestPathLength(maze, src, dest);

    if (min_dist != -1) {
        cout << min_dist << endl;

        vector<pair<int, int>> path;
        vector<vector<bool>> visited(mazeRows, vector<bool>(mazeCols));

        findShortestPath(maze, visited, src.first, src.second, dest.first, dest.second, min_dist, 0);

        path.push_back(src);

        // 回溯找到最短路徑
        while (src != dest) {
            int i = src.first;
            int j = src.second;

            if (isSafe(maze, visited, i - 1, j)) {
                src = make_pair(i - 1, j);
            } else if (isSafe(maze, visited, i, j + 1)) {
                src = make_pair(i, j + 1);
            } else if (isSafe(maze, visited, i + 1, j)) {
                src = make_pair(i + 1, j);
            } else if (isSafe(maze, visited, i, j - 1)) {
                src = make_pair(i, j - 1);
            }

            path.push_back(src);
        }

        // 輸出最短路徑
        for (const auto& p : path) {
            cout << "(" << p.first + 1 << "," << p.second + 1 << ")" << endl;
        }
    } else {
        cout << "Destination cannot be reached from the given source." << endl;
    }

    return 0;
}

