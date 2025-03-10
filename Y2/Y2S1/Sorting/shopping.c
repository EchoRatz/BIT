#include <stdio.h>  
 
#define MAX_SHOPS 200000  
  
int main() {  
    int n;  
    scanf("%d", &n);  
  
    int l[MAX_SHOPS], r[MAX_SHOPS];  
    int L_min = 1000000000, R_max = 0;  
    int L2_min = 1000000000, R2_max = 0;  
    int L_min_index = -1, R_max_index = -1;  
  
    for (int i = 0; i < n; i++) {  
        scanf("%d %d", &l[i], &r[i]);  
  
        if (l[i] < L_min) {  
            L2_min = L_min;  
            L_min = l[i];  
            L_min_index = i;  
        } else if (l[i] < L2_min) {  
            L2_min = l[i];  
        }  
  
        if (r[i] > R_max) {  
            R2_max = R_max;  
            R_max = r[i];  
            R_max_index = i;  
        } else if (r[i] > R2_max) {  
            R2_max = r[i];  
        }  
    }  
  
    for (int i = 0; i < n; i++) {  
        int L_current = (i == L_min_index) ? L2_min : L_min;  
        int R_current = (i == R_max_index) ? R2_max : R_max;  
  
        if (L_current <= R_current) {  
            printf("%d\n", i + 1);  
            return 0;  
        }  
    }  
  
    printf("-1\n");  
    return 0;  
}  