#include <iostream>
#include <vector>
using namespace std;
vector<int> ink_table(36, 0);
vector<int> ink(37, 0);
int main()
{
    int n;
    cin >> n; // 幾次
    for (int i = 1; i <= n; ++i)
    {
        if (i > 1)
        {
            cout << endl;
        }
        cout << "Case " << i << ":" << endl;
        fill(ink_table.begin(), ink_table.end(), 0);
        for (int j = 0; j < 36; ++j)
        {
            cin >> ink_table[j]; // 輸入紀錄表
        }
        int m;
        cin >> m;
        while (m--) // 幾個測試資料
        {
            int test;
            cin >> test; // 輸入測試資料
            fill(ink.begin(), ink.end(), 0);
            for (int k = 2; k <= 36; ++k) // 2 到 36進位
            {
                int t = test;
                while (t)
                {
                    ink[k] += ink_table[t % k]; // 算n進位的餘數並用他來查需要的Ink cost
                    t /= k;
                }
            }
            int min_cost = 999999;
            for (int r = 2; r <= 36; ++r)
            {
                min_cost = min(ink[r], min_cost); // 找最小ink cost
            }
            cout << "Cheapest base(s) for number " << test << ":";
            for (int r = 2; r <= 36; ++r)
            {
                if (min_cost == ink[r])
                {
                    cout << " " << r;
                }
            }
            cout << endl;
        }
    }
    return 0;
}