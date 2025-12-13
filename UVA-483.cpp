#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>
using namespace std;
int main(){
    string s;
    while (getline(cin,s))
    {
        string w;
        stringstream ss(s);
        bool first = 0;
        while(ss >> w){
            reverse(w.begin(),w.end());
            if(first){ cout << " ";}
            cout<< w;
            first = 1;
        }
        cout << endl;
    }

    return 0;
}