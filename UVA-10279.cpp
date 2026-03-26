#include<bits/stdc++.h>

using namespace std;
int drow[]={-1,-1,-1,0,0,1,1,1};
int dcol[]={-1,0,1,-1,1,-1,0,1};
const int N = 10;
char mine[N][N];
char touch[N][N];
char sumMines[N][N];
int main(){
	int numberOfGame = 0;
	int n;
	cin >> numberOfGame;
	while(numberOfGame--){
		cin >> n;
		memset(sumMines,0,sizeof(sumMines));
		for(int i=0;i<n;i++){
			cin >> mine[i];
		}
		for(int i=0;i<n;i++){
			cin >> touch[i];
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				for(int k=0;k<8;k++){
					int nextRow = i+drow[k];
					int nextCol = j+dcol[k];
					if(nextRow >= 0 && nextCol < n && nextCol >=0 && nextCol<n){
						if(mine[nextRow][nextCol] == '*'){
							sumMines[i][j]++;
						}
					}
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(touch[i][j]=='x'&& mine[i][j] == '*' ){
					touch[i][j] = '*';
				}else if(touch[i][j] == 'x'){
					touch[i][j] = sumMines[i][j] + '0';
				}
			}
		}
		for(int i=0;i<n-1;i++){
			cout << touch[i]<<endl;
		}
		cout << touch[n-1];
	}
	
	return 0;
}