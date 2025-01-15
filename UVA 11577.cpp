# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
using namespace std;
int main(){
	int x;
	string str;
	cin >> x;
//	vector<int> frequence(27, 0);
//	vector<char> ans;
	getline(cin,str);
	while (x--){
		vector<int> frequence(27, 0);
		vector<char> ans(0);
		getline(cin,str);
		for( char a: str){
			if (isalpha(a)){
				frequence[tolower(a)-(int)'a'+1]++;    //ª`·N tolowerÂà¦¨ASCII  
			}		
		}	
		int topChar = *max_element(frequence.begin(),frequence.end());
		for(int i=1; i< frequence.size(); i++){
			if(frequence[i] == topChar){
				ans.push_back('a' + i-1); 
			}
		}
		for(char i: ans){
			cout << i ;
		}
		cout << endl;
	}
	
	return 0;
	
}
