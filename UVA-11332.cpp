#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <vector>
using namespace std;

int cnt(string num)
{
    int sum = 0;
    for (int i = 0; i < num.length(); i++)
    {
        sum += (int)num[i] - '0'; // 將字元轉換為數字並加到 sum 因為 '0' 的 ASCII 值是 48。
    }
    if (sum > 9)
    {
        return cnt(to_string(sum));
    }
    return sum;
}
int main()
{
    string num;
    while (cin >> num && num != "0")
    {
        if (num.length() > 1)
        {
            cout << cnt(num) << endl;
        }
        else
        {
            cout << num << endl;
        }
    }

    return 0;
}