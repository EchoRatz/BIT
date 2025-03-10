#include <stdio.h>
#include <string.h>

int count_occurrences(const char *a, const char *b) {
    int count = 0;
    int b_len = strlen(b);

    while ((a = strstr(a, b)) != NULL) {
        count++;
        a += b_len; 
    }

    return count;
}

int main() {
    char a[100];
    char b[100];

    fgets(a, sizeof(a), stdin);
    a[strcspn(a, "\n")] = 0; 

    fgets(b, sizeof(b), stdin);
    b[strcspn(b, "\n")] = 0; 

    int result = count_occurrences(a, b);
    printf("%d\n", result);

    return 0;
}
