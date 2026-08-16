#include<bits/stdc++.h>
using namespace std;

//int led[10]={6,2,5,5,4,5,6,3,7,6};
int main(){
    int n;
    cin >> n;
    int temp = n, ans=0;
    if(temp % 3 == 0){
        while(temp > 0){
            ans += 7;
            temp -= 3;
        }
    }else if(temp % 3 == 2){
        ans += 1;
        temp -= 2;
        while(temp > 0){
            ans += 7;
            temp -= 3;     
        }    
    }else if(temp % 3 == 1){
        ans += 4;
        temp -= 4;
        while(temp > 0){
            ans += 7;
            temp -= 3;     
        }    
    }
    cout << ans << '\n';
    return 0;
}

