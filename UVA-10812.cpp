#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    int n, a, b, s, d;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> s >> d;
        if (s >= d && (s + d) % 2 == 0) // 檢查s+d是否為負值，落s+d不是偶數，則a和b不可能是負整數
        {
            a = (s + d) / 2;
            b = (s - d) / 2;
            cout << a << " " << b << endl;
        }
        else
        {
            cout << "impossible" << endl;
        }
    }
    return 0;
}