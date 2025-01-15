#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;

int main() {
    string n, m;
    int tmp, totalGas = 0, totalCost = 0, tank = 0, start = 0;
    
    getline(cin,n);
    getline(cin,m);
    istringstream ss(n);
    istringstream yy(m);
    vector<int> gas;
    vector<int> cost;
    while(ss >> tmp) {
        gas.push_back(tmp);
    }
    while(yy >> tmp) {
        cost.push_back(tmp);
    }

    for(int i = 0; i < gas.size(); i++) {
    	
        totalGas += gas[i];
        totalCost += cost[i];
        
        tank += gas[i] - cost[i];
        
        if(tank < 0) {
            start = i + 1;
            tank = 0;
        }
    }

    if(totalGas < totalCost) {
        cout << "-1" << endl; 
    } else {
        cout << start << endl;
    }

    return 0;
}


