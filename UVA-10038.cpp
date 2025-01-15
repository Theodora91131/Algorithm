#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int n;
    vector<int> order(3000, 0);
    vector<int> num;

    while (cin >> n)
    {
        num.resize(n);
        fill(order.begin(), order.end(), 0); // 初始化 order
        bool flag = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> num[i];
        }

        for (int i = 0; i < n - 1; ++i)
        {
            int diff = abs(num[i] - num[i + 1]);
            if (diff > 0 && diff < n)
            {
                order[diff] = 1;
            }
        }

        for (int i = 1; i <= n - 1; ++i) // 確保所有 1 到 n-1 都出現
        {
            if (order[i] != 1)
            {
                flag = 1;
                break;
            }
        }

        if (flag)
        {
            cout << "Not jolly" << endl;
        }
        else
        {
            cout << "Jolly" << endl;
        }
    }

    return 0;
}
