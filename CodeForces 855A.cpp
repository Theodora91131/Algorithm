#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    set<string> v;
    while(n--)
    {
        string s;
        cin>>s;
        if(v.find(s)==v.end())
        {
            cout<<"NO"<<endl;
            v.insert(s);
        }
        else
        {
            cout<<"YES"<<endl;
        }
    }
    return 0;
}