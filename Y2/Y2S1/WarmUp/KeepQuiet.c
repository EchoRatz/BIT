#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    if(n == 1) {
        printf("1\n");
    }
    else if(n > 1) {
        printf("%d\n", n/2);
    }
    return 0;
}
