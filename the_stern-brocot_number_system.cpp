#include <iostream>
#include <algorithm>
using namespace std;
struct fraction{
	int M;
	int N;
};

int main(){	
	int f_m,f_n;
	while(cin >> f_m >>f_n && !(f_m ==1 && f_n==1)){
		fraction L={0,1}, M={1,1},R={1,0};
		while(1){
			long double Fd = (long double)f_m/f_n;
			long double Md = (long double)M.M/M.N;
			if(Fd>Md){
				L = M;
				M.M += R.M;
				M.N += R.N;
				printf("R");
			}
			else if(Fd<Md){
				R = M;
				M.M += L.M;
				M.N += L.N;
				printf("L");
			}
			else{               
            	printf("\n");
            	break;
        	}
		}	
	}
	return 0;
}
