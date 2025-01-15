#include <iostream>
#include <string>
#include <map>

using namespace std;
int main()
{
    string s;
    map<string, long long> m;     // 儲存詞語與數值的映射
    map<long long, string> rev_m; // 儲存數值與詞語的反向映射
    while (cin >> s)
    {
        if (s == "clear")
        {
            m.clear();
            rev_m.clear();
            continue;
        }
        if (s == "def")
        {
            string x;
            long long y;
            cin >> x >> y;
            if (m.count(x) && rev_m.count(m[x]))
            {
                rev_m.erase(m[x]); // 如果詞語已經有舊定義，刪除舊數值的反向映射
            }
            m[x] = y;     // 更新詞語到數值的映射
            rev_m[y] = x; // 更新數值到詞語的映射
        }
        else
        {
            int stat = 0; // 運算符的狀態：0 表示 "+"，1 表示 "-"
            /* + 0  -1 */
            long long ans = 0;
            int impos = 0; // 標誌是否出現未定義詞語的情況
            while (cin >> s)
            {
                cout << s << ' ';
                if (s == "=") // 遇到 "=" 表示計算結束
                {
                    break;
                }
                if (impos) // 如果有未定義詞語，直接跳過計算
                {
                    continue;
                }
                if (s != "+" && s != "-") // 遇到詞語
                {
                    if (!m.count(s)) // 詞語未定義
                    {
                        impos = 1;
                        continue;
                    }
                    if (stat == 0) //"+" 操作
                    {
                        ans += m[s];
                    }
                    else
                    {
                        ans -= m[s]; // "-" 操作
                    }
                }
                else if (s == "+")
                {
                    stat = 0; // 設定下一步為 "+" 操作
                }
                else if (s == "-")
                {
                    stat = 1; // 設定下一步為 "-" 操作
                }
            }
            if (rev_m.count(ans) && impos == 0) // 輸出結果
            {
                cout << rev_m[ans] << endl; // 如果結果有對應的詞語，輸出詞語
            }
            else
            {
                cout << "unknown" << endl; // 無對應詞語或有未定義詞語
            }
        }
    }
    return 0;
}