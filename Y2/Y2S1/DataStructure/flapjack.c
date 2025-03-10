#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PANCAKES 30

// Function to flip the pancakes from top to position i
void flip(int *stack, int n, int i) {
    for (int start = 0, end = i; start < end; start++, end--) {
        int temp = stack[start];
        stack[start] = stack[end];
        stack[end] = temp;
    }
}

// Function to find the position of the maximum pancake in the unsorted part of the stack
int findMax(int *stack, int n) {
    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (stack[i] > stack[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

int main() {
    char line[256];
    
    // Process input stacks until EOF
    while (fgets(line, sizeof(line), stdin) != NULL) {
        int stack[MAX_PANCAKES];
        int n = 0;

        // Read the stack from input
        char *token = strtok(line, " ");
        while (token != NULL) {
            stack[n++] = atoi(token);
            token = strtok(NULL, " ");
        }

        // Output the initial stack
        for (int i = 0; i < n; i++) {
            if (i > 0) printf(" ");
            printf("%d", stack[i]);
        }
        printf("\n");

        // Flip sequence
        for (int currSize = n; currSize > 1; currSize--) {
            // Find the maximum pancake in the unsorted part of the stack
            int maxIndex = findMax(stack, currSize);

            // If the maximum pancake is not already in its correct place, flip it
            if (maxIndex != currSize - 1) {
                // If the maximum pancake is not already at the top, bring it to the top
                if (maxIndex != 0) {
                    printf("%d ", n - maxIndex);
                    flip(stack, currSize, maxIndex);
                }

                // Now flip it to its correct position
                printf("%d ", n - (currSize - 1));
                flip(stack, currSize, currSize - 1);
            }
        }

        // End the sequence with 0
        printf("0\n");
    }

    return 0;
}
