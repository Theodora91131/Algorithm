#include <bits/stdc++.h>
using namespace std;
struct network{
	int x, y;
};
double distance(network a, network b){
	double x = a.x - b.x;
	double y = a.y - b.y;
	return sqrt(pow(x,2)+pow(y,2))+16;
}
vector <network> p(10);
multimap<double, vector<int>> link; 
vector<int> vis(10,0), save(10);
void dfs(int index, int n){
	if(index == n){
		link.insert({0.0,save});
		return;
	}
	for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            save[index] = i;
            dfs(index + 1, n);
            vis[i] = 0;
        }
    }
}
int main() {
    int n, t = 1;
    while (cin >> n) {
        if (n == 0) break;

        for (int i = 0; i < n; i++) {
            cin >> p[i].x >> p[i].y;
        }

        link.clear();
        dfs(0, n);

        double min_len = 1e9;
        vector<int> best_order;

        for (auto it = link.begin(); it != link.end(); it++) {
            double sum = 0;
            for (int j = 1; j < n; j++) {
                int x1 = p[it->second[j - 1]].x, y1 = p[it->second[j - 1]].y;
                int x2 = p[it->second[j]].x, y2 = p[it->second[j]].y;
                sum += distance({x1, y1}, {x2, y2});
            }
            if (sum < min_len) {
                min_len = sum;
                best_order = it->second;
            }
        }

        cout << "**********************************************************" << endl;
        cout << "Network #" << t++ << endl;
        for (int j = 1; j < n; j++) {
            int x1 = p[best_order[j - 1]].x, y1 = p[best_order[j - 1]].y;
            int x2 = p[best_order[j]].x, y2 = p[best_order[j]].y;
            cout << "Cable requirement to connect (" << x1 << "," << y1 << ") to (" << x2 << "," << y2 << ") is " << fixed << setprecision(2) << distance({x1, y1}, {x2, y2}) << " feet." << endl;
        }
        cout << "Number of feet of cable required is " << fixed << setprecision(2) << min_len << "." << endl;
    }
    return 0;
}
