#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long int n, m, i;
    cin >> n >> m;

    vector<long long int> a(n), b(n), x(m);
	vector<long long int> values;
  
    for (i = 0; i < n; i++){
    	cin >> a[i];
        values.push_back(a[i]);
	}
        
    for (i = 0; i < n; i++){
    	cin >> b[i];
        values.push_back(b[i]);
	}
        
    for (i = 0; i < m; i++){
    	cin >> x[i];
		values.push_back(x[i]);
	}
      
    sort(values.begin(), values.end());
    auto unique_end = unique(values.begin(), values.end());
    values.erase(unique_end, values.end());

   
    for (i = 0; i < n; i++) {
        a[i] = lower_bound(values.begin(), values.end(), a[i]) - values.begin();
        b[i] = lower_bound(values.begin(), values.end(), b[i]) - values.begin();
    }
    for (i = 0; i < m; i++)
        x[i] = lower_bound(values.begin(), values.end(), x[i]) - values.begin();

    vector<long long int> prefix_sum(values.size(), 0);
    vector<long long int> sum(values.size(), 0);

    // Main algorithm using prefix sum
    for (i = 0; i < n; i++) {
        prefix_sum[a[i]]++;
        prefix_sum[b[i]]--;
    }

    for (i = 1; i < values.size(); i++) {
        prefix_sum[i] += prefix_sum[i - 1];
        sum[i] += prefix_sum[i - 1] * (values[i] - values[i - 1]);
    }

    for (i = 1; i < values.size(); i++)
        sum[i] += sum[i - 1];

    // Output results
    for (i = 0; i < m - 1; i++)
        cout << sum[x[i]] << " ";
    cout << sum[x[m - 1]] << endl;

    return 0;
}

