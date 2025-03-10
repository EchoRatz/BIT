#include <stdio.h>
#include <math.h>

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        long long n;
        scanf("%lld", &n);

        int mice_required = (int)ceil(log2(n));

        printf("%d\n", mice_required);
    }

    return 0;
}