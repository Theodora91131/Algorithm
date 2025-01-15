#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int main()
{
    int x;
    string a;
    vector<long long> coef, temp;
    while (cin >> x)
    {
        cin.ignore();
        getline(cin, a);    // a0..a1...an
        stringstream ss(a); // 當字串包含多個數字（可能用空格分隔）時，使用 stringstream 可以輕鬆地將字串中的數字逐一提取
        int num;
        coef.clear();
        temp.clear();
        while (ss >> num)
        {
            temp.push_back(num);
        }
        coef.resize(temp.size(), 0);
        for (int i = 0; i < temp.size(); ++i)
        {
            coef[i] = temp[i];
        }
        coef.pop_back(); // 踢掉第最後一個再reverse
        int n = coef.size();
        long long sum = 0, currentPower = 1;
        reverse(coef.begin(), coef.end()); // 我從an....a0...a1開始做 公式a0*x^n+a1*x^(n-1)
        for (int j = 0; j < n; j++)
        {
            sum += (coef[j] * (j + 1) * currentPower); // pow 無法辨識大於 2^64 的整數浮點值 題目2^31
            currentPower *= x;
        }
        cout << sum << endl;
    }
    return 0;
}