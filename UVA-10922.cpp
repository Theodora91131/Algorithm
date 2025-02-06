#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main() {
    string str;
    while (cin >> str && str != "0") {
        int csum = 0, cnt = 1;
        for (int i = 0;i < str.length();++i) {
            csum += (str[i] - '0');    //stoi只能用在string str[i]是char所以不能這樣做
        }
        while (csum % 9 == 0 && csum != 9) {
            int sum = 0;
            while (csum > 0) {
                sum += csum % 10;
                csum /= 10;
            }
            csum = sum;
            cnt++;
        }

        if (csum % 9 != 0) {
            cout << str << " is not a multiple of 9." << endl;
        }
        else {
            cout << str << " is a multiple of 9 and has 9-degree " << cnt << "." << endl;
        }
    }
    return 0;
}