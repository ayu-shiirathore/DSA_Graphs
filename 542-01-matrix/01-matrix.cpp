class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));  // Visited matrix
        vector<vector<int>> dis(n, vector<int>(m, -1)); // Distance matrix, initialized to -1
        queue<pair<int, int>> q;  // Queue to perform BFS
        
        // Step 1: Push all cells with 0 into the queue and mark them as visited
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});  // Push the position of 0 cells
                    vis[i][j] = 1;   // Mark as visited
                    dis[i][j] = 0;   // Distance to nearest 0 is 0
                }
            }
        }

        // Directions for 4 neighbors (up, down, left, right)
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        // Step 2: BFS to fill the distance matrix
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // Explore all 4 neighbors
            for (int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                // Check if the new position is within bounds and not yet visited
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;  // Mark as visited
                    dis[nrow][ncol] = dis[row][col] + 1;  // Update distance
                    q.push({nrow, ncol});  // Add to the queue for further exploration
                }
            }
        }

        return dis;
    }
};