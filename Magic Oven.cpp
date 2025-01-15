#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue<long long, vector<long long>, greater<long long>> minHeap;  // �s���count-n�j���1�j���]�l
    priority_queue<long long, vector<long long>, less<long long>> maxHeap;     // �s���count�j���count+n�j���]�l

    vector<string> output;

    int count = 1;
    int ovencnt = 0;
    for (int i = 0; i < n; ++i) {
        string operation;
        cin >> operation;

        if (operation == "DIOU") {
            long long x;
            cin >> x;

            // ��J minHeap �� maxHeap
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

    // ��X���G
    for (const string& result : output) {
        cout << result << endl;
    }

    return 0;
}

