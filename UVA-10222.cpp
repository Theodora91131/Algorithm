#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<char, char> query = {
        {'2', '`'}, {'3', '1'}, {'4', '2'}, {'5', '3'}, {'6', '4'}, {'7', '5'}, {'8', '6'}, {'9', '7'}, {'0', '8'}, {'-', '9'}, {'=', '0'}, {'e', 'q'}, {'r', 'w'}, {'t', 'e'}, {'y', 'r'}, {'u', 't'}, {'i', 'y'}, {'o', 'u'}, {'p', 'i'}, {'[', 'o'}, {']', 'p'}, {'\\', '['}, {'d', 'a'}, {'f', 's'}, {'g', 'd'}, {'h', 'f'}, {'j', 'g'}, {'k', 'h'}, {'l', 'j'}, {';', 'k'}, {'\'', 'l'}, {'c', 'z'}, {'v', 'x'}, {'b', 'c'}, {'n', 'v'}, {'m', 'b'}, {',', 'n'}, {'.', 'm'}, {'/', ','}};

    string str;
    while (getline(cin, str))
    {
        for (char c : str)
        {
            if (c == ' ')
            {
                cout << ' '; // 保留空格
            }
            else
            {
                auto it = query.find(tolower(c));
                if (it != query.end())
                {
                    cout << it->second; // 解碼並輸出
                }
                else
                {
                    cout << c; // 如果沒有對應的映射，保留原字符
                }
            }
        }
        cout << endl; // 每次輸入一行後換行
    }

    return 0;
}
