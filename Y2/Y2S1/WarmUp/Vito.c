#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int r;
        scanf("%d", &r);

        int *streets = (int *)malloc(r * sizeof(int));
        
        for (int i = 0; i < r; i++) {
            scanf("%d", &streets[i]);
        }
       
        qsort(streets, r, sizeof(int), compare);

        int median = streets[r / 2];

        int total_distance = 0;
        for (int i = 0; i < r; i++) {
            total_distance += abs(streets[i] - median);
        }

        printf("%d\n", total_distance);

        free(streets);
    }

    return 0;
}
