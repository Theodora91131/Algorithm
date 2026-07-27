#include<iostream>
#include<vector>
#include<algorithm>
#include<array>
using namespace std;
struct Platform{
    int left, right, height;
};
bool comp(const Platform &a, const Platform &b){
    return a.height < b.height;
}
int main(){
    int t,n;
    cin >> t;
    while(t--){
        int X, Y, Max;
        cin >> n;
        vector<Platform> p(n);
        cin >> X >> Y >> Max;
       
        for(int i=0;i<n;i++){
            cin >> p[i].left >> p[i].right >> p[i].height;
        }
        sort(p.begin(),p.end(),comp);
        const int INF = 1e9;
        vector<array<int, 2>> dp(n, {INF, INF});//dp[i][0] dp[i][1] 從第i個'平台左端出發到地面的最短時間
        for(int i=0;i<n;i++){//由低到高處理每個平台 :左端往下掉會掉到哪個平台? 右端往下調會掉到哪個平台?
            int left = p[i].left, right = p[i].right, height = p[i].height;
            int belowLeft = -1;
            for(int j=i-1; j>=0;j--){ //平台已經由低到高排好了 從i-1往下找第一個符合的就是左端正下方
                if(p[j].left <= left && left <= p[j].right){
                    belowLeft = j;
                    break;
                }
            }
            if(belowLeft == -1){ //如果左端下方沒有平台：因為直接掉到地面，下落距離就是 height。
                if(height <= Max){
                    dp[i][0] = height;
                }
            }else{
                int drop = height - p[belowLeft].height;
                if(drop <= Max){
                    dp[i][0]=drop+min(left - p[belowLeft].left + dp[belowLeft][0],p[belowLeft].right - left + dp[belowLeft][1]);
                }
            }
            int belowRight = -1;
            for(int j=i-1; j>=0;j--){
                if(p[j].left <= right && right <= p[j].right){
                    belowRight = j;
                    break;
                }
            }
            if(belowRight == -1){
                if(height <= Max){
                    dp[i][1]=height;
                }
            }else{
                int drop = height - p[belowRight].height;
                if(drop <= Max){
                    dp[i][1]= drop + min(right - p[belowRight].left + dp[belowRight][0],p[belowRight].right - right + dp[belowRight][1]);
                }
            }
        }
        int first = -1; //處理起點
        for(int i= n-1; i>=0; i--){
            if(p[i].left <= X&&X<=p[i].right){
                first = i;
                break;
            }
        }
        if(first == -1){
            cout << Y << endl;
        }else{
            int drop = Y - p[first].height;
            int ans = drop + min(X-p[first].left + dp[first][0],p[first].right-X+dp[first][1]);
            cout << ans << endl;
        }
    }
    return 0;
}