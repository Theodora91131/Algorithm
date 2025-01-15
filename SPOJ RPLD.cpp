# include <bits/stdc++.h>
using namespace std;
struct Stud{
	int id;
	int sub;
};
int main(){
	int T;
	cin >> T;
	for(int j=0; j<T; j++){
		int N, R;
		cin >> N >> R;
		map<int,set<int>> rec;
		bool flag = 0;
		for(int i=0; i<R; i++){
			Stud stu;
			cin >> stu.id >> stu.sub;
			
			if(rec.find(stu.id)!=rec.end() &&rec[stu.id].find(stu.sub) != rec[stu.id].end()){
				flag = 1;
			}else{
				rec[stu.id].insert(stu.sub);
			}
		}
		if(flag){
			cout << "Scenario #" << j+1 << ": " << "impossible"<<endl;
		}else {
			cout << "Scenario #" << j+1 << ": " << "possible"<<endl;
		}
		
	}
	return 0;
}
