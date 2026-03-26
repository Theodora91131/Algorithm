#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    map<int,int>counts;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        counts[a]++;
    }
    vector<pair<int,int>>freq;
    for(auto &[val, count] : counts){
        freq.push_back({count,val});
    }
    int low = 1,high = n, ans_x=1;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(mid == 0){low = 1; continue;}
        long long total = 0;
        for(auto &p:freq){
            total += p.first/mid;
        }
        if(total>=k){
            ans_x = mid;
            low = mid+1;
        } else {
            high = mid-1;
        }
    }
    vector<int>res;
    for(auto &p:freq){
        int times = p.first/ans_x;
        for(int i=0;i<times;i++){
            res.push_back(p.second);
            if(res.size() == k) break;
        }
        if(res.size() == k) break;
    }
    for(int i=0;i<k;i++){
        cout << res[i];
        if(i<k-1) {
            cout << " ";
        }
    }
    return 0;
}