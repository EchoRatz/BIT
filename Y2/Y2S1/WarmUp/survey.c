#include <stdio.h>
#include <stdlib.h>

#define MAX_TIME 1000000

int main() {
    int n;
    scanf("%d", &n);

    int *time_line = (int *)calloc(MAX_TIME + 2, sizeof(int)); 

    for (int i = 0; i < n; i++) {
        int s, t;
        scanf("%d %d", &s, &t);
        time_line[s]++; 
        time_line[t + 1]--; 
    }

    int max_people = 0;
    int current_people = 0;

    for (int i = 1; i <= MAX_TIME; i++) {
        current_people += time_line[i];
        if (current_people > max_people) {
            max_people = current_people;
        }
    }

    printf("%d\n", max_people);

    free(time_line);

    return 0;
}