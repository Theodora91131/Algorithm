#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Interval{
    int start;
    int end;
    int efficiency;
};
bool cmp(const Interval &a, const Interval &b){
    return a.start < b.start;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,M,R;
    cin >> N >> M >> R;
    vector<Interval> intervals(M);
    for(int i=0;i<M;i++){
        cin >> intervals[i].start >> intervals[i].end >> intervals[i].efficiency;
    }
    sort(intervals.begin(), intervals.end(), cmp);
    vector<long long> dp(M);
    long long ans = 0;
    for(int i=0;i<M;i++){
        dp[i] = intervals[i].efficiency; //區間i自己單獨做
        for(int j=0;j<i;j++){
            if(intervals[j].end+R <= intervals[i].start){ //區間j做完休息R小時 是否來得及過區間i
                dp[i] = max(dp[i],dp[j]+intervals[i].efficiency);
            }
        }
        ans = max(ans,dp[i]);
    }
    cout << ans << endl;
    return 0;
}