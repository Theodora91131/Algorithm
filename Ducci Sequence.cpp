# include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	while(n--){
		int m;
		cin >> m;
		vector<int>ori(m);
		map<vector<int>,int> seen; //一維關聯對應 
		for(int i=0; i<m; i++){
			cin >> ori[i];	
		}
		//判斷是否進入loop 
		int cnt = 0;
		bool loop = 0;
		while(cnt <= 1000){
			if(seen.find(ori)!=seen.end()){ //ORI如果存在
				if(seen[ori]==cnt){
					cout << "LOOP" <<endl;
					loop = true;
					break;
				}
			}
			seen[ori]=cnt; //當序列首次出現時，我們將它的鍵 ori 加入到 seen 中，並將對應的值設置為當前的步數 cnt 
			//加入ducci
			vector<int>ducci(m);
			bool allZero = 1;
			int a;
			for(int i=0; i<m; i++){
				ducci[i]=abs(ori[i]-ori[(i+1)%m]);
				cout << ducci[i] << endl;
				if(ducci[i] != 0){
					allZero = 0;
				}
//				 a = abs(ori[i]-ori[(i+1)%m]);
//				cout << a <<endl;
//				ducci.push_back(a);
//				if(a != 0){
//					allZero = 0;
//				}	
			}
			if(allZero){
				cout << "ZERO" <<endl;
				break;
			} 
			ori = ducci;
			cnt++;
		}
		if(!loop && cnt > 1000){
			cout << "LOOP" << endl;
		}	
	}
		return 0;
}
	
	

