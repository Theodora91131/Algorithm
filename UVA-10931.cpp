#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n, temp, cnt;
    vector<int> binary;
    while (cin >> n && n != 0)
    {
        cout << "The parity of ";
        temp = n;
        binary.clear();
        cnt = 0;
        while (temp)
        {
            if (temp & 1)
            {
                binary.push_back(1);
                cnt++;
            }
            else if (!(temp & 1))
            {
                binary.push_back(0);
            }

            temp >>= 1;
        }
        reverse(binary.begin(), binary.end());
        for (auto i = 0; i < binary.size(); ++i)
        {
            cout << binary[i];
        }
        cout << " is " << cnt << " (mod 2)." << endl;
    }
    return 0;
}