#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;
bool cmp(const pair<int,int>&a, const pair<int,int>&b){
    return a.second < b.second;
}
int main(){
    int a = 0;
    cin >> a;
    vector<pair<int,int>>v1(a);
    for(int i = 0; i < a; i++){
        int b, c;
        cin >> b >> c;
        v1[i] = make_pair(b,c);
    }
    sort(v1.begin(),v1.end(),cmp);
    int end = 0, cnt = 0;
    for(int i = 0; i < v1.size(); i++){
        if( end <= v1[i].first){
            end = max(end,v1[i].second);
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}