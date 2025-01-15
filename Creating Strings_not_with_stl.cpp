# include <iostream>
# include <algorithm>
using namespace std;
bool cmp (string &a, string &b){
	return a + b < b + a;
}
int main(){
	vector<string> ss;
	string str;
	getline(cin, str);
	if(str.size()>=1 &&str.size()<=8 ){
		sort(str.begin(),str.end(),cmp);
		ss.push_back(str);		
	}	
	for(string i:ss){
		cout << i << endl;
	}	
	return 0;
} 
