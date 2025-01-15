#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm> //sort
using namespace std;
int n, cnt, s;
string str;
vector<int> frequence(27, 0);
bool cmp(int i, int j)
{
    if (frequence[i] == frequence[j])
    {
        return i < j; // true : i , j; false: j, i
    }
    return frequence[i] > frequence[j]; // true: frequence[i] , frequence[j]; false: frequence[j] , frequence[i]
}
int main()
{
    cin >> n;
    cin.ignore(); // 忽略第一行的換行符，避免 getline 錯過輸入
    while (n--)
    {
        getline(cin, str);
        for (char a : str)
        {
            if (isalpha(a))
            {
                frequence[toupper(a) - (int)'A']++;
            }
        }
    }
    vector<int> indices(26);
    for (int j = 0; j < 26; ++j)
    {
        indices[j] = j;
    }
    sort(indices.begin(), indices.end(), cmp);
    for (int i = 0; i < 26; ++i)
    {
        int index = indices[i];
        if (frequence[index] > 0)
        { // 只輸出出現過的字母
            cout << char('A' + index) << " " << frequence[index] << endl;
        }
    }

    return 0;
}