#include<bits/stdc++.h>
using namespace std;
int main(){
    ios:: sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while(cin >> n && n != 0){
        priority_queue<long long,vector<long long>,greater<long long>> min_heap; // 最小heap 底層是完全二元樹
        for(int i=0; i<n; i++){
            long long val;
            cin >> val;
            min_heap.push(val); // 插入tree 中 花 O(log n) 的時間
        }
        long long total_cost = 0;
        while(min_heap.size()>1){ // 樹中還有超過一個節點時繼續合併
            long long first = min_heap.top(); // 取出最小的元素
            min_heap.pop();
            long long second = min_heap.top(); // 取出第二小的元素
            min_heap.pop();
            long long merged_cost = first + second; // 合併兩元素
            total_cost += merged_cost; // 累加合併
            min_heap.push(merged_cost); // 將合併後的元素重新插入heap中
        }
        cout << total_cost << endl; // 輸出總合併成本
        return 0;

    }








}