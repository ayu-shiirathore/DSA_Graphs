class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);
        queue<int> q;
        vector<int> ans;

        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }

        for(int i=0; i<numCourses; i++){
            if(indegree[i]==0)
            q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(int i : adj[node]){
                indegree[i]--;
                if(indegree[i]==0)
                q.push(i);
            }
        }

        return ans.size() == numCourses ? ans : vector<int>();
    }
};