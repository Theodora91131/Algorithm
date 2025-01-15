#include <iostream>
using namespace std;

int main()
{
    int Num[100001] = {0}; // 初始化所有元素為 0重要 不然 1 100000測資會完蛋

    // 計算 1 到 100000 的完全平方數
    for (int i = 1; i * i < 100001; ++i)
    {
        Num[i * i] = 1;
    }

    // 計算前綴和，Num[i] 表示從 1 到 i 的完全平方數總數
    for (int i = 1; i < 100001; ++i)
    {
        Num[i] += Num[i - 1];
    }

    int a, b;
    while (cin >> a >> b)
    {
        if (a == 0 && b == 0)
        {
            break;
        }

        cout << Num[b] - Num[a - 1] << endl;
    }
    return 0;
}
