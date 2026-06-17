#include<bits/stdc++.h>
using namespace std;    

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<long long> array(n);
    vector<long long>result(k);
    for(int i = 0; i < n; i++){
        cin >> array[i];
    }
    sort(array.begin(), array.end());
    long long sub=0,cur=0;
    int printed=0;
    for(int i=0; i<n && printed < k; i++){ 
        cur= array[i]-sub;
        if(cur>0){
            sub += cur;
            cout << cur << endl;
            printed++;
        }
    }
    while(printed < k){
        cout << 0 << endl;
        printed++;
    }
    return 0;
}