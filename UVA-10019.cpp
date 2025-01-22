#include <iostream>

using namespace std;
int main()
{
    int n, temp1, temp2, t;
    int d_to_b_one;
    int h_to_b_one;
    cin >> t;
    while (t--)
    {
        cin >> n;
        d_to_b_one = 0;
        h_to_b_one = 0;
        temp1 = n;
        temp2 = n;

        while (temp1)
        {
            if (temp1 & 1) // 十轉二進位
            {
                d_to_b_one++;
            }
            temp1 >>= 1;
        }

        while (temp2)
        {
            int q = temp2 % 10;
            temp2 /= 10;
            while (q)
            {
                if (q & 1) // 十六轉二進位
                {
                    h_to_b_one++;
                }
                q >>= 1;
            }
        }
        cout << d_to_b_one << " " << h_to_b_one << endl;
    }

    return 0;
}