#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,c;
    cin >> n;
    vector<int> st;
    for(int i = 0; i < n; i++){
        cin >> c;
        int p = c % 2;
        if(!st.empty() && st.back() == p){
            st.pop_back();
        }else {            
            st.push_back(p);
        }
    }
     if (st.size() <= 1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}