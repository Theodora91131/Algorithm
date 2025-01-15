#include<bits/stdc++.h>
using namespace std;

int nthSuperUglyNumber(int n, vector<int>& primes) {
    vector<int> superUgly(n, 0);
    vector<int> indices(primes.size(), 0);
    superUgly[0] = 1;

    for (int i = 1; i < n; i++) {
        int min_val = INT_MAX;
        for (int j = 0; j < primes.size(); j++) {
            min_val = min(min_val, primes[j] * superUgly[indices[j]]);
            
        }
		cout << min_val << endl;
        superUgly[i] = min_val;
	
        for (int j = 0; j < primes.size(); j++) {
            if (min_val == primes[j] * superUgly[indices[j]]) {
            	
                indices[j]++;
                
            }
        }
    }

    return superUgly[n - 1];
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> primes(k);

    for (int i = 0; i < k; i++) {
        cin >> primes[i];
    }

    int result = nthSuperUglyNumber(n, primes);
    cout << result << endl;

    return 0;
}

