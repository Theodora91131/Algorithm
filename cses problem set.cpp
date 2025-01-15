#include<iostream>
#include<algorithm>
#include<string> 
using namespace std;
int f[100000005], sz[100000005];
char arr[100000005];
int n, m, k, a;
void init(){
	for(int i = 0; i < n * m; i++){
		f[i] = i;
		sz[i] = 1;
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
	f[y] = x;
}
int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> arr[i * m + j];//將二維地圖映射到一維陣列，我們將每一行的字符依次存儲在一維陣列中。在存儲每一行時，每一列的字符在一維陣列中的索引將是該行的偏移量。
			//因此，在存儲地圖中的每一行時，我們將每一列的字符按照順序存儲到一維陣列中，需要將列數 m 考慮在內，通過將 i 乘以地圖的列數 m，然後加上 j，得到在一維陣列 arr 中對應的索引，即 i * m + j。
		}
	}
	init();

	for(int k = 0; k < n * m; k++){
		if(arr[k] == '#'){
			f[k] = 0;
		}
		else if(arr[k] == '.'){
			if(arr[ k + 1] == '.'&&k%m != (m-1)){  //k % m != (m - 1) 檢查的是地圖中的每一行的最後一個字符，
				merge(k, k+1); //以確保在執行 k + 1 操作時不會超出地圖的範圍。
			}					//具體地，k % m 表示 k 在當前行的列索引，(m - 1) 是當前行的最後一列的索引。
			if(arr[k+m] == '.'){ //因此，k % m != (m - 1) 表示 k 不是當前行的最後一個字符，這樣可以確保 k + 1 操作不會跨越到下一行。
				merge(k, k+m);//arr[ k + 1] == '.' 當前字符的右邊一個位置是空地（floor） 是否可向右移 
							//arr[k + m] == '.': 表示在地圖中，當前字符的下面一個位置是空地 是否可向下移 
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < m*n; i++){ //算連通數量 (就是相異集合的數量) 
		if(find(i) == i){
			ans++;
		}
	}
	if(arr[0] == '.'){  //arr[0] == '.': 如果地圖的起始位置是地板，則直接輸出計算得到的房間數量 ans。
		cout << ans << endl;//因為起始位置是地板，不需要減去任何房間數量。 
	}else {
		cout << ans - 1 << endl;//ans - 1: 如果地圖的起始位置是牆壁，則需要減去一個房間數量，因為起始位置不屬於任何一個房間。
	}							//所以這裡將計算得到的房間數量 ans 減去 1，然後輸出結果。
	return 0;
}
