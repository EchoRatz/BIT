#include <stdio.h>  
#include <string.h>  
#include <limits.h>  
 
#define MAX_N 16  
#define MAX_M 16  
  
int n, m;  
int grid[MAX_N][MAX_M];  
int press[MAX_N][MAX_M];  
  
int minPresses = INT_MAX;  
  
void toggle(int x, int y) {  
    grid[x][y] ^= 1;  
    if (x > 0) grid[x - 1][y] ^= 1;  
    if (x < n - 1) grid[x + 1][y] ^= 1;  
    if (y > 0) grid[x][y - 1] ^= 1;  
    if (y < m - 1) grid[x][y + 1] ^= 1;  
}  
  
void findMinPresses() {  
    for (int mask = 0; mask < (1 << m); mask++) {  
        int tempGrid[MAX_N][MAX_M];  
        memcpy(tempGrid, grid, sizeof(grid));  
          
        memset(press, 0, sizeof(press));  
          
        for (int j = 0; j < m; j++) {  
            if (mask & (1 << j)) {  
                press[0][j] = 1;  
                toggle(0, j);  
            }  
        }  
          
        for (int i = 1; i < n; i++) {  
            for (int j = 0; j < m; j++) {  
                if (grid[i - 1][j]) {  
                    press[i][j] = 1;  
                    toggle(i, j);  
                }  
            }  
        }  
          
        int isAllOff = 1;  
        for (int j = 0; j < m; j++) {  
            if (grid[n - 1][j]) {  
                isAllOff = 0;  
                break;  
            }  
        }  
          
        if (isAllOff) {  
            int pressCount = 0;  
            for (int i = 0; i < n; i++) {  
                for (int j = 0; j < m; j++) {  
                    pressCount += press[i][j];  
                }  
            }  
            if (pressCount < minPresses) {  
                minPresses = pressCount;  
            }  
        }  
          
        memcpy(grid, tempGrid, sizeof(grid));  
    }  
}  
  
int main() {  
    scanf("%d %d", &n, &m);  
      
    for (int i = 0; i < n; i++) {  
        char line[MAX_M + 1];  
        scanf("%s", line);  
        for (int j = 0; j < m; j++) {  
            grid[i][j] = line[j] - '0';  
        }  
    }  
      
    findMinPresses();  
    printf("%d\n", minPresses);  
      
    return 0;  
}  