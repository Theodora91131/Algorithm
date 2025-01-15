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
            auto it = std::lower_bound(tails.begin(), tails.end(), nums[i]);	//�p�G nums[i] ���j�� tails �����̫�@�Ӥ����A
	        *it = nums[i];														//lower_bound(l, r, x)���϶� [l, r) �d�򤺲Ĥ@�Ӥj�󵥩� x ���Ȫ���m�C
	        																	//���᭱���Ʀr�@�Ӿ��| �h���N�e������   
        }
    }																		//	�h�ݭn���b tails �����J nums[i] ����m�C
																	//	�o�̨ϥΤF std::lower_bound �禡�Ӷi��G���j���A
	std::cout << tails.size() << std::endl;

    return 0;
}																		//	���Ĥ@�Ӥj�󵥩� nums[i] ��������m�A�ñN�Ӧ�m���ȧ�s�� nums[i]�A
																			//	�H�O�� tails �����ǩʡC
  
  
 // �y�y auto it = std::lower_bound(tails.begin(), tails.end(), nums[i]); �ЫؤF�@�ӦW�� it �����N���A�����V tails �}�C������m�A�Ӧ�m���Ȥj��ε��� nums[i]�C

//�M��A�y�y *it = nums[i]; �N nums[i] ���Ƚ�ȵ� it �ҫ��V����m�A�Y�N nums[i] ���J�� tails �}�C�����A���m�C  

