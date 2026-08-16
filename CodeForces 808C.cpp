#include<bits/stdc++.h>
using namespace std;
struct Cup{
    int volume;
    int id;
};
bool cmp(Cup a, Cup b){
    return a.volume > b.volume;
}
int main(){
    int n,w;
    while(cin >> n >> w){
        bool flag = false;
        vector<Cup> cups(n);
        vector<int> ansCup(n,0);
        for(int i=0;i<n;i++){
            cin >> cups[i].volume;
            cups[i].id = i;
        }
        sort(cups.begin(),cups.end(),cmp);
        int need=0,extra=w;
        for(int i=0;i<n;i++){ 
            int half = ceil(double(cups[i].volume)/2);
            need += half;
            cups[i].volume -= half;
            ansCup[cups[i].id] += half;
            extra -= half;
            if(need > w){
                flag = true;
                continue;
            }
        }
        while(extra>0 && need <= w){ 
            for(int i=0;i<n;i++){
                int temp = min(extra, cups[i].volume);
                ansCup[cups[i].id] += temp;
                need += temp;
                if(extra >= cups[i].volume){
                    extra -= cups[i].volume;
                }else{
                    extra = 0;
                }  
                 cups[i].volume -= temp;            
            }
        }
        
        if(flag){
            cout << -1 << endl;
        }else{
            for(int i=0;i<n;i++){
                cout << ansCup[i] << " ";
            }
            cout << endl;
        }

    }

    return 0;
}