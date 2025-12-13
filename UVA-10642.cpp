#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;
long long getIndex(long long x,long long y){
    return (x+y)*(x+y+1)*0.5+x;
} 
int main(){
    int x;
    cin >> x;
    for(int i=1; i<=x; i++){
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << "Case "<< i <<":"<<" "<< getIndex(x2,y2)-getIndex(x1,y1)<<endl;
    }
    return 0;
}
