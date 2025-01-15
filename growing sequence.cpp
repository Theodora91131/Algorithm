#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> x(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }
        int a_i = 0;
        for (int i = 0; i < n; i++) {
            int y = a_i & ~x[i];
            cout << y << ' ';
            x[i] ^= y;
			swap(a_i,x[i]);
        }
        cout << endl;    
    }
    return 0;
}

