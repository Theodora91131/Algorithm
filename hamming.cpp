#include <iostream>
#include <string>
#include <vector>

using namespace std;

// �ͦ����׬�N�AHamming�Z����H���G���r��
void generateBinaryStrings(int N, int H, string current, int onesCount) {
    // �w�F��ؼ�Hamming�Z��
    if (current.length() == N && onesCount == H) {
        cout << current << endl;
        return;
    }

    // �|���F��ؼЪ���
    if (current.length() < N) {
        // �K�[0
        generateBinaryStrings(N, H, current + '0', onesCount);
        // �K�[1�]�e���O�Ѿl��1���Ӽƨ����^
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
            cout << endl;  // ���ո�ƶ�����
        }
    }

    return 0;
}

