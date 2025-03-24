#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Step 1: Create the adjacency list
        vector<vector<pair<int, int>>> adj(n + 1); // adj[i] holds {destination, time}
        
        for (const auto& time : times) {
            int u = time[0], v = time[1], w = time[2];
            adj[u].push_back({v, w});
        }
        
        // Priority Queue stores pairs of {time, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        //Initialize distances array with infinity
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        
        //Push the starting node into the priority queue
        pq.push({0, k});  // (time = 0, node = k)
        
        while (!pq.empty()) {
            int time = pq.top().first;  
            int node = pq.top().second; 
            pq.pop();
            
            // If we have already found a shorter way to this node, skip it
            if (time > dist[node]) {
                continue;
            }
            
            // Explore the neighbors
            for (auto& neighbor : adj[node]) {
                int nextNode = neighbor.first;
                int travelTime = neighbor.second;
                
                // If we find a shorter path to the neighbor
                if (dist[node] + travelTime < dist[nextNode]) {
                    dist[nextNode] = dist[node] + travelTime;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }
        
        //Check if all nodes are reachable and find the maximum time
        int maxTime = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == INT_MAX) {
                return -1;  // Some node is not reachable
            }
            maxTime = max(maxTime, dist[i]);
        }
        
        return maxTime;
    }
};
