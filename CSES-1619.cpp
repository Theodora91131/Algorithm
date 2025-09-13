#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<utility>
using namespace std;
bool cmp(const pair<int,int> &a, const pair<int,int>& b){
    if(a.first == b.first){
      return  a.second > b.second;
    }
    return a.first < b.first; 
}
int main(){
    int a, cnt=0;
    cin >> a;
    vector<pair<int,int>>event(2*a);
    
    for(int i =0; i < a; i++){
        int b, c;
        cin >> b >> c;
        event.push_back({b,1});
        event.push_back({c,-1});
    }
   
    sort(event.begin(),event.end(),cmp);
    int cust=0;
    for(int i=0; i < event.size(); i++){
        cust += event[i].second;
        cnt = max(cnt,cust);
    }
    cout << cnt << endl;
    return 0;
}