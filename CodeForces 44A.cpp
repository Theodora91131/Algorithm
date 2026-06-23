#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    set<string>uniqueSet;
    int n;
    cin >> n;
    cin.ignore(); // Ignore the newline character after reading n
    while(n--){
        string line;
        getline(cin,line);
        uniqueSet.insert(line);
    }
    cout << uniqueSet.size() << endl;

    return 0;
}
