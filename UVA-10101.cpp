#include<bits/stdc++.h>
using namespace std;
void longNumber(long long n){
    if(n >= 10000000){
            longNumber(n/10000000);
            cout << " kuti";
            n %= 10000000;
        }
        if(n >= 100000){
            cout <<" "<< n/100000 << " lakh";
            n %= 100000;
        }
        if(n >= 1000){
            cout << " " << n/1000 << " hajar";
            n %= 1000;
        }
        if(n >= 100){
            cout << " " << n/100 << " shata";
            n %= 100;
        }
        if(n > 0){
            cout << " " << n;
        }   
}
int main(){
    ios:: sync_with_stdio(false);
    cin.tie(nullptr);
    long long number;
    int cnt = 0;
    while(cin >> number){
        cout << setw(4) << ++cnt << ".";
        if (number == 0) {
            cout << " 0"; // 如果單獨輸入 0，直接印出 " 0"
        }else{
            longNumber(number);
        }
        cout << endl;
    }
    return 0;
}
        
