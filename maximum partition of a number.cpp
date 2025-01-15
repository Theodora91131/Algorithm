#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    string x;
    cin >> x;

    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        int maxS = 0;
        for (int j = 1; j <= m && i - j >= 0; j++) {
            maxS = max(maxS, stoi(x.substr(i - j, j))); //stoi(x.substr(i - j, j)) ���N��O�N x ���� i - j �}�l�� j �Ӧr�Ū��l�r���ഫ����ơC�o�˪��ާ@�D�n�O���F������Ϋ᪺�C�ӳ������ƭȡA�H�K�i�����M�p��
            dp[i] = max(dp[i], dp[i - j] + maxS);
        }
    }

    cout << dp[n] << endl;

    return 0;
}

