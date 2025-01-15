#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Item {
public:
    int index;
    int weight;
    int value;

    Item(int index, int weight, int value) {
        this->index = index;
        this->weight = weight;
        this->value = value;
    }
};

bool compareItems(const Item& item1, const Item& item2) {
    return item1.value > item2.value;
}

class Knapsack {
public:
    int maxWeight;
    vector<Item> items;
    vector<int> selectedItems;
    int bestValue;

    Knapsack(int maxWeight, const vector<Item>& items) {
        this->maxWeight = maxWeight;
        this->items = items;
        this->selectedItems.resize(items.size(), 0);
        this->bestValue = 0;
    }

    void solve() {
        sort(items.begin(), items.end(), compareItems);

        vector<vector<int>> dp(items.size() + 1, vector<int>(maxWeight + 1, 0));

        for (int i = 1; i <= items.size(); i++) {
            for (int j = 1; j <= maxWeight; j++) {
                if (items[i - 1].weight <= j) {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - items[i - 1].weight] + items[i - 1].value);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        int i = items.size();
        int j = maxWeight;

        while (i > 0 && j > 0) {
            if (dp[i][j] != dp[i - 1][j]) {
                selectedItems[items[i - 1].index - 1] = 1;
                j -= items[i - 1].weight;
            }
            i--;
        }

        bestValue = dp[items.size()][maxWeight];
    }

    void printSelectedItems() {
        for (int i = 0; i < selectedItems.size(); i++) {
            if (selectedItems[i] == 1) {
                cout << i + 1 << " ";
            }
        }
        cout << endl;
    }

    void printBestValue() {
        cout << bestValue << endl;
    }
};

int main() {
    int capacity;
    cin >> capacity;

    vector<Item> items;
    int index = 1;

    while (true) {
        int itemIndex, weight, value;
        cin >> itemIndex >> weight >> value;

        if (itemIndex == -1 && weight == -1 && value == -1) {
            break;
        }

        items.push_back(Item(itemIndex, weight, value));
    }

    Knapsack knapsack(capacity, items);
    knapsack.solve();

    // Output results
    knapsack.printSelectedItems();
    knapsack.printBestValue();

    return 0;
}

