class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        
        // Get the original color at the starting point
        int originalColor = image[sr][sc];

        // If the original color is the same as the target color, no need to fill
        if (originalColor == color) {
            return image;
        }

        // Create a visited vector to keep track of visited cells
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        // Directions for moving up, right, down, left
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        // Queue for BFS
        queue<pair<int, int>> q;
        q.push({sr, sc});
        visited[sr][sc] = true; // Mark the starting point as visited

        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            // Only fill if the current pixel is the original color
            if (image[i][j] == originalColor) {
                image[i][j] = color;
            }

            // Check all 4 directions (up, right, down, left)
            for (int k = 0; k < 4; k++) {
                int row = i + drow[k];
                int col = j + dcol[k];

                // Check if the new position is valid, not visited, and has the original color
                if (row >= 0 && row < n && col >= 0 && col < m && !visited[row][col] && image[row][col] == originalColor) {
                    q.push({row, col});
                    visited[row][col] = true; // Mark this cell as visited
                }
            }
        }

        return image;
    }
};
