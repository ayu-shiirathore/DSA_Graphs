class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;  // number of courses (vertices)
        vector<vector<int>> adj(V);  // adjacency list
       
        // create adjacency list
        for (auto& prereq : prerequisites) {
            adj[prereq[1]].push_back(prereq[0]);  // prereq[1] must come before prereq[0]
        }

        vector<int> indegree(V, 0);  // indegree count array
        for (int i = 0; i < V; i++) {
            for (auto& neighbor : adj[i]) {
                indegree[neighbor]++;
            }
        }

        queue<int> q;
        // pushing all elements with indegree=0 into the queue
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            // now reduce the indegree of neighbors
            for (auto& neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

    
        if(topo.size() == V)
        return topo;

        return {};

    }
};