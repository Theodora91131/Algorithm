# include<iostream>  
# include<bits/stdc++.h>  
#include <vector>  
using namespace std;  
int cnt = 0, cntM = 0;  
int fibon(int n){     
    if((n == 1) || (n == 0)){  
        cnt++;  
        return n;  
    }  
    cnt++;    
    return fibon(n-1)+fibon(n-2);  
      
}  
int fibonM(int n, vector<int>&memory){      
    if((n == 1) || (n == 0)){  
        cntM++;  
        return n;  
    }  
    if (memory[n] != -1){  
        return memory[n];  
    }  
    cntM++;  
    memory[n] = fibon(n-1)+fibon(n-2);    
    return memory[n];  
      
}  
int main(){  
    int n;  
    cin >> n;  
  cout << "沒使用memory"<<endl;  
  for (int i = 0; i < n; ++i) {  
        cout << fibon(i) << " ";  
    }  
    cout << cnt <<"次"<< endl;  
    cout << endl;  
    cout << "使用memory"<<endl;  
    vector<int>memory (n,-1);  
    for (int i = 0; i < n; ++i) {  
        cout << fibonM(i,memory) << " ";  
    }     
    
     cout << cntM <<"次"<< endl;      
     cout << endl;   
      
    return 0;  
}  
