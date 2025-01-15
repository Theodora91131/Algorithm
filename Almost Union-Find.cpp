#include<iostream>
#include<algorithm>
using namespace std;
int f[400005],sz[400005],id[400005];
long long sum[400005];
int newid;
void init(){
	for(int i = 0; i <= 100001; i++){
		f[i] = i;
		sz[i] = 1;
		sum[i] = i;
		id[i] = i;
	}
}
int find(int x){
	if(f[x] == x) return x;
	return find(f[x]);
}
void merge(int x, int y){
	x = find(x), y = find(y);
	if(x == y) return;
	if(sz[x] < sz[y]) swap(x,y);
	sz[x] += sz[y];
	sum[x] += sum[y];
	f[y] = x;
}
void remove(int x){
	int root = find(id[x]);
	sz[root]--;
	sum[root] -= x;
}
void add(int x){
	f[id[x]] = id[x] = newid++;
	sz[id[x]] = 1;
	sum[id[x]] = x;
}
int main(){
	int n, m;
	while(cin >> n >> m){
		init();
		newid = n + 1;
		while(m--){
			int que, p, q;
			cin >> que;
			if(que == 1){
				cin >> p >> q;
				if(find(id[p]) != find(id[q])){
					merge(id[p],id[q]);
				}
			}
			if(que == 2){
				cin >> p >> q;
				if(find(id[p]) != find(id[q])){
					remove(p);
					add(p);
					merge(id[p],id[q]);
				}
			}
			if(que == 3){
				cin >> p;
				cout << sz[find(id[p])] << " " << sum[find(id[p])] << endl;
			}
		}	
	}
	
	
	return 0;
}
