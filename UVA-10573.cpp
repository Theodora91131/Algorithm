#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const double PI = acos(-1);
    int n;
    cin >> n;
    cin.ignore(); // 吃掉第一行換行

    while(n--){
        string s;
       	getline(cin,s);
        istringstream ss(s);
        double a, b;
        if(ss >> a){
            if(ss >> b){
                cout << fixed << setprecision(4) << 2.0 * PI * a * b << "\n";
            } else {
                //用t^2=(r1+r2)^2-(r1-r2)^2  ; t^2=4*r1*r2
                //本題(t/2)^2=(r1+r2)^2-(r1-r2)^2  ; t^2=16*r1*r2
                cout << fixed << setprecision(4) << PI * a * a / 8.0 << "\n";
            }
        } else {
            cout << "Impossible." << "\n";
        }
    }

    return 0;
}
