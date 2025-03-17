class Solution {
private:
    void dfs(int sr, int sc, vector<vector<int>>& ans, vector<vector<int>>& image, int color, int drow[], int dcol[], int start) {
        ans[sr][sc] = color; // Fill the current pixel with the target color
        
        int n = image.size();
        int m = image[0].size();

        // Explore all 4 possible directions (up, right, down, left)
        for (int i = 0; i < 4; i++) {
            int nrow = sr + drow[i]; // New row
            int ncol = sc + dcol[i]; // New column

            // Check if the new position is within bounds and has the same color as the start
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == start && ans[nrow][ncol] != color) {
                // Call dfs recursively with the new row and column
                dfs(nrow, ncol, ans, image, color, drow, dcol, start);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int startColor = image[sr][sc]; // Store the color at the starting point

        // If the target color is the same as the starting color, no need to do anything
        if (startColor == color) {
            return image;
        }

        // Create a copy of the image to store the result
        vector<vector<int>> ans = image;
        
        // Directions for moving in the 4 cardinal directions (up, right, down, left)
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        
        // Start DFS from the given coordinates (sr, sc)
        dfs(sr, sc, ans, image, color, drow, dcol, startColor);
        
        return ans; // Return the modified image
    }
};
