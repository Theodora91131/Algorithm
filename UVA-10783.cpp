#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a;
    for (int i = 0; i < a; ++i)
    {
        int sum = 0;
        cin >> b >> c;
        for (int i = b; i <= c; i++)
        {
            if ((i % 2) == 1)
            {
                sum += i;
            }
        }
        cout << "Case " << i + 1 << ": " << sum << endl;
    }

    return 0;
}