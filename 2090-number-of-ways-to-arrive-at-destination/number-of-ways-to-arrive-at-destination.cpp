const int MOD = 1e9 + 7;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // Build the adjacency list for the graph
        vector<vector<pair<int, int>>> adj(n);  // adjacency list (node, travel time)
        
        for (const auto& road : roads) {
            int u = road[0], v = road[1], time = road[2];
            // two times because the graph is undirected
            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }
        
        vector<long long> dist(n, LLONG_MAX);  // shortest distance from node 0 to each node
        vector<int> ways(n, 0);  // number of ways to reach each node with the shortest distance
        
        dist[0] = 0;  // starting node has distance 0
        ways[0] = 1;  // there is 1 way to reach node 0 (itself)
        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});  // push the starting node (0) with distance 0
        
        while (!pq.empty()) {
            long long d = pq.top().first;  // current distance
            int node = pq.top().second;  // current node
            pq.pop();
            
            // If the current distance is greater than the stored shortest distance, skip it
            if (d > dist[node]) {
                continue;
            }
            
            // Explore neighbors
            for (const auto& neighbor : adj[node]) {
                int nextNode = neighbor.first;
                int time = neighbor.second;
                
                // If a shorter path is found 
                if (d + time < dist[nextNode]) {  // Use `long long` for addition
                    dist[nextNode] = d + time;
                    ways[nextNode] = ways[node];  // reset the number of ways
                    pq.push({dist[nextNode], nextNode});
                }
                // If the same shortest path is found, increment the number of ways
                else if (d + time == dist[nextNode]) {
                    ways[nextNode] = (ways[nextNode] + ways[node]) % MOD;
                }
            }
        }
        
        // Return the number of ways to reach node n - 1 (destination)
        return ways[n - 1];
    }
};
