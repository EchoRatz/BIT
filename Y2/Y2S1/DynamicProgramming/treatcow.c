#include <stdio.h>

#define MAX_N 2000

int values[MAX_N];
int dp[MAX_N][MAX_N];

// Function to calculate maximum revenue
int maxRevenue(int n) {
    // Initialize the dp table for all ranges
    for (int len = 1; len <= n; len++) {  // len is the length of the current range
        for (int i = 0; i + len - 1 < n; i++) {  // i is the start of the range
            int j = i + len - 1;  // j is the end of the range
            int age = n - len + 1;  // Current age of the treats

            if (i == j) {
                // Base case: Only one treat in the range
                dp[i][j] = age * values[i];
            } else {
                // Recurrence relation: Choose the optimal choice from both ends
                dp[i][j] = (age * values[i] + dp[i + 1][j] > age * values[j] + dp[i][j - 1])
                               ? age * values[i] + dp[i + 1][j]
                               : age * values[j] + dp[i][j - 1];
            }
        }
    }
    return dp[0][n - 1];  // The maximum revenue for the entire range
}

int main() {
    int n;
    
    // Read the number of treats
    scanf("%d", &n);
    
    // Read the values of the treats
    for (int i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }
    
    // Calculate and output the maximum revenue
    printf("%d\n", maxRevenue(n));
    
    return 0;
}
