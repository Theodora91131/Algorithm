#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
    double s, n, p, i;
    cin >> s;
    for (int j = 0; j < s; ++j)
    {
        cin >> n >> p >> i;
        if (p < 0.00001)
        {
            cout << "0.0000" << endl;
        }
        else
        {
            cout << fixed << setprecision(4) << (pow(1 - p, i - 1) * p) / (1 - pow(1 - p, n)) << endl;
        }
    }

    return 0;
}
// 直到第i人才擲出特定點數機率為(1-p)^(i-1)*p，若是第二輪才贏得遊戲，獲得機率為(1-p)^(n+i-1)*p，第m輪獲得機率為(1-p)^(mn+i-1)*p
// 第i個人獲勝機率是以上機率的總和，[(i-p)^(i-1)*p]*(1/(1-(1-p)^n))
