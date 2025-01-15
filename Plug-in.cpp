# include <iostream>
# include <cctype>
# include <string>
# include <vector>
# include <stack>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	stack<char> Stk;
	string str;
	cin >> str;
	
	for (int i=0; i<str.size(); i++){
		if(!Stk.empty() && Stk.top()==str[i]){
			Stk.pop();
		}else{
			Stk.emplace(str[i]);
		}
	}	
	vector<int>vec;
	while(!Stk.empty()){
		vec.push_back(Stk.top());
		Stk.pop();
	}
	for(int i=vec.size()-1;i>=0;i--){
		cout << (char)vec[i];
	}
	return 0;
}
