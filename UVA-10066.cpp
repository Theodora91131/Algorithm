#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m,ans=0,cnt=0;
    while(cin >> n >> m && (n != 0 && m != 0)){
        vector<int> x(n), y(m);
        vector<vector<int>> common(n+1, vector<int>(m+1));
        cnt++;
        for(int i = 0; i < n; i++){
            cin >> x[i];
        }
        for(int i = 0; i < m; i++){
            cin >> y[i];
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(x[i-1]==y[j-1]){
                        common[i][j] = common[i-1][j-1]+1;
                        ans++;
                }else if(x[i-1]!=y[j-1]){
                        common[i][j] = max(common[i-1][j],common[i][j-1]);
                }
            }
        }
        cout << "Twin Towers #" << cnt << endl;
        cout << "Number of Tiles : " << common[n][m] << endl<<endl;
    }
    return 0;
}