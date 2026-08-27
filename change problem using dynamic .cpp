#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find the minimum number of coins
int minCoins(const vector<int>& coins, int amount) {
    // Create a DP table initialized with a value greater than any possible answer (amount + 1)
    vector<int> dp(amount + 1, amount + 1);
    
    // Base case: 0 coins are needed to make an amount of 0
    dp[0] = 0;

    // Iteratively build up the solution for every amount up to the target
    for (int i = 1; i <= amount; ++i) {
        for (int coin : coins) {
            if (i - coin >= 0) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    // If dp[amount] wasn't updated, it means the amount cannot be formed
    return dp[amount] > amount ? -1 : dp[amount];
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    
    int result = minCoins(coins, amount);
    cout << "Minimum coins required: " << result << endl; // Output: 3 (5 + 5 + 1)
    
    return 0;
}
