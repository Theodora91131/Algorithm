# include <iostream>

using namespace std;
int main(){
	unsigned int x, y;
	while(cin >> x >> y){
		unsigned int ans;
		ans = x ^ y;
		cout << ans << endl;
	}
	return 0;
} 
