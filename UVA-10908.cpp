#include<iostream>
#include<vector>
using namespace std;

int t, N, M, Q, r, c;
char now;
vector<vector<char>> matrix;

bool chek(int n) {
    if (r - n < 0 || r + n >= M || c - n < 0 || c + n >= N) return false;
    for (int i = r - n; i <= r + n; i++) {
        if (matrix[i][c - n] != now || matrix[i][c + n] != now)
            return false;
    }
    for (int j = c - n + 1; j <= c + n - 1; j++) {
        if (matrix[r - n][j] != now || matrix[r + n][j] != now)
            return false;
    }
    return true;
}

int main() {
    cin >> t;
    while (t--) {
        cin >> M >> N >> Q;
        matrix.assign(M, vector<char>(N)); // assign (not resize) to clear previous test cases
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                cin >> matrix[i][j];
            }
        }
        cout << M << " " << N << " " << Q << endl;
        while (Q--) {
            cin >> r >> c;
            now = matrix[r][c];
            int cnt = 0;
            while (chek(cnt + 1)) cnt++;
            cout << 2 * cnt + 1 << endl;
        }
    }
    return 0;
}
