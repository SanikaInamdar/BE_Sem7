#include <iostream>
#include <vector>

using namespace std;

// Memoization: Helper function using a 2D vector to store computed values
int knapsackMemo(int W, const vector<int>& weights, const vector<int>& values, int n, vector<vector<int>>& memo) {
    if (n == 0 || W == 0) {
        return 0;
    }

    // Check if the result is already computed and stored in the memo table
    if (memo[n][W] != -1) {
        return memo[n][W];
    }

    // If the current item's weight is greater than the current capacity, skip it
    if (weights[n - 1] > W) {
        return memo[n][W] = knapsackMemo(W, weights, values, n - 1, memo);
    }

    // Choose the maximum value between including and excluding the current item
    int include = values[n - 1] + knapsackMemo(W - weights[n - 1], weights, values, n - 1, memo);
    int exclude = knapsackMemo(W, weights, values, n - 1, memo);

    // Save the result in the memo table and return it
    return memo[n][W] = max(include, exclude);
}

// Tabulation: Function to solve 0-1 Knapsack problem using dynamic programming
int knapsackTabulation(int W, const vector<int>& weights, const vector<int>& values, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= W; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    // Example usage
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int W = 50; // Knapsack capacity

    int n = values.size();

    // Memoization
    vector<vector<int>> memo(n + 1, vector<int>(W + 1, -1));
    int max_value_memo = knapsackMemo(W, weights, values, n, memo);
    cout << "Maximum value using memoization: " << max_value_memo << endl;

    // Tabulation
    int max_value_tabulation = knapsackTabulation(W, weights, values, n);
    cout << "Maximum value using tabulation: " << max_value_tabulation << endl;

    return 0;
}
