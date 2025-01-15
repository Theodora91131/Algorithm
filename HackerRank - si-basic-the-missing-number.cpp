#include <iostream>
using namespace std;
int main()
{
    int a, sum = 0, i;
    for (int i = 1; i < 100; ++i)
    {
        cin >> a;
        sum += a;
    }
    cout << 5050 - sum;
    return 0;
}