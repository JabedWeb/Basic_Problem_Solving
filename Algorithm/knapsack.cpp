#include <iostream>
#include <vector>
#include <algorithm>

// Structure to represent an item
struct Item {
    int weight;
    int value;

    Item(int weight, int value) : weight(weight), value(value) {}
};

// Function to solve the knapsack problem
int knapsack(int capacity, const std::vector<Item>& items) {
    int n = items.size();

    // Create a 2D array to store the maximum values
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(capacity + 1, 0));

    // Fill the dp array
    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= capacity; ++w) {
            if (items[i - 1].weight <= w) {
                // Take the maximum value by either including or excluding the item
                dp[i][w] = std::max(items[i - 1].value + dp[i - 1][w - items[i - 1].weight], dp[i - 1][w]);
            } else {
                // Cannot include the item, so just take the value from the previous row
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Return the maximum value
    return dp[n][capacity];
}

int main() {
    int capacity = 10; // Knapsack capacity
    std::vector<Item> items = {Item(2, 6), Item(2, 10), Item(3, 12)};

    int maxValue = knapsack(capacity, items);
    std::cout << "Maximum value: " << maxValue << std::endl;

    return 0;
}
