#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<limits>
#include<set>
using namespace std;
int L= numeric_limits<int>::max();
int R= numeric_limits<int>::min();
int main(){
    int K, N;
    cin >> K >> N;
    vector<int> a(N);
    vector<int> b(N);
    set<int> select;
    for(int i = 0; i < N; i++){
        cin >> a[i] >> b[i];
    }

    for(int i = 0; i < N; i++){
            if(a[i]>b[i]){
                swap(a[i],b[i]);
            }
        int start = a[i];
        int end = b[i];
        L = min(a[i],L);
        R = max(b[i],R);
        int len = end - start + 1;
        if (len<=K){
            for(int j = start;j<=end;j++){
                select.insert(j);
            }
        } else {
            int cnt = 0;
            for(int j = start; j <= end; j++){
                if(select.find(j)!=select.end()){
                    cnt++;
                }
            }
            int add = K - cnt;
            for(int j = end;j>=start;j--){
                if(select.find(j)==select.end() && add>0){
                        select.insert(j);
                        add--;
                }
            }
            
                  
        }  
    }
    cout << select.size() << endl;
    for(auto it = select.begin(); it!=select.end(); it++){
            cout << *it << endl;
    }
    return 0;
}