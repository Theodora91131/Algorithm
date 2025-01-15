# include <iostream>
# include <vector>
# include <string>
# include <iomanip>
# include <cmath>

using namespace std;

int main(){
	int x;
	cin >> x;
	while(x--){
		int s;
		float total=0, average=0, cnt=0;
		cin >> s;
		vector <int> score(s);
		for(int i = 0; i < s; i++){
			cin >> score[i];
			total += score[i];
		}
		total /= s;
		for(int i =0; i < s; i++){
			if (score[i] > total){
				cnt ++;
			}
		}
		cnt = cnt / s * 100;
		cout << fixed << setprecision(3) << cnt <<"%"<< endl;
		
	}
	return 0;
}
