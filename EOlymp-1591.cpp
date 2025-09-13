#include<vector>
#include<algorithm>
#include<cmath>
#include<utility>
#include<iostream>
using namespace std;
struct Job{
    int id;
    int T;
    int S;
};
bool cmp(const Job &a, const Job &b){
    long long left = 1LL*a.T*b.S;
    long long right = 1LL*b.T*a.S;   //Greedy 排序，核心判斷來自「兩兩比較」推導出來的交換法則。
    if(left == right){
        return a.id < b.id; //字典序小的先
    }
    return left < right;

}
int main(){
    int a;
    while(cin>>a){
        vector<Job>jobs(a);
        for(int i=0; i<a; i++){
            int t, s;
            cin >> t >> s;
            jobs[i]= {i+1,t,s};
        }
        
        sort(jobs.begin(),jobs.end(),cmp);
        for (int i = 0; i < a; i++) {
            cout << jobs[i].id;
            if (i != a-1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}