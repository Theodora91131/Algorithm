#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void merge(vector<int> &vec2,int l,int m,int r){
	//cout <<"A[2]" << " ";
	const double max = 50000;
	int iLeft = 0, iRight = 0;

    vector<int> leftArray(vec2.begin()+l, vec2.begin()+m+1), rightArray(vec2.begin()+m+1, vec2.begin()+r+1);
    leftArray.insert(leftArray.end(), max);     
    rightArray.insert(rightArray.end(), max);   
    
    for (int i = l; i <= r; i++) {

        if (leftArray[iLeft] <= rightArray[iRight] ) {
            vec2[i] = leftArray[iLeft];
            iLeft++;
        }
        else{
            vec2[i] = rightArray[iRight];
            iRight++;
        }
    }
    
}
void divide(vector<int> &vec1, int l, int r){
	//cout <<"A[5]" << " ";	
	if(l < r){
		int mid = l + (r - l)/2;
    	divide(vec1, l, mid);
    	divide(vec1, mid + 1, r);
    	merge(vec1, l, mid, r);
    	//cout <<"A[f]" << " ";	
	}
    
   
}
int main(){
    vector<int> A;	
	int a,i =0;
	while(cin>>a){	 
		 A.insert(A.end(), a); 
		char ch = getchar();
		if(ch == '\n')
			break;
	}
	
    divide(A,0, A.size()-1);
	 for(int i=0; i<A.size(); i++)
		cout << A[i] << " ";
	cout << endl;
	return 0;
}
