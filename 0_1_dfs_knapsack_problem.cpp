#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <ctime> 
 
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
    clock_t startTime; 
 
 
    Knapsack(int maxWeight, vector<Item> items) { 
        this->maxWeight = maxWeight; 
        this->items = items; 
        this->selectedItems.resize(items.size(), 0); 
        this->bestValue = 0; 
        this->startTime = clock(); 
     
    } 
 
    void solve() { 
        sort(items.begin(), items.end(), compareItems); 
 
        vector<int> currentSelection(items.size(), 0); 
        dfs(0, currentSelection, 0, 0); 
 
        // Output selected item indices 
        for (int i = 0; i < selectedItems.size(); i++) { 
            if (selectedItems[i] == 1) { 
                cout << (items[i].index) << " "; 
            } 
        } 
        cout << endl; 
 
        // Output best value 
        cout << bestValue << "\n"; 
    } 
 
    void dfs(int index, vector<int>& currentSelection, int currentValue, int currentWeight) { 
        if (currentWeight > maxWeight) { 
            return; 
        } 
 
        if (index == items.size() ) { 
            if (currentValue > bestValue) { 
                bestValue = currentValue; 
                selectedItems = currentSelection; 
            } 
            return; 
        } 
 
        // Select current item 
        currentSelection[index] = 1; 
        dfs(index + 1, currentSelection, currentValue + items[index].value, currentWeight + items[index].weight); 
        currentSelection[index] = 0; 
 
        // Skip current item 
        dfs(index + 1, currentSelection, currentValue, currentWeight); 
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
        index++; 
    } 
 
     
    Knapsack knapsack(maxWeight, items); 
    knapsack.solve(); 
 
    return 0; 
}  
