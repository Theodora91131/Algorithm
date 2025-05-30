#include<iostream>
#include<vector>
#include<sstream>
#include<set>
#include<string>
#include <map>
#include<algorithm>
using namespace std;
int goal;
vector<int> nums;// 不重複的候選數字（遞減）
vector<int> path;// 當前組合
map<int, int>countMap;//記數字最多可用幾次
map<int, int>used;//記目前用的次數
set<string> results;

void dfs(int startIdx, int currentSum) {
    if (currentSum == goal) { //如果湊到正確的sum 把path存起來
        stringstream ss;
        for (int i = 0; i < path.size(); ++i) {
            if (i > 0) ss << "+";
            ss << path[i];
        }
        results.insert(ss.str());
        return;
    }
    for (int i = startIdx; i < nums.size(); ++i) {
        int num = nums[i];
        if (currentSum + num > goal) continue; //超過總和就跳過
        if (used[num] >= countMap[num])continue; // 用超次數也跳過
        path.push_back(num); //選擇：把 num 加入 path
        used[num]++;
        dfs(i, currentSum + num);// i 不加一，因為可以重複選擇相同值（如果還有剩下）
        used[num]--; //回溯：結束後退一步，恢復狀態
        path.pop_back();
    }
}
int main() {
    string line;
    while (getline(cin, line)) {
        stringstream ss(line);
        int n;
        ss >> goal >> n;
        if (n == 0) break;
        nums.clear();
        countMap.clear();
        used.clear();
        path.clear();
        results.clear();

        vector<int> raw(n);
        for (int i = 0; i < n;++i) {
            ss >> raw[i]; //保留原始輸入順序（但之後會排序）
            countMap[raw[i]]++; //統計每個數字出現幾次，用來限制使用次數
        }
        nums = raw; // 移除重複的，保留排序後的數字列表
        sort(nums.begin(), nums.end(), greater<int>());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());  //注意 UNIQUE只會移除連續重複的職 而且也不適清掉 只是把它擺後面 ，然後回傳一個 iterator，指向第一個重複的元素的位置

        dfs(0, 0);
        cout << "Sums of " << goal << ":\n";
        if (results.empty()) {
            cout << "NONE" << endl;
        }
        else {
            vector<string> sorted(results.begin(), results.end());
            sort(sorted.rbegin(), sorted.rend());//反向排序
            for (const string& s : sorted) {
                cout << s << endl;
            }
        }

    }
    return 0;
}