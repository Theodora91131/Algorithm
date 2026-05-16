#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1000005;
int cnt[MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> a(n);
    long long total_sum = 0;
    for(int i=0; i<n;i++){
        cin >> a[i];
        total_sum += a[i];
        cnt[a[i]]++; // 统计每个数的出现次数
    }
    vector<int> ans;
    for(int i=0;i<n;i++){
        cnt[a[i]]--; // 暂时移除当前元素，计算剩余元素的和
        long long remaining_sum = total_sum - a[i];
        // 检查剩余元素的和是否是2的幂次方
        if(remaining_sum %2 == 0){
            long long target = remaining_sum/2;

            //確保target 沒有超出題目範圍 且在剩下的數字中確實存在
            if(target < MAXN && cnt[target] > 0){
                ans.push_back(i+1); // 題目要求從1開始的索引
            }
        }
        cnt[a[i]]++; // 把當前元素加回去

    }
    cout << ans.size() << endl;
    for(int idx : ans){
        cout << idx << " ";
    }
    cout << endl;
    return 0;
}