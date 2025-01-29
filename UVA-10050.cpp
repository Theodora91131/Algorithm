#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t, dur, party;
    cin >> t;
    while (t--) {
        cin >> dur >> party;
        vector<int>tDay(dur + 1, 0);
        vector<int>h(party, 0);
        for (int i = 0; i < party; ++i) {
            cin >> h[i];
            for (int j = h[i]; j <= dur; j += h[i]) {
                tDay[j] = 1;
            }
        }
        int cnt = 0;
        for (int j = 1; j <= dur; ++j) {
            if (j % 7 == 6 || j % 7 == 0) {
                continue;
            }
            if (tDay[j] == 1) {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}