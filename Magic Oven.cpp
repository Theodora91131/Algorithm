#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue<long long, vector<long long>, greater<long long>> minHeap;  // 存放第count-n大到第1大的包子
    priority_queue<long long, vector<long long>, less<long long>> maxHeap;     // 存放第count大到第count+n大的包子

    vector<string> output;

    int count = 1;
    int ovencnt = 0;
    for (int i = 0; i < n; ++i) {
        string operation;
        cin >> operation;

        if (operation == "DIOU") {
            long long x;
            cin >> x;

            // 放入 minHeap 或 maxHeap
            if (maxHeap.empty() || x <= maxHeap.top()) {
                maxHeap.push(x);
            } else {
                minHeap.push(x);
            }
			ovencnt++;	
        } else if (operation == "MUMIMUMI") {
            if (count <= 0 || count > ovencnt) {
                output.push_back("BAONU");
            } else {
            	while (minHeap.size() < count - 1) {
                	minHeap.push(maxHeap.top());
                	maxHeap.pop();
            	}
            	while (minHeap.size() > count - 1) {
                	maxHeap.push(minHeap.top());
                	minHeap.pop();
            	}
            	output.push_back(to_string(maxHeap.top()));
            }
            count++;
        } else if (operation == "<3DONGDONG") {
            if (count <= 0 || count > ovencnt) {
                output.push_back("BAONU");
            } else {
            	while (minHeap.size() < count - 1) {
                	minHeap.push(maxHeap.top());
                	maxHeap.pop();
            	}
            	while (minHeap.size() > count - 1) {
                	maxHeap.push(minHeap.top());
                	minHeap.pop();
            	}
            	output.push_back(to_string(maxHeap.top()));
            }
            count--;
        }
    }

    // 輸出結果
    for (const string& result : output) {
        cout << result << endl;
    }

    return 0;
}

