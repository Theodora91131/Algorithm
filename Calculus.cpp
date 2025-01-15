#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<long long> a(n), b(n), x(m);
    vector<long long> areas;
    areas.reserve(m);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    for (int i = 0; i < m; ++i) {
        cin >> x[i];
    }

    for (int i = 0; i < m; ++i) {
        long long x_val = x[i];

        for (int j = 0; j < n; ++j) {
            long long high = min(b[j], x_val);
            long long area = max(0LL, high - a[j]);
            areas.emplace_back(area);
        }

        long long total_area = 0;
        for (long long val : areas) {
            total_area += val;
        }

        cout << total_area;
        if (i < m - 1) {
            cout << " ";
        }

        areas.clear();  // 清除 areas 向量，以便下一次使用
    }

    cout << "\n";

    return 0;
}

