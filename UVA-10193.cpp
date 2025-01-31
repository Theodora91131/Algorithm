#include<iostream>
#include<vector>
#include<cmath>
#include<string>
using namespace std;
long long binTODic(string& S) {
    long long dec = 0;
    for (char c : S) {
        dec = dec * 2 + (c - '0');
    }
    return dec;
}
long long gcd(long long p, long long q) {
    if (p < q) return gcd(q, p);
    if (q == 0) return p;
    return gcd(q, p % q);
}
int main() {
    int N;
    cin >> N;
    string S1, S2;
    for (int i = 1; i <= N; ++i) {
        cin >> S1 >> S2;
        long long N1 = binTODic(S1);
        long long N2 = binTODic(S2);
        if (gcd(N1, N2) > 1) {
            cout << "Pair #" << i << ": All you need is love!" << endl;
        }
        else {
            cout << "Pair #" << i << ": Love is not all you need!" << endl;
        }

    }

    return 0;
}

