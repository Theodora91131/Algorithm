#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int a, b = 0;
vector<int> v1,v2;

int main(){
    cin >> a;
    for(int i = 1; i <= a; i++){
        cin >> b;
        v1.resize(b);
        v2.resize(b);
        for(int k = 0; k < b; k++){
            cin >> v1[k];
        }
        for(int m = 0; m < b; m++){
            cin >> v2[m];
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end(),greater<int>());
        long long product = 0;
        for(int j = 0; j < v1.size(); j++){
            product += (long long)v1[j]*v2[j];
        }
        cout << "Case #" << i << ": " << product << endl;
    }

    return 0;
}