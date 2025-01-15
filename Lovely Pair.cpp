#include <iostream>  
#include <vector>  
#include <queue>  
#include <cmath>  
#include <climits>  
using namespace std;  
  
int main() {  
    int T;  
    cin >> T;  
  
    while (T--) {  
        int n;  
        cin >> n;  
  
        vector<long long> nums(n);  
        for (int i = 0; i < n; i++) {  
            cin >> nums[i];  
        }  
  		if (n == 1) {
            cout << (nums[0] == 0 ? 0 : nums[0]) << endl;
            continue;
        }
        long long maxProduct = INT_MIN;  
        long long currentProduct = 1;  
        int negativeCount = 0; 
        priority_queue<long long, vector <long long>, greater<long long>> minHeap;  
  
        for (int i = 0; i < n; i++) {  
        	if (nums[i] > 0) {  
                currentProduct *= nums[i];  
                maxProduct = max(maxProduct, currentProduct);  
            } else if (nums[i] <= 0) {  
                negativeCount++;  
                minHeap.push(nums[i]);  
            } 
        }  
        int effectiveNegativeCount = 0;  
        if (minHeap.size() != 1 ){  
            effectiveNegativeCount = (negativeCount % 2 == 0) ? negativeCount : negativeCount - 1;  
        }else{  
            effectiveNegativeCount = 1;  
        }  
          
        while (effectiveNegativeCount > 0) {  
            currentProduct *= minHeap.top();  
            minHeap.pop();  
            effectiveNegativeCount--;  
            maxProduct = max(maxProduct, currentProduct);  
        }    
         cout << maxProduct << endl;  
    }  
    return 0;  
}  
