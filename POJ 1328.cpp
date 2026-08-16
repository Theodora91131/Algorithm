#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<limits>

using namespace std;
struct coord{
    double l, r;
    double x, y;
};
bool cmp(coord a, coord b){
    return a.r < b.r;
}
int main(){
    int n, d;
    int case_num = 0;
    while(cin >> n >> d){
        case_num++;
        if(n == 0 && d == 0) break;
        vector<coord> points(n);
        for(int i=0;i<n;i++){
            cin >> points[i].x >> points[i].y;
        }
        bool flag = false;
        for(int i=0;i<n;i++){
            if(points[i].y > d){
                flag = true;
                break;
            }else{
                double len = sqrt(d*d - points[i].y*points[i].y);
                points[i].l = points[i].x - len;
                points[i].r = points[i].x + len;
            }
        }
        if(!flag){
            sort(points.begin(),points.end(),cmp);
            double cur=-1e9;
            int cnt = 0;
            for(int i=0;i<n;i++){
                if(points[i].l>cur){
                    cur = points[i].r;
                    cnt++;
                }
            }
            cout << "Case " << case_num << ": " << cnt << endl;
        
        }else{
            cout << "Case " << case_num << ": "<< -1 << endl;
        }
    }
}