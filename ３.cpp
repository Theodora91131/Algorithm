#include <iostream>

using namespace std;

int main() {
    int X, Y, N;
    cin >> X >> Y >> N;

    int total_cost = 0;

    // Calculate the total cost based on the optimal strategy
    int three_apples_cost = (N / 3) * Y;  // Buy three-apple packs
    int remaining_apples = N % 3;  // Buy individual apples

    total_cost = three_apples_cost;

    if (remaining_apples == 1) {
        total_cost += X;
    } else if (remaining_apples == 2) {
        total_cost += min(X * 2, Y);  // Buy either two individual apples or one three-apple pack
    }

    cout << total_cost << endl;

    return 0;
}

