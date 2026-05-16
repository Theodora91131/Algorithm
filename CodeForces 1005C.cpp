#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    map<int,int>counts;
    for(int i=0;i<n;i++){
        cin>>a[i];
        counts[a[i]]++;
    }
    int removed = 0;
    for(int i=0;i<n;i++){
        bool ok = false;
        for(int d=0;d<=30;d++){
            long long pow2 = 1LL << d;
            long long target = pow2 - a[i];
            if(counts.count(target)){
                if(target == a[i]){
                    if(counts[target]>1){
                        ok = true;
                        break;
                    }
                }else{
                    ok = true;
                    break;
                }
            }
        }
        if(!ok){
            removed++;
        }
    }
    cout << removed << endl;
    return 0;
}