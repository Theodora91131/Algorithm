#include <iostream>
#include <algorithm>

using namespace std;
int main(){
	int nball,dep,pos,r;
	cin >> r && r!= -1 ;
	while(r --){
		cin >> dep >> nball;
		pos = 1;
		for(int j=1;j<dep;j++){
			if ((nball%2)==0){
				pos=2*pos+1;  
				nball = nball / 2;
				
			}else{
				pos=2*pos;  
				nball = (nball+1) / 2; 
			}
			
		}
		cout << pos<<endl;	
	}
		
	} 
