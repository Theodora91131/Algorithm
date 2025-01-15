#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;
int main()
{
    vector<string> sent;
    string str;
    int max_line = 0;
    while (getline(cin, str))
    {
        sent.push_back(str);
        max_line = max(max_line, static_cast<int>(str.length()));
    }
    for (int col = 0; col < max_line; ++col)
    {
        for (int row = sent.size() - 1; row >= 0; --row)
        {
            if (col < sent[row].length())
            {
                cout << sent[row][col];
            }
            else
            {
                cout << ' ';
            }
        }
        cout << endl;
    }

    return 0;
}