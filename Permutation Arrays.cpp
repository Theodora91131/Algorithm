# include <iostream>
# include <vector>
# include <algorithm>
# include <sstream>
# include <iomanip>
# include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> index;
        vector<string> numbers;
        vector<pair<int, string>> val;
        string ind,tmp,num;
        getline(cin, ind);
		getline(cin, ind);
		getline(cin, num);
		stringstream in(ind);
		stringstream nu(num);
		int tmp_index;
		while(in >> tmp){
			tmp_index = stoi(tmp);
			index.push_back(tmp_index);
		}
		while(nu >> tmp){
			numbers.push_back(tmp);
		
		}
        for(int i=0; i<index.size(); i++){
        	val.push_back(make_pair(index[i],numbers[i]));
		}
        sort(val.begin(), val.end());
        for (const auto& a : val) {
            cout << a.second << endl;
        }
        if (t > 0) {
            cout << endl;
        }
    }
    return 0;
}

