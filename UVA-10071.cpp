#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
    int v = 0, t = 0;
    vector<pair<int, int>> a;
    while (cin >> v >> t)
    {
        a.emplace_back(v, t);                                 // push_back接受單一輸入 要用的話要make_pair(v,t)或{v,t}
        cout << 2 * a.back().first * a.back().second << endl; // back 用來找出最後插入的元素
    }

    return 0;
}