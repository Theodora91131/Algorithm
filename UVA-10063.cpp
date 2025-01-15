#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> b(10005, 0);
    int n, t = 0, i, j;
    while (cin >> n)
    {
        bool b2 = 1;
        for (int i = 1; i <= n; ++i)
        {
            cin >> b[i];
            if (b[i] <= b[i - 1])
            {
                b2 = 0;
            }
        }
        vector<int> note(20005, 0);
        if (b2 == 1)
        {
            for (int i = 1; i <= n; ++i)
            {
                for (int j = i; j <= n; ++j)
                {
                    if (note[b[i] + b[j]] != 0) // 表示這個和已經在之前的計算中出現過
                    {
                        b2 = 0;
                    }
                    note[b[i] + b[j]] = 1; // 記錄這個和已經出現過
                }
            }
        }
        if (b2)
        {
            cout << "Case #" << ++t << ": It is a B2-Sequence." << endl
                 << endl;
        }
        else
        {
            cout << "Case #" << ++t << ": It is not a B2-Sequence." << endl
                 << endl;
        }
    }
    return 0;
}