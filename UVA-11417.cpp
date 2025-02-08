#include<iostream>
#include<vector>

using namespace std;
int GCD(int p, int q) {
    if (p < q) { return GCD(q, p); }
    if (q == 0) { return p; }
    return GCD(q, p % q);
}
int main() {
    int n;
    vector<int>ans(502, 0);
    for (int i = 1; i < 502; ++i) { ///預先處理
        int sum = 0;
        for (int j = 1;j < i; ++j) {
            sum += GCD(i, j);
        }
        ans[i] = ans[i - 1] + sum;
    }
    while (cin >> n && n != 0) {
        cout << ans[n] << endl;
    }

    return 0;
}
///法二//
/**#include <iostream>

using namespace std;

int GCD(int p, int q) {
    if (q == 0) {
        return p;
    }
    return GCD(q, p % q);
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        int G = 0;
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                G += GCD(i, j);
            }
        }
        cout << G << endl;
    }
    return 0;
}
 */