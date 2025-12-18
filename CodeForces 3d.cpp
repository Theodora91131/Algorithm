#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();

    vector<pair<long long,long long>> q;
    for (char c : s) {
        if (c == '?') {
            long long a, b;
            cin >> a >> b;
            q.push_back({a, b});
        }
    }

    long long cost = 0;
    int balance = 0;
    int qi = 0;

    // 存 的是 ')' 還 ? (a-b, index)
    set<pair<long long,int>> st;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') balance++;
        else if (s[i] == ')') balance--;
        else {
            auto [a, b] = q[qi++];
            s[i] = ')';
            cost += b;
            balance--;
            st.insert({a - b, i});
        }

        while (balance < 0) { // balance 負了，表示多了 )，需要把某個 ? 從 ) 變成 ( 而因為可能有多個 ))) ，所以要用 while 而不是 if
            if (st.empty()) {
                cout << -1 << '\n';
                return 0;
            }
            auto it = st.begin();
            cost += it->first;   //把這個 ? 從 ) 改成 ( 要「多付」的錢
            s[it->second] = '('; //真的把字串中那個位置改成 (
            balance += 2; //因為原本是 ) 現在變 (，所以 balance 多 2
            st.erase(it);
        }
    }

    //  關鍵補救段
    while (balance > 0) { // 多餘的 (，需要把某個 ? 從 ( 變成 )
        if (st.empty()) {
            cout << -1 << '\n';
            return 0;
        }
        auto it = st.begin();
        cost += it->first;
        s[it->second] = '(';
        balance += 2;
        st.erase(it);
    }

    cout << cost << '\n';
    cout << s << '\n';
}
