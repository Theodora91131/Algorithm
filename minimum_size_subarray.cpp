#include <iostream>
#include <vector>
#include <limits>

int findMinSubarrayLength(std::vector<int>& nums, int s) {
    int n = nums.size();
    int start = 0;
    int end = 0;
    int sum = 0;
    int min_length = std::numeric_limits<int>::max();

    while (end < n) {
        sum += nums[end];

        while (sum >= s) {
            min_length = std::min(min_length, end - start + 1);
            sum -= nums[start];
            start++;								//²¾°Êµ¡®æªº·§©À 
        }

        end++;
    }

    if (min_length == std::numeric_limits<int>::max()) {
        return 0;
    } else {
        return min_length;
    }
}

int main() {
    int n, s;
    std::cin >> n >> s;
    std::vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }

    int result = findMinSubarrayLength(nums, s);
    std::cout << result << std::endl;

    return 0;
}

