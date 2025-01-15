#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string str;
vector<int> vis;
int n = 0;
vector<string> output; 

void dfs(vector<char>& ans, int index) {
    if (index == str.size()) {
        string current_str;
        for (int i = 0; i < str.size(); i++) {
            current_str += ans[i];
        }
        output.push_back(current_str);
        n++; 
        return;
    }

    for (int i = 0; i < str.size(); i++) {
        if (!vis[i]) {
            if (i > 0 && str[i] == str[i - 1] && !vis[i - 1]) {
                continue;
            }
            ans[index] = str[i];
            vis[i] = 1;
            dfs(ans, index + 1);
            vis[i] = 0; //»¼°jµ²§ô¹ê°õ¦æ 
        }
    }
}

int main() {
    getline(cin, str);
    sort(str.begin(), str.end());

    vector<char> ans(str.size());
    vis.resize(str.size(), 0);

    dfs(ans, 0);

    cout << n << endl;
    for (const string& s : output) {
        cout << s << endl;
    }

    return 0;
}

