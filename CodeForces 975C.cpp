#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q;
    cin >> n >> q;
    vector<long long> strengths(n);
    vector<long long>attack(q);
    vector<long long>totalStrengths(n);//前綴合 打死前面i幾個戰士需要的需求總傷害
    for(int i=0; i<n; i++){
        cin >> strengths[i];
    }
    for(int i=0; i<q; i++){
        cin >> attack[i];
    }
    for(int i=0; i<totalStrengths.size(); i++){
        if(i==0){
            totalStrengths[i] = strengths[i];
        }else{
            totalStrengths[i] = totalStrengths[i-1]+strengths[i];
        }
    }
    long long damage=0;
    long long total = totalStrengths[n - 1];//判斷是否死光了
    for(int i=0;i<q;i++){
        damage += attack[i];//累積傷害
        if(damage >= total){ //這分鐘結束後還站著多少人(全部死光了的情況)
            damage = 0;
            cout << n << endl;
        }else{
            int dead = upper_bound(totalStrengths.begin(),totalStrengths.end(),damage)-totalStrengths.begin(); //打死了幾個人
            cout << n - dead << endl; //活者的人數=總人數-死的人數
        }//it - totalStrengths.begin() 是因為upper_bound()回傳的是一個iterator，減去begin()才會得到index位置
    }//upper_bound()二分搜尋法，找出第一個大於damage的元素位置，這個位置就是打死的人數

}