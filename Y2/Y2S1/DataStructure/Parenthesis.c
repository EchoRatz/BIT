#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
 
#define MAX_N 100001  
#define MAX_LEN 100001  
  
// Function to calculate imbalance of a sequence  
void calculateImbalance(char *s, int *left_count, int *right_count) {  
    int n = strlen(s);  
    int balance = 0;  
    for (int i = 0; i < n; i++) {  
        if (s[i] == '(') {  
            balance++;  
        } else {  
            if (balance > 0) {  
                balance--;  
            } else {  
                (*right_count)++;  
            }  
        }  
    }  
    *left_count = balance;  // The remaining unbalanced '(' after processing  
}  
  
int main() {  
    int n;  
    scanf("%d", &n);  
  
    // Arrays to count the left and right imbalances  
    int left_imbalance[MAX_N] = {0};  
    int right_imbalance[MAX_N] = {0};  
  
    // Count of exact matches  
    int valid_pairs = 0;  
  
    for (int i = 0; i < n; i++) {  
        char s[MAX_LEN];  
        scanf("%s", s);  
  
        int left_count = 0, right_count = 0;  
        calculateImbalance(s, &left_count, &right_count);  
  
        if (left_count == 0 && right_count == 0) {  
            // Balanced sequences  
            valid_pairs++;  
        } else if (left_count > 0 && right_count == 0) {  
            // Left-leaning sequences  
            left_imbalance[left_count]++;  
        } else if (right_count > 0 && left_count == 0) {  
            // Right-leaning sequences  
            right_imbalance[right_count]++;  
        }  
    }  
  
    int total_pairs = valid_pairs / 2;  // Each balanced sequence can form a pair  
  
    // Pair left-leaning and right-leaning sequences  
    for (int i = 1; i < MAX_N; i++) {  
        total_pairs += (left_imbalance[i] < right_imbalance[i] ? left_imbalance[i] : right_imbalance[i]);  
    }  
  
    printf("%d\n", total_pairs);  
    return 0;  
}  