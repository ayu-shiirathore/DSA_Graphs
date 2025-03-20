class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();

        // Create reverse adjacency list and indegree array
        vector<vector<int>> adjRev(V);
        vector<int> indegree(V, 0);
    
        // Step 1: Build the reversed graph and calculate indegree
        for (int i = 0; i < V; ++i) {
            for (int neighbor : graph[i]) {
                adjRev[neighbor].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        vector<int> safe;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safe.push_back(node);

            for (auto it : adjRev[node]) {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }

        sort(safe.begin(), safe.end());

        return safe;
    }
};
