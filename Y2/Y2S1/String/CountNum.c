#include <stdio.h>
#include <string.h>

#define MAX_WORD 1000
#define MAX_LENGTH 21

int main() {
    int n;
    char word[MAX_WORD][MAX_LENGTH];
    int meaningful_count = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", word[i]);

        if (strlen(word[i]) > 10) {
            int is_unique = 1;

            for (int j = 0; j < i; j++) {
                if (strcmp(word[i], word[j]) == 0) {
                    is_unique = 0;
                    break;
                }
            }

            if (is_unique) {
                meaningful_count++;
            }
        }
    }

    printf("%d\n", meaningful_count);

    return 0;
}
