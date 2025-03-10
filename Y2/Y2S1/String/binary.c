#include <stdio.h>
#include <string.h>

#define MAX_LEN 100001

void add_binary(char *a, char *b, char *result) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    int carry = 0, sum;
    int i = len_a - 1, j = len_b - 1, k = 0;
    char temp_result[MAX_LEN + 1];

    while (i >= 0 || j >= 0 || carry) {
        sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';

        temp_result[k++] = (sum % 2) + '0';
        carry = sum / 2;
    }

    for (int m = 0; m < k; m++) {
        result[m] = temp_result[k - m - 1];
    }
    result[k] = '\0';
}

void print_addition_format(char *a, char *b, char *result) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    int len_result = strlen(result);

    int padding_a = len_result + 2 - len_a;
    int padding_b = len_result + 2 - len_b - 1;

    for (int i = 0; i < padding_a; i++) {
        printf(" ");
    }
    printf("%s\n", a);

    printf("+");
    for (int i = 0; i < padding_b; i++) {
        printf(" ");
    }
    printf("%s\n", b);

    for (int i = 0; i < len_result + 2; i++) {
        printf("-");
    }
    printf("\n");

    printf("  ");
    printf("%s", result);  // No newline here to prevent extra lines after the last result
}

int main() {
    int T;
    scanf("%d", &T);
    char a[MAX_LEN], b[MAX_LEN], result[MAX_LEN + 1];

    for (int t = 0; t < T; t++) {
        scanf("%s %s", a, b);
        add_binary(a, b, result);
        print_addition_format(a, b, result);
        if (t < T - 1) {
            printf("\n");  // Separate output for each test case except the last
        }
    }

    // Add a final newline after the last result
    printf("\n");

    return 0;
}
