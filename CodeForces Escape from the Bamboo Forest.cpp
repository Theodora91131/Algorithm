#include<bits/stdc++.h>
using namespace std;

bool opposite(char a, char b) {
    return (a == 'R' && b == 'L') || (a == 'L' && b == 'R') ||
           (a == 'U' && b == 'D') || (a == 'D' && b == 'U');
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n; //迷宮大小
    string s;// example: RLLRUD 牆洞的方向
    cin >> n >> s;
    int k = (n+1)/4;
    long long ans = 1;
    for(int i = 1; i<k; i++){
        char prev = s[i-1]; //內層牆的洞方向
        char cur = s[i]; //外層牆的洞方向
        long long R = 2LL*i; //兩道牆中間那圈開放區的半徑
        ans +=2;
        if(prev == cur) {
            ans += 0;
        } else if (opposite(prev, cur)) {
            ans += 4*R;
        }else {
            ans += 2*R;
        }
    }
    cout << ans << endl;
    return 0;
}