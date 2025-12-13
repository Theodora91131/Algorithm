#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<utility>
using namespace std;
struct Job
{
    int id;
    int A;
    int B;
};
bool cmp(const Job &a, const Job &b){
    return a.B < b.B;
}
int main(){
    int n;
    while (cin >> n)
    {
       vector<Job>jobs(n);
        for (int i=0; i<n; i++){
            int a, b;
            cin >> a >> b;
            jobs[i]={i+1,a,b};
        }
        sort(jobs.begin(),jobs.end(),cmp);
        int temp_A=0;
        bool d = 1;
        for(int i=0; i<n; i++){
            temp_A += jobs[i].A;
            if(temp_A > jobs[i].B){
                d = 0;
                break;
            }

        }
        if(d){
            cout << "Yes" << endl;
            break;
        }{
            cout << "No" << endl;
            break;
        }
    }
    return 0;
}