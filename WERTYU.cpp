# include <iostream>
# include <unordered_map>
using namespace std;
int main(){
	unordered_map<char,char> query ={
		{'1', '`'}, {'2', '1'}, {'3', '2'}, {'4', '3'}, {'5', '4'},
        {'6', '5'}, {'7', '6'}, {'8', '7'}, {'9', '8'}, {'0', '9'},
        {'-', '0'}, {'=', '-'}, {'W', 'Q'}, {'E', 'W'}, {'R', 'E'},
        {'T', 'R'}, {'Y', 'T'}, {'U', 'Y'}, {'I', 'U'}, {'O', 'I'},
        {'P', 'O'}, {'[', 'P'}, {']', '['}, {'\\', ']'}, {'S', 'A'},
        {'D', 'S'}, {'F', 'D'}, {'G', 'F'}, {'H', 'G'}, {'J', 'H'},
        {'K', 'J'}, {'L', 'K'}, {';', 'L'}, {'\'', ';'}, {'X', 'Z'},
        {'C', 'X'}, {'V', 'C'}, {'B', 'V'}, {'N', 'B'}, {'M', 'N'},
        {',', 'M'}, {'.', ','}, {'/', '.'}
	};
	string str;
	while(getline(cin,str)){
		for(char c : str){
			if (c == ' '){
				cout << ' ';
			}else {
                auto it = query.find(c);
                if (it != query.end()) { //看find(c)有無找到,沒找到傳回end() 
                    char ans = it->second;
                    std::cout << ans;
            	}
			}
			
		}
		cout << endl;
	}
	
	return 0;
} 
