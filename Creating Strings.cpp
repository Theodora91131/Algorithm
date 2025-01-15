# include <iostream>
# include <algorithm>
using namespace std;
int main(){
	vector<string> a;
	string str;
	getline(cin, str);
	if(str.size()>=1 &&str.size()<=8 ){
		sort(str.begin(),str.end());
		a.push_back(str);
		int n=1;
		while(next_permutation(str.begin(),str.end())){
			n++;
			string permuatation;
			for(int i = 0; i < str.length(); i++){
				permuatation += str[i];	
			}
			a.push_back(permuatation);	
		}
		cout << n << endl;
		for(string i:a){
			cout << i << endl;
		}	
	}		
	return 0;
} 
