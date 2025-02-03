#include<iostream>
#include<vector>

using namespace std;
int main() {
    int m, n;
    while (cin >> n >> m) {
        if ((n < 2) || (m < 2)) {
            cout << "Boring!" << endl;
            continue;
        }
        int temp = n;
        while (n % m == 0 && n > 1) {
            n = n / m;
        }
        if (n != 1) {
            cout << "Boring!" << endl;
        }
        else {
            while (temp % m == 0 && temp > 1) {
                cout << temp << " ";
                temp = temp / m;
            }
            cout << "1" << endl;
        }
    }
    return 0;
}