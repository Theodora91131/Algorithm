#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int t, m, d = 0;
    cin >> t;
    vector<string> months = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"};
    vector<string> weeks = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    vector<int> day = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
    for (int i = 0; i < t; ++i)
    {
        cin >> m >> d;

        int dayOfYear = day[m - 1] + d; // 計算當年的第幾天
        int h = (dayOfYear + 5) % 7;    // 2011.1.1星期六
        cout << weeks[h] << endl;
    }

    return 0;
}