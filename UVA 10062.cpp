# include <iostream>
# include <string>
# include <vector>
# include <algorithm>

using namespace std;
bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second == b.second) {
        return a.first > b.first;
    }
    return a.second < b.second;
}

int main(){
	bool flag = false;
	string str;
	while(getline(cin,str)){
		vector<int> frequence(129,0);
		vector<pair<int,int>> ans ;
		if (flag) {
            cout << endl;
        }else{
        	flag = true;
		}
		for (char a : str){
			frequence[(int)a]++;
		} 
		for(int i = 1; i < frequence.size(); i++){
			if (frequence[i] > 0){
				ans.push_back(make_pair(i,frequence[i]));
			}
		}
		sort(ans.begin(),ans.end(),compare);
		 
		for (const auto& a : ans) {
            cout << a.first << " " << a.second << endl;
        }
	}	
	return 0;
}
