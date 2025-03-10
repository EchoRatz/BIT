#include <stdio.h>
#include <limits.h>

#define MAX_CUTS 51
#define MAX_LENGTH 1001

int cuts[MAX_CUTS];  // To store the positions of the cuts
int dp[MAX_CUTS][MAX_CUTS];  // DP table to store minimum costs

// Function to find the minimum cost of cutting the stick
int minCutCost(int length, int n) {
    // Initialize DP table
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= n + 1; j++) {
            dp[i][j] = 0;
        }
    }

    // Fill DP table
    for (int len = 2; len <= n + 1; len++) {  // length of the segment being considered
        for (int i = 0; i + len <= n + 1; i++) {
            int j = i + len;
            dp[i][j] = INT_MAX;  // Set an initial large value for minimum cost

            // Try cutting at each position between i and j
            for (int k = i + 1; k < j; k++) {
                int cost = dp[i][k] + dp[k][j] + (cuts[j] - cuts[i]);
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    // The final answer is in dp[0][n+1], which represents cutting the full stick
    return dp[0][n+1];
}

int main() {
    int L, n;
    int case_num = 1;

    while (1) {
        // Read the length of the stick
        scanf("%d", &L);
        if (L == 0) break;  // End of input

        // Read the number of cuts
        scanf("%d", &n);

        // Read the positions of the cuts
        for (int i = 1; i <= n; i++) {
            scanf("%d", &cuts[i]);
        }

        // Add the two ends of the stick to the cuts array
        cuts[0] = 0;
        cuts[n + 1] = L;

        // Find the minimum cost of cutting
        int result = minCutCost(L, n);

        // Output the result
        printf("%d\n", result);
    }

    return 0;
}
