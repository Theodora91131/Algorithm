#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
	
    std::vector<int> tails;
    tails.push_back(nums[0]);

    for (int i = 1; i < n; i++) {
        if (nums[i] > tails.back()) {																					
            tails.push_back(nums[i]);
          
        } else {
            auto it = std::lower_bound(tails.begin(), tails.end(), nums[i]);	//如果 nums[i] 不大於 tails 中的最後一個元素，
	        *it = nums[i];														//lower_bound(l, r, x)找到區間 [l, r) 範圍內第一個大於等於 x 的值的位置。
	        																	//給後面的數字一個機會 去取代前面的數   
        }
    }																		//	則需要找到在 tails 中插入 nums[i] 的位置。
																	//	這裡使用了 std::lower_bound 函式來進行二分搜索，
	std::cout << tails.size() << std::endl;

    return 0;
}																		//	找到第一個大於等於 nums[i] 的元素位置，並將該位置的值更新為 nums[i]，
																			//	以保持 tails 的有序性。
  
  
 // 語句 auto it = std::lower_bound(tails.begin(), tails.end(), nums[i]); 創建了一個名為 it 的迭代器，它指向 tails 陣列中的位置，該位置的值大於或等於 nums[i]。

//然後，語句 *it = nums[i]; 將 nums[i] 的值賦值給 it 所指向的位置，即將 nums[i] 插入到 tails 陣列中的適當位置。  

