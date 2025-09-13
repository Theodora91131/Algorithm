#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<utility>

using namespace std;
bool cmp(const pair<int,int>& d, const pair<int,int>& e){
     if(d.first == e.first){
      return  d.second > e.second;
    }
    return d.first < e.first; 
}
int main(){
    int a;
    cin >> a;
    int b, c;
    vector<pair<int,int>>v;
    while(cin >> b >> c){
        if(b == 0 && c == 0){
            break;
        }
        v.push_back({b,c}); 
    }
    sort(v.begin(),v.end(),cmp);
    int reach = 0, i = 0, n = v.size();
    vector<pair<int,int>> ans;
    while (reach < a)
    {
        int bestReach = reach;
        pair<int,int> bestSeg = {0,0};
        while(i<n && v[i].first <= reach){
            if(v[i].second > bestReach){
                bestReach = v[i].second;
                bestSeg  = v[i];
            }
            i++;
        }
        if(bestReach == reach){
            cout << "No solution\n";
            return 0;
        }
        ans.push_back(bestSeg);
        reach = bestReach;

    }
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i].first << " " << ans[i].second << "\n";
    } 
    
    return 0;
}