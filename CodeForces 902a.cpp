#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<utility>
using namespace std;
bool comp(const pair<int,int>& a, const pair<int,int>& b){
    return a.first < b.first; //由小到大
}
int main(){
    bool flag = 0;
    int a, b, reach = 0;
    cin >> a >> b;
    vector<pair<int,int>>v1(a);
    for(int i=0; i< a; i++){
        int x, y;
        cin >> x >> y;
        v1[i]= make_pair(x,y);
    }
    sort(v1.begin(),v1.end(),comp);
    for(int i=0; i<a; i++){
        if(v1[i].first <= reach){
            reach = max(v1[i].second,reach);
        }
    }
    if(reach >= b) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}