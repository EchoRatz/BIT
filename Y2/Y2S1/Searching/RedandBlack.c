#include <stdio.h>
#include <string.h>

#define MAX_W 20
#define MAX_H 20

char grid[MAX_H][MAX_W];  // Grid to store the tiles
int visited[MAX_H][MAX_W];  // To mark if a tile has been visited
int W, H;  // Width and Height of the grid

// Directions for moving (right, left, down, up)
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

// Check if the next position is within bounds and is a black tile
int is_valid(int x, int y) {
    return x >= 0 && x < W && y >= 0 && y < H && !visited[y][x] && grid[y][x] == '.';
}

// DFS function to explore reachable black tiles
int dfs(int x, int y) {
    visited[y][x] = 1;
    int count = 1;  // Count this tile

    // Explore all four directions
    for (int i = 0; i < 4; i++) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if (is_valid(new_x, new_y)) {
            count += dfs(new_x, new_y);  // Recursively explore the next tile
        }
    }
    return count;
}

int main() {
    while (1) {
        scanf("%d %d", &W, &H);

        // End condition
        if (W == 0 && H == 0) {
            break;
        }

        // Read the grid and locate the starting position
        int start_x = -1, start_y = -1;
        for (int i = 0; i < H; i++) {
            scanf("%s", grid[i]);
            for (int j = 0; j < W; j++) {
                if (grid[i][j] == '@') {
                    start_x = j;
                    start_y = i;
                    grid[i][j] = '.';  // Mark the start as a black tile
                }
            }
        }

        // Reset visited array
        memset(visited, 0, sizeof(visited));

        // Perform DFS from the starting position
        int result = dfs(start_x, start_y);

        // Output the result
        printf("%d\n", result);
    }

    return 0;
}
