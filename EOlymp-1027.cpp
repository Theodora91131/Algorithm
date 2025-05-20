#include<iostream>
#include<vector>
using namespace std;
int main() {
    int k;                 //1/k=(1/y)+(1/x)
    while (cin >> k && k) { //對於每個y>k, 我們能嘗試計算對應x
        vector<int> x, y;
        for (int i = k + 1; i <= 2 * k; i++) { //列舉y 設定上界理由 若y>2k 則x=(ky/(y-k)) < ky/k =u  x<y不合法
            if (k * i % (i - k) == 0) {  //x=(ky/(y-k))
                x.push_back(i * k / (i - k));
                y.push_back(i);
            }
        }
        cout << x.size() << endl;
        for (int i = 0; i < x.size();i++) {
            cout << "1/" << k << " = 1/" << x[i] << " + 1/" << y[i] << endl;
        }
    }
    return 0;
}
