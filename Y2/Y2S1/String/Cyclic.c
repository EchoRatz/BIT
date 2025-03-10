#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void generateSmallestNumber(int digits, char *result) {
    result[0] = '1';
    for (int i = 1; i < digits; i++) {
        result[i] = '0';
    }
    result[digits] = '\0';
}

void increment(char *num) {
    int len = strlen(num);
    int carry = 1;
    for (int i = len - 1; i >= 0 && carry; i--) {
        if (num[i] == '9') {
            num[i] = '0';
        } else {
            num[i]++;
            carry = 0;
        }
    }
    if (carry) {
        memmove(num + 1, num, len + 1);
        num[0] = '1';
    }
}

int main() {
    int L;
    char num[100005];

    scanf("%d", &L);
    scanf("%s", num);

    increment(num);

    int len = strlen(num);
    if (len % L != 0) {
        int newLength = ((len / L) + 1) * L;
        generateSmallestNumber(newLength, num);
        len = newLength;
    }

    int sections = len / L;
    char **arr = (char **)malloc(sections * sizeof(char *));
    for (int i = 0; i < sections; i++) {
        arr[i] = (char *)malloc((L + 1) * sizeof(char));
        strncpy(arr[i], num + i * L, L);
        arr[i][L] = '\0';
    }

    for (int i = sections - 1; i > 0; i--) {
        if (strcmp(arr[i], arr[i - 1]) > 0) {
            int carry = 1;
            for (int j = L - 1; j >= 0 && carry; j--) {
                if (arr[i - 1][j] == '9') {
                    arr[i - 1][j] = '0';
                } else {
                    arr[i - 1][j]++;
                    carry = 0;
                }
            }
            for (int j = i; j < sections; j++) {
                strcpy(arr[j], arr[i - 1]);
            }
        }
    }

    char smallest[L + 1];
    generateSmallestNumber(L, smallest);
    if (strcmp(arr[0], smallest) >= 0) {
        for (int i = 0; i < sections; i++) {
            strcpy(arr[i], arr[0]);
        }
    }

    for (int i = 0; i < sections; i++) {
        printf("%s", arr[i]);
    }
    printf("\n");

    for (int i = 0; i < sections; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
