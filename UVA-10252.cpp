#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string x, y;

int main()
{
    while (getline(cin, x))
    {
        getline(cin, y);

        if (x == " " || y == " ")
        {
            cout << "\n";
            continue; // 避免在空輸入時進行後續處理
        }

        // 分別統計 x 和 y 中各字母的頻率
        vector<int> freqX(26, 0);
        vector<int> freqY(26, 0);

        for (char ch : x)
        {
            if (islower(ch)) // 確保只處理小寫字母
                freqX[ch - 'a']++;
        }

        for (char ch : y)
        {
            if (islower(ch))
                freqY[ch - 'a']++;
        }

        // 找出共同字母，數量取最小值並輸出
        for (int i = 0; i < 26; ++i)
        {
            for (int j = 0; j < min(freqX[i], freqY[i]); ++j) // 這段內層迴圈負責處理當前字母 i 的輸出次數。
            {
                cout << char(i + 'a');
            }
        }

        cout << "\n"; // 在每次迭代結束後加換行
    }

    return 0;
}
