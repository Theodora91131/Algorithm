#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int index;
    int weight;
    int value;

    Item(int i, int w, int v) : index(i), weight(w), value(v) {}
};

vector<int> best_first_search_knapsack(int capacity, const vector<Item>& items) {
    vector<int> selectedItems;
    vector<int> indices(items.size());   //用於存儲物品的索引，以便進行排序和後續處理。 
    for (int i = 0; i < indices.size(); i++) {  //將每個位置的值設置為該位置的索引值。這樣可以確保初始時，索引值按順序排列，並且與 items 向量中的物品對應。
        indices[i] = i;
    }

    sort(indices.begin(), indices.end(), [&](int i1, int i2) {
        double valuePerWeight1 = static_cast<double>(items[i1].value) / items[i1].weight;
        double valuePerWeight2 = static_cast<double>(items[i2].value) / items[i2].weight;
        return valuePerWeight1 > valuePerWeight2;
    });

    vector<vector<int>> dp(items.size() + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= items.size(); i++) {
        for (int j = 1; j <= capacity; j++) {
            if (items[indices[i - 1]].weight <= j) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - items[indices[i - 1]].weight] + items[indices[i - 1]].value);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    int i = items.size();
    int j = capacity;

    while (i > 0 && j > 0) {
        if (dp[i][j] != dp[i - 1][j]) {
            selectedItems.push_back(items[indices[i - 1]].index);
            j -= items[indices[i - 1]].weight;
        }
        i--;
    }

    reverse(selectedItems.begin(), selectedItems.end());

    return selectedItems;
}

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

    vector<int> bestItems = best_first_search_knapsack(capacity, items);

    // Output results
    for (int i = 0; i < bestItems.size(); i++) {
        cout << bestItems[i] << " ";
    }
    cout << endl;

    int totalValue = 0;
    for (int i = 0; i < bestItems.size(); i++) {
        totalValue += items[bestItems[i] - 1].value;
    }
    cout << totalValue << endl;

    return 0;
}

