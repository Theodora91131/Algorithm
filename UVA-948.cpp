#include <iostream>
#include <vector>

using namespace std;
int main()
{
    vector<int> fibona;
    int n;
    cin >> n;
    fibona.push_back(1);
    fibona.push_back(2);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        cout << a << " = ";
        while (fibona[fibona.size() - 1] < a) // 使用迴圈不斷生成新的斐波那契數，直到序列中的最大數字大於等於 a
        {
            int fib = fibona[fibona.size() - 1] + fibona[fibona.size() - 2];
            fibona.push_back(fib);
        }
        bool preone = 0;
        for (int j = fibona.size() - 1; j >= 0; j--) // 使用一個逆向迴圈從最大到最小的斐波那契數檢查是否可以減去該數字。
        {
            if (fibona[j] <= a)
            {
                a -= fibona[j]; // 如果可以減去，輸出 1 並從 a 中扣除該數
                cout << "1";
                preone = 1;
            }
            else if (preone) // 定義 preone 來記錄前一個輸出的數字是否為 1
            {
                cout << "0"; // 如果之前已經輸出了 1 且不能減去當前斐波那契數，則輸出 0
            }
        }
        cout << " (fib)" << endl;
    }
}