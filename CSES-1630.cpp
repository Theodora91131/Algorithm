#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

struct Job{
    int id;
    int D;
    int F;
};
bool cmp (const Job &a, const Job &b){
    return (long long) a.D < (long long) b.D;
}
int main(){
    int n;
    while(cin>>n){
        vector<Job>jobs(n);
        for(int i=0; i<n; i++){
            int d, f;
            cin >> d >> f;
            jobs[i]={i+1,d,f};
        }
        sort(jobs.begin(),jobs.end(),cmp);
        long long temp=0;
        long reward=0;
        for(int i=0; i<jobs.size();i++){
            temp +=jobs[i].D;
            reward+= jobs[i].F - temp;
        }
        cout << reward << endl;
    }

    return 0;
}