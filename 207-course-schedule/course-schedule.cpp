class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        
        // Build graph and calculate in-degrees
        for(auto& pre : prerequisites) {
            int course = pre[0];
            int prerequisite = pre[1];
            graph[prerequisite].push_back(course);
            indegree[course]++;
        }
        
        // Queue for nodes with 0 in-degree
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        int count = 0; // Count of processed nodes
        while(!q.empty()) {
            int current = q.front();
            q.pop();
            count++;
            
            for(int neighbor : graph[current]) {
                indegree[neighbor]--;
                if(indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        return count == numCourses;
    }
};