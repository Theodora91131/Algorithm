#include<iostream>
#include<algorithm>
#include <cmath>
using namespace std;
int main() {
    long long a, b, c;
    while (cin >> a >> b) {
        c = abs(a) - abs(b);
        cout << abs(c) << endl;
    }
    return 0;
}