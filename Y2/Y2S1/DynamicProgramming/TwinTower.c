#include <stdio.h>
#include <string.h>

#define MAX_TILES 100

// Function to compute the longest common subsequence (LCS) length
int lcs(int N1, int tower1[], int N2, int tower2[]) {
    int dp[MAX_TILES + 1][MAX_TILES + 1];

    // Initialize the DP table
    for (int i = 0; i <= N1; i++) {
        for (int j = 0; j <= N2; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (tower1[i - 1] == tower2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
            }
        }
    }

    return dp[N1][N2];  // The length of the LCS
}

int main() {
    int N1, N2;
    int tower1[MAX_TILES], tower2[MAX_TILES];
    int case_number = 1;

    while (1) {
        // Read the number of tiles in both towers
        scanf("%d %d", &N1, &N2);

        // If both N1 and N2 are 0, terminate the input
        if (N1 == 0 && N2 == 0) {
            break;
        }

        // Read the tiles for the first tower
        for (int i = 0; i < N1; i++) {
            scanf("%d", &tower1[i]);
        }

        // Read the tiles for the second tower
        for (int i = 0; i < N2; i++) {
            scanf("%d", &tower2[i]);
        }

        // Compute the LCS length
        int result = lcs(N1, tower1, N2, tower2);

        // Output the result
        printf("Twin Towers #%d\n", case_number++);
        printf("Number of Tiles : %d\n", result);
    }

    return 0;
}
