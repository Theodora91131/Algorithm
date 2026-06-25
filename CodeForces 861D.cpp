#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> phones(n);
    unordered_map<string, int> cnt;

    for (int k = 0; k < n; k++) {
        cin >> phones[k];

        set<string> local;

        for (int i = 0; i < 9; i++) {
            for (int len = 1; i + len <= 9; len++) {
                local.insert(phones[k].substr(i, len));
            }
        }

        for (auto &s : local) {
            cnt[s]++;
        }
    }

    for (auto &phone : phones) {
        string ans = phone;

        for (int len = 1; len <= 9; len++) {
            bool found = false;

            for (int i = 0; i + len <= 9; i++) {
                string sub = phone.substr(i, len);

                if (cnt[sub] == 1) {
                    ans = sub;
                    found = true;
                    break;
                }
            }

            if (found) break;
        }

        cout << ans << '\n';
    }

    return 0;
}