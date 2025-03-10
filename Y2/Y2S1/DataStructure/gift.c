#include <stdio.h>  
#include <stdlib.h>  
  
// Structure to represent a gift with its volume and original index  
typedef struct {  
    int volume;  
    int index;  
} Gift;  
  
// Comparator function for sorting gifts by volume  
int cmp(const void *a, const void *b) {  
    return ((Gift *)a)->volume - ((Gift *)b)->volume;  
}  
  
int main() {  
    int k;  
    scanf("%d", &k);  
  
    if (k <= 0) {  
        // Handle case of no gifts  
        printf("0\n");  
        return 0;  
    }  
  
    Gift *gifts = (Gift *)malloc(k * sizeof(Gift));  
    for (int i = 0; i < k; i++) {  
        scanf("%d", &gifts[i].volume);  
        gifts[i].index = i + 1;  // Storing the 1-based index  
    }  
  
    // Sort the gifts by volume  
    qsort(gifts, k, sizeof(Gift), cmp);  
  
    int *used = (int *)calloc(k, sizeof(int));  // Array to mark whether a gift has been packed  
  
    int **result = (int **)malloc(k * sizeof(int *));  // To store packing plan  
    int *result_sizes = (int *)malloc(k * sizeof(int));  // Number of gifts in each package  
    int package_count = 0;  
  
    // Iterate through gifts and try to pack them  
    for (int i = 0; i < k; i++) {  
        if (used[i]) continue;  // Skip if the gift is already packed  
  
        // Create a new package with this gift  
        result[package_count] = (int *)malloc(2 * sizeof(int));  // Initially allocate for two gifts  
        result_sizes[package_count] = 1;  // Initially, one gift in the package  
        result[package_count][0] = gifts[i].index;  // Add the current gift's index to the package  
        used[i] = 1;  
  
        int current_size = gifts[i].volume;  
  
        // Try to pack other smaller gifts into this package  
        for (int j = i + 1; j < k; j++) {  
            if (!used[j] && gifts[j].volume >= 2 * current_size) {  
                // Pack this gift into the current package  
                result[package_count] = realloc(result[package_count], (result_sizes[package_count] + 1) * sizeof(int));  
                result[package_count][result_sizes[package_count]] = gifts[j].index;  
                result_sizes[package_count]++;  
                used[j] = 1;  
                current_size = gifts[j].volume;  // Update current size to the packed gift  
            }  
        }  
  
        package_count++;  // Move to the next package  
    }  
  
    // Output the number of packages  
    printf("%d\n", package_count);  
  
    // Output each package  
    for (int i = 0; i < package_count; i++) {  
        printf("%d ", result_sizes[i]);  // Number of gifts in the package  
        for (int j = 0; j < result_sizes[i]; j++) {  
            printf("%d ", result[i][j]);  
        }  
        printf("\n");  
        free(result[i]);  // Free the dynamically allocated memory for this package  
    }  
  
    // Free dynamically allocated memory  
    free(gifts);  
    free(used);  
    free(result);  
    free(result_sizes);  
  
    return 0;  
}  