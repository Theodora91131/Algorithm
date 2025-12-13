#include<iostream>
#include<vector>
#include<algorithm>
#include <limits>
#include<set>
using namespace std;
int main(){

    int n;
    cin >> n;
    vector<int> a(n);
    multiset<int> s;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        auto it = s.upper_bound(a[i]); //return 第一個「嚴格大於 x」的元素
        if(it == s.end()){
            s.insert(a[i]);
        }else{
            s.erase(it);
            s.insert(a[i]);
        }
    }
    cout << s.size() << endl;
     
    return 0;
}