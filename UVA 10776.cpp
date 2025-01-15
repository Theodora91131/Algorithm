#include <bits/stdc++.h>
using namespace std;

const int N = 30;
vector<int> vis(N);
set<string> arr;
string str;
int k;
int s;

void dfs(int index, int now) {
    if (now == k) {
        string ans;
        for (int i = 0; i < s; i++) {
            if (vis[i]) ans += str[i];
        }
        if (arr.count(ans) == 0) {
            arr.insert(ans);
            cout << ans << endl;
        }
        return;
    }

    if (index >= s || s - index + now < k) return;

    char pre = ' ';
    for (int i = index; i < s; i++) {
        if (!vis[i] && str[i] != pre) {
            pre = str[i];
            vis[i] = 1;
            dfs(i + 1, now + 1);
            vis[i] = 0;
        }
    }
}

int main() {
    while (cin >> str >> k) {
        s = str.size();
        if (k > s) {
            return 0;
        }
        sort(str.begin(), str.end());
        arr.clear();
        dfs(0, 0);
    }
    return 0;
}

