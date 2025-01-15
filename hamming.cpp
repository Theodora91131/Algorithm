#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 生成長度為N，Hamming距離為H的二元字串
void generateBinaryStrings(int N, int H, string current, int onesCount) {
    // 已達到目標Hamming距離
    if (current.length() == N && onesCount == H) {
        cout << current << endl;
        return;
    }

    // 尚未達到目標長度
    if (current.length() < N) {
        // 添加0
        generateBinaryStrings(N, H, current + '0', onesCount);
        // 添加1（前提是剩餘的1的個數足夠）
        if (onesCount < H) {
            generateBinaryStrings(N, H, current + '1', onesCount + 1);
        }
    }
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N, H;
        cin >> N >> H;

        generateBinaryStrings(N, H, "", 0);

        if (t < T - 1) {
            cout << endl;  // 測試資料間換行
        }
    }

    return 0;
}

