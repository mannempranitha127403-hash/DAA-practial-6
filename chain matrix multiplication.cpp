#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Function to find the minimum number of scalar multiplications
int matrixChainOrder(const vector<int>& p) {
    int n = p.size() - 1; // Number of matrices
    
    // dp[i][j] stores the minimum multiplication cost for matrices Mi...Mj
    // Row 0 and Column 0 are left unused for simpler 1-based indexing mapping
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    // l is the chain length (l=2 means multiplying 2 adjacent matrices)
    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;

            // Try all possible split positions 'k' between i and j-1
            for (int k = i; k < j; k++) {
                // Cost = cost of left sub-chain + cost of right sub-chain + cost of multiplying results
                int cost = dp[i][k] + dp[k + 1][j] + (p[i - 1] * p[k] * p[j]);
                
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    // The result for the entire chain of matrices (M1 to Mn) is stored here
    return dp[1][n];
}

int main() {
    // Example: 3 matrices with dimensions:
    // A: 10x20, B: 20x30, C: 30x40
    vector<int> dimensions = {10, 20, 30, 40};
    
    int minOps = matrixChainOrder(dimensions);
    
    cout << "Minimum number of multiplications is: " << minOps << endl;
    
    return 0;
}
