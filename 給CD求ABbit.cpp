#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int A = 0, B = 0; 
        int C, D;
        cin >> C >> D;

        bool possible = true; 
        bool isFirst = true;

        for (int i = 30; i >= 0; i--) { 
            int c = (C >> i) & 1;
            int d = (D >> i) & 1;

            if (c == 0 && d == 1) {
            	if(isFirst){
            		B |= (1 << i);
            		isFirst = false;
				}else{
					A |= (1 << i);
				}   
            } else if (c == 1 && d == 0) {
                possible = false; 
                break;
            } else if (c == 1 && d == 1) {
                A |= (1 << i);
                B |= (1 << i);
            }
        }

         if (possible) {
            cout << A << " " << B << endl;
        } else {
            cout << "-1" << endl;
        }
    }

    return 0;
}
