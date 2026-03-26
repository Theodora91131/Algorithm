#include<bits/stdc++.h>

using namespace std;

int gcd(int p, int q) {
    if(q == 0){
        return p;
    } 
    return gcd(q,p % q);
}

int lcm(int p, int q) {
    return p / gcd(p,q)*q;
}

int getTotalx(vector<int> a, vector<int> b){
    int L = a[0]; // count lcm
    for(int i = 1; i < a.size(); i++){
        L = lcm(L, a[i]);
    }

    int G = b[0]; // count gcd
    for(int i = 1; i < b.size(); i++){
        G = gcd(G, b[i]);
    }

    int count = 0; //數 L 的倍數中，有幾個可以整除 G
    for(int i = L; i <= G; i += L){
        if(G % i == 0){
            count++;    
        }
    }
    return count;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int j = 0; j < m; j++){
        cin >> b[j];
    }
    int result = getTotalx(a, b);
    cout << result << endl;
    return 0;
}