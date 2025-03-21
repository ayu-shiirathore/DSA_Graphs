class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // Edge case: if start or end are blocked, return -1
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) {
            return -1;
        }

        // Directions for 8 neighbors (up, down, left, right, and diagonals)
        int dr[] = {-1, 0, 1, 0, -1, -1, 1, 1};
        int dc[] = {0, 1, 0, -1, -1, 1, 1, -1};

        // Distance matrix to keep track of the shortest path to each cell
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        
        // Initialize BFS
        queue<pair<int, pair<int, int>>> q; 
        dist[0][0] = 1; // Starting point, count as 1 because it's part of the path
        q.push({1, {0, 0}}); // Queue stores (distance, {row, col})

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;

            // If we've reached the bottom-right corner, return the distance
            if (r == n - 1 && c == n - 1) {
                return dis;
            }

            // Check all 8 possible directions
            for (int i = 0; i < 8; i++) {
                int nrow = r + dr[i];
                int ncol = c + dc[i];

                // Check bounds and if the cell is open (0)
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 0) {
                    // If this cell has not been visited or can be reached with a shorter path
                    if (dis + 1 < dist[nrow][ncol]) {
                        dist[nrow][ncol] = dis + 1;
                        q.push({dis + 1, {nrow, ncol}});
                    }
                }
            }
        }

        return -1;
    }
};
