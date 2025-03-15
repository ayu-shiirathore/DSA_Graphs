class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int, int>, int>> q;

        // Initialize the visited array with the same size as grid
        int vis[n][m];

        // Populate the queue with all the rotten oranges and mark them as visited
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int num = grid[i][j];
                if (num == 2) {
                    q.push({{i, j}, 0});  // Rotten orange with time 0
                    vis[i][j] = 2;  // Mark it as visited (rotten)
                }
                else if (num == 1) {
                    vis[i][j] = 0;  // Fresh orange, not visited
                }
            }
        }

        int time = 0;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        // Perform BFS
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            time = max(time, t);  // Track the maximum time
            q.pop();

            // Explore all four directions
            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                // Check if the new position is valid and if the orange is fresh
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && vis[nrow][ncol] != 2) {
                    q.push({{nrow, ncol}, t + 1});  // Push the new position with the incremented time
                    vis[nrow][ncol] = 2;  // Mark the fresh orange as rotten
                }
            }
        }

        // Check if there are any fresh oranges left
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && vis[i][j] != 2) {
                    return -1;  // If a fresh orange is not visited, return -1
                }
            }
        }

        return time;  // Return the maximum time taken to rot all oranges
    }
};
