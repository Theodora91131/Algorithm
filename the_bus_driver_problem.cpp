#include <iostream>       
#include <algorithm>   
using namespace std;
int main(){  
	int n, d, r;
	int morning[101], evening[101];
	
	while((cin >> n >> d >> r )&& n != 0 && d!=0 && r!= 0){
		for (int i = 0; i < n; ++i){
			cin >> morning[i];
		} 
        for (int i = 0; i < n; ++i){
        	cin >> evening[i];
		} 
		sort(morning,morning+n);
		sort(evening,evening+n);
		int flat = 0;
		for(int i = 0; i < n; i++) 
			if(morning[i] + evening[n-i-1] > d)
				flat += morning[i] + evening[n-i-1] - d;
		cout << flat*r<<endl;
	}
	return 0;
}
