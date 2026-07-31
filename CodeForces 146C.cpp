#include<bits/stdc++.h>
using namespace std;
int main(){
    string str1,str2;
    int swapCount=0,replaceCount=0,total=0;
    while(cin >> str1 >> str2){
        int c47 = 0, c74 = 0;
        for(int i=0;i<str1.size();i++){
            if(str1[i] =='4'&& str2[i] =='7'){
                c47++;
            }else if(str1[i] =='7'&& str2[i] =='4'){
                c74++;
            }
            swapCount = min(c47, c74); //可以配對的
            replaceCount = abs(c74-c47); //無法配對的
            total = swapCount+replaceCount;

        }
        cout << total << endl;
    }
    return 0;
}