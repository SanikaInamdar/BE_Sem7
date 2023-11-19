#include <iostream>
#include <vector>

using namespace std;

int knapsack(int W, int ind, vector<int>&weights, vector<int>&values, vector<vector<int>>&dp){
    if(ind<0 or W==0){
        return 0;
    }
    if(dp[ind][W]!=-1){
        return dp[ind][W];
    }
    int notake=knapsack(W, ind-1, weights, values, dp);
    int take=0;
    if(weights[ind]<=W){
        take=values[ind]+knapsack(W-weights[ind], ind-1, weights, values, dp);
    }
    return dp[ind][W] = max(take, notake);
}

int main() {
    // Example usage
    vector<int> values = { 300, 150, 120, 100, 90, 80 };
    vector<int> weights = { 6, 3, 3, 2, 2, 2 };
    int W = 10; // Knapsack capacity

    int N = values.size();

    // Memoization
    vector<vector<int>> dp(N , vector<int>(W + 1, -1));
    int max_value_dp = knapsack(W, N-1, weights, values, dp);
    cout << "Maximum value using memoization: " << max_value_dp << endl;

    return 0;
}
// Time Complexity: O(N*W)

// Reason: There are N*W states therefore at max ‘N*W’ new problems will be solved.

// Space Complexity: O(N*W) + O(N)