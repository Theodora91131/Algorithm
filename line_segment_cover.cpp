#include <iostream>  
#include <vector>  
#include <algorithm>  
using namespace std;  
  
 bool cmp(pair<int,int> p1, pair<int,int> p2) {  
     if(p1.first == p2.first) {  
         return p2.second > p1.second;  
     } else {  
         return p2.first > p1.first;  
     }  
 }  
  
int main() {     
    int n, a;  
    cin >> n;  
  
    while(n--) {  
        cin >> a;  
        vector<pair<int,int>> points(a);  
        for(int i = 0; i < a; i++) {  
           cin >> points[i].first >> points[i].second;  
        }  
        sort(points.begin(), points.end());  
          
        int length = 0,end = -1;  
        for(int i = 0; i < points.size(); i++) {  
            int s = points[i].first;  
            int e = points[i].second; 
           
            if(s > end){
			 	length += (e -s);
			 	end = e;
			}else if(e > end){
				length += (e - end);
				end = e;
			 
			}
		}
			cout << length << endl;              
        }
		 return 0;      
    }  
      
     
  
