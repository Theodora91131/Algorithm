#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> prime;

int main() {
    const int MAX = 1000000;
    vector<bool> isprime(MAX + 1, 0);
    isprime[0] = 1;
    isprime[1] = 1;

    for (int i = 2; i <= 1000; ++i) {
        if (!isprime[i]) {
            prime.push_back(i); //把質數記錄進質數表裡面
            for (long long j = i; i * j <= MAX; ++j) {
                isprime[i * j] = 1; //所有質數的倍數設成非質數
            }
        }
    }


    string n;
    while (cin >> n) {
        int num = stoi(n);
        if (isprime[num]) {
            cout << n << " is not prime." << endl;
        }
        else {
            string rn = n;
            reverse(rn.begin(), rn.end());
            int rnum = stoi(rn);
            if (!isprime[rnum] && !isprime[num] && rnum != num) {
                cout << n << " is emirp." << endl;
            }
            else {
                cout << n << " is prime." << endl;
            }
        }
    }
    return 0;
}
