#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> start(n), end(n);
    vector<pair<int, int>> func(m);
    vector<long long> ans(m, 0);

    for (int i = 0; i < n; i++) cin >> start[i];
    for (int i = 0; i < n; i++) cin >> end[i];
    for (int i = 0; i < m; i++) {
        cin >> func[i].first;
        func[i].second = i;
    }

    sort(start.begin(), start.end());
    sort(end.begin(), end.end());
    sort(func.begin(), func.end());

    int s_pos = 0, e_pos = 0, temp = 0;
    long long total = 0, value = 0;

    for (int i = 0; i < m; i++) {
        while (e_pos < n && (end[e_pos] <= start[s_pos] || func[i].first > end[e_pos])) {
            total += (end[e_pos] - value) * temp;
            value = end[e_pos];
            temp--;
            e_pos++;
        }

        while (s_pos < n && end[e_pos] >= start[s_pos] && func[i].first > start[s_pos]) {
            total += (start[s_pos] - value) * temp;
            value = start[s_pos];
            temp++;
            s_pos++;
        }

        total += (func[i].first - value) * temp;
        value = func[i].first;
        ans[func[i].second] = total;
    }

    for (int i = 0; i < m - 1; i++) cout << ans[i] << " ";
    cout << ans[m - 1] << endl;

    return 0;
}

