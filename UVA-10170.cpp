#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    long long S, D, days = 0;
    while (cin >> S >> D)
    {
        for (int i = 0;; ++i)
        {
            days = (S + (S + i)) * (i + 1) / 2;
            if (days >= D)
            {
                cout << S + i << endl;
                break;
            }
        }
    }

    return 0;
}