class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        // Define a priority queue of type {diff, {row, col}}
        priority_queue<
            pair<int, std::pair<int, int>>,  // Type of the elements in the queue
            vector<std::pair<int, std::pair<int, int>>>,  // Underlying container (vector)
            greater<std::pair<int, std::pair<int, int>>>  // Comparator (min-heap)
        > pq;

        int n = heights.size();
        int m = heights[0].size();

        // Initialize distances with a large value
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;  // Start from the top-left corner
        pq.push({0, {0, 0}});  // Push starting point into the priority queue

        int dr[] = {-1, 0, 1, 0};  // Directions for moving up, right, down, left
        int dc[] = {0, 1, 0, -1};

        // Process the priority queue
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int diff = it.first;  // Current "effort" (diff)
            int row = it.second.first;
            int col = it.second.second;

            // If we've reached the bottom-right corner, return the result
            if (row == n - 1 && col == m - 1) {
                return diff;
            }

            // Explore all four directions
            for (int i = 0; i < 4; i++) {
                int nrow = row + dr[i];
                int ncol = col + dc[i];

                // Ensure the new position is within bounds
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                    // Calculate the effort to move to the next cell
                    int newEffort = max(abs(heights[row][col] - heights[nrow][ncol]), diff);

                    // If the new effort is smaller than the previously recorded effort, update
                    if (newEffort < dist[nrow][ncol]) {
                        dist[nrow][ncol] = newEffort;  // Update the effort to reach (nrow, ncol)
                        pq.push({newEffort, {nrow, ncol}});  // Push new effort and position into the queue
                    }
                }
            }
        }

        return 0;  // Thisd line should never be reached if there's a valid path
    }
};
