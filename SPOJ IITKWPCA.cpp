#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cin.ignore(); // Ignore the newline character after reading n
   
    while(n--){
        set<string> uniqueWords;
        string line;
        getline(cin,line);
   
        string s;
        stringstream ss(line);
      
        while(ss >> s){
            reverse(s.begin(), s.end());
            uniqueWords.insert(s);   
        }
        cout << uniqueWords.size() << endl;
        
    }
    return 0;
    
}