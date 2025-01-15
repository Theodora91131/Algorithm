#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	const int MAX = 100000;
	vector<int> bitCnt(MAX);
    for (int i = 1; i < MAX; i++) {
        bitCnt[i] = bitCnt[i >> 1] + (i & 1);
    }
    int n;
    cin >> n;
    while (n--) {
        long long l, r;
        cin >> l >> r;
        int maxCnt = -1;
        long long ans = -1;
        for (long long j = l; j <= r; j++) {
            int currentCount = bitCnt[j]; 
            if (currentCount > maxCnt) {
                maxCnt = currentCount;
                ans = j;
            }
        }
        cout << ans << endl;
    }

    return 0;
}

