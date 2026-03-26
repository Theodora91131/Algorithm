#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<char,char> mp;
    string s1 = "BFPV";
    string s2 = "CGJKQSXZ";
    string s3 = "DT";
    string s4 = "L";
    string s5 = "MN";
    string s6 = "R";

    for(char c : s1) mp[c] = '1';
    for(char c : s2) mp[c] = '2';
    for(char c : s3) mp[c] = '3';
    for(char c : s4) mp[c] = '4';
    for(char c : s5) mp[c] = '5';
    for(char c : s6) mp[c] = '6';

    string s;
    
    while(cin >> s) {
        char last = '0'; // 初始化為'0'，不是空格
        string code = "";
        for(char c : s) {
            if(mp.count(c)) {
                char digit = mp[c];
                if(digit != last) {
                    code += digit;
                    last = digit;
                }
            } else {
                // 遇到不可編碼字母，不改變 last
                last = '0';
            }
        }
        cout << code << endl;
    }
    return 0;
}
