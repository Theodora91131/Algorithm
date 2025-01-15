#include <iostream> 
#include <algorithm> 
#include <vector> 
using namespace std; 
struct Items{ 
    int event,value,weight; 
}; 
int main(){ 
 vector<int>weight,id,value;  
 Items pack; 
    int w; 
 cin >> w ; 
   while((cin>> pack.event >>pack.weight >> pack.value)&& pack.event != -1 && pack.weight != -1 && pack.value != -1){      
      id.push_back(pack.event); 
      value.push_back(pack.value); 
       weight.push_back(pack.weight); 
 } 
  int n = id.size(); 
     vector<vector<int>> dp(n+1, vector<int>(w+1, 0)); 
    vector<vector<int>> items(n+1, vector<int>(w+1, 0)); 
 for(int i = 1; i <= n; i++){ 
        for(int j = 1; j <= w; j++){ 
            if(j-weight[i-1] < 0){ 
              dp[i][j]= dp[i-1][j]; 
          }else{ 
             dp[i][j]=max(dp[i-1][j-weight[i-1]] + value[i-1], dp[i-1][j]); 
             if(dp[i-1][j-weight[i-1]] + value[i-1] > dp[i-1][j]){ 
                     items[i][j] = 1; 
                   
                   
               } 
          } 
      } 
  } 
  vector<int> res; 
    int curr_w = w, curr_i = n; 
    while (curr_i > 0) { 
        if (items[curr_i][curr_w] == 1) { 
             
            curr_w -= weight[curr_i-1]; 
            if (id.front()==0){
            	res.push_back(curr_i-1);
			}else{
				res.push_back(curr_i);
			}
            
        } 
        curr_i--; 
    } 
    for (int i = 0; i < res.size(); i++) { 
        cout << res[i] << " "; 
    } 
    cout << endl << dp[n][w] << endl; 
      
   return 0; 
  }  
