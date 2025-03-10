#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct State {
    int x, y, time;
};

int dx[4] = {-1, 1, 0, 0};  // Up, Down, Left, Right movements
int dy[4] = {0, 0, -1, 1};

int bfs(vector<vector<char>>& grid, int n, int m, int k, pair<int, int> start, pair<int, int> end) {
    queue<State> q;
    vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(k, false)));

    q.push({start.first, start.second, 0});  // Start BFS from the starting point with time 0
    visited[start.first][start.second][0] = true;

    while (!q.empty()) {
        State cur = q.front();
        q.pop();

        int x = cur.x, y = cur.y, t = cur.time;

        // Check if we reached the exit
        if (x == end.first && y == end.second) {
            return t;  // Return the time when we reached the exit
        }

        // Try all 4 possible movements (up, down, left, right)
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int next_time = t + 1;

            // Check if the new position is within bounds
            if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                // Check if it's a wall
                if (grid[nx][ny] == '#') continue;

                // Check if it's a monster, but we can move only if it's disappeared at time next_time
                if (grid[nx][ny] == '*' && (next_time % k != 0)) continue;

                // Check if this state has been visited at this time modulo k
                if (!visited[nx][ny][next_time % k]) {
                    visited[nx][ny][next_time % k] = true;
                    q.push({nx, ny, next_time});
                }
            }
        }
    }

    // If we exit the loop, it means we didn't find a way to the exit
    return -1;
}

int main() {
    int T;
    cin >> T;  // Number of test cases

    while (T--) {
        int n, m, k;
        cin >> n >> m >> k;  // Grid dimensions and monster disappearance interval

        vector<vector<char>> grid(n, vector<char>(m));
        pair<int, int> start, end;

        // Read the grid and locate start (S) and end (E)
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> grid[i][j];
                if (grid[i][j] == 'S') {
                    start = {i, j};
                }
                if (grid[i][j] == 'E') {
                    end = {i, j};
                }
            }
        }

        // Perform BFS to find the shortest path
        int result = bfs(grid, n, m, k, start, end);

        // Output the result for this test case
        cout << result << endl;
    }

    return 0;
}
