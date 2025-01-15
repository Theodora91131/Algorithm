#include <iostream>
#include <vector>
# include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    vector<vector<int>>c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    for(int i=0; i<a.size();i++){
    	for(int j=0; j<b.size();j++){
    		c[i].push_back(a[i]&b[j]);
		}
	}
    for (int i=0; i<=(1<<9); i++){
    	for (int j=0; j<n; j++){
    		bool flag = 0;
    		for(int k=0; k<m; k++){
    			if((i|c[j][k])==i){
    				break;
				}else if(k==m-1){
					flag = 1;
					break;
				}	 	
			}
			if (flag){
				break;
			}else if(j == n-1){
				cout<<i<<endl;
				return 0;
			}
		
		}
	}
	
    
    return 0;
}

