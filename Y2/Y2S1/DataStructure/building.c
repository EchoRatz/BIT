#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR 1000001 // Maximum number of possible colors
#define MAX_BUILDINGS 1000000 // Maximum number of buildings

// Global variables
int color[MAX_BUILDINGS];   // Array to store the color of each building
int height[MAX_BUILDINGS];  // Array to store the height of each building
int col[MAX_COLOR];         // Array to store the count of each color in the current view
int index_[MAX_BUILDINGS];  // Stack to maintain the indices of buildings
int top = -1;               // Top of the stack (index)

int main() {
    int cases;
    
    // Read the number of test cases
    scanf("%d", &cases);
    
    while (cases--) {
        int num;
        
        // Read the number of buildings in the current test case
        scanf("%d", &num);
        
        // Reset stack and color counts for the current test case
        top = -1;
        memset(col, 0, sizeof(col)); // Reset color counts

        // Read the colors of the buildings
        for (int i = 0; i < num; ++i) {
            scanf("%d", &color[i]);
        }

        // Read the heights of the buildings
        for (int i = 0; i < num; ++i) {
            scanf("%d", &height[i]);
        }

        int num_c = 0; // Initialize distinct color count

        // Process each building one by one
        for (int i = 0; i < num; ++i) {
            // Maintain the monotonic stack (decreasing heights)
            while (top >= 0 && height[index_[top]] <= height[i]) {
                int top_idx = index_[top];
                top--; // Pop from stack

                // Decrease the color count of the popped building's color
                if (--col[color[top_idx]] == 0) {
                    num_c--; // Reduce distinct color count if no more buildings of this color are visible
                }
            }

            // If this color is appearing for the first time, increase distinct color count
            if (col[color[i]]++ == 0) {
                num_c++;
            }

            // Push the current building index to the stack
            index_[++top] = i;

            // Output the result for each building except the last one
            if (i < num - 1) {
                printf("%d ", num_c);
            }
        }

        // End of the test case output
        printf("%d\n", num_c); // Print the last one without trailing space
    }

    return 0;
}
