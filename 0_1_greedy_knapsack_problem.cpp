#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Item {
public:
    int index;
    int weight;
    int value;
    double unitValue;

    Item(int index, int weight, int value) {
        this->index = index;
        this->weight = weight;
        this->value = value;
        this->unitValue = (double)value / weight;
    }
};

bool compareItems(const Item& item1, const Item& item2) {
    return item1.unitValue > item2.unitValue;
}

class Knapsack {
public:
    int maxWeight;
    vector<Item> items;
    vector<int> selectedItems;
    int bestValue;

    Knapsack(int maxWeight, vector<Item> items) {
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

        int remainingWeight = maxWeight;
        for (int i = items.size(); i > 0 && remainingWeight > 0; i--) {
            if (dp[i][remainingWeight] != dp[i - 1][remainingWeight]) {
                selectedItems[i - 1] = 1;
                remainingWeight -= items[i - 1].weight;
            }
        }

        // Output selected item indices
        for (int i = 0; i < selectedItems.size(); i++) {
            if (selectedItems[i] == 1) {
                cout << (items[i].index) << " ";
            }
        }
        cout << endl;

        // Output best value
        cout << dp[items.size()][maxWeight] << "\n";
    }
};

int main() {
    int maxWeight;
    cin >> maxWeight;

    vector<Item> items;
    int index = 0;
    while (true) {
        int itemIndex, weight, value;
        cin >> itemIndex >> weight >> value;
        if (itemIndex == -1 && weight == -1 && value == -1) {
            break;
        }
        items.push_back(Item(itemIndex, weight, value));
       // index++;
    }

    Knapsack knapsack(maxWeight, items);
    knapsack.solve();

    return 0;
}

