#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int cnt = 0;
    for(int i=0;i<n;i++){
        int temp = a[i];
        while(k < ceil(double(temp)/2)){
            temp = ceil(double(temp)/2);
            cnt++;
        }
        k = max(k, a[i]);
    }
    cout << cnt << endl;
}