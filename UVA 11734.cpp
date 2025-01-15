# include <iostream>
# include <string>
#include <cstring>
using namespace std;
int main(){
	int x;
	string blank, team, judge;
	cin >> x;
	getline(cin,team);
	for (int i=1; i<=x; i++){
		getline(cin,team);
		getline(cin,judge);
		string noblank ="";
		for (char a: team){
			if(a !=' '){   //把不是空格的字加進去  
				noblank += a;
			}
		}
		if(team == judge){
			cout<< "Case" <<" "<< i << ":"<<" "<<"Yes"<<endl;
		}else if(noblank == judge){
			cout<< "Case" <<" "<< i << ":"<<" "<<"Output Format Error"<<endl;
		}else{
			cout<< "Case" <<" "<< i << ":"<<" "<<"Wrong Answer"<<endl;
		}	
	}
	return 0;
}
