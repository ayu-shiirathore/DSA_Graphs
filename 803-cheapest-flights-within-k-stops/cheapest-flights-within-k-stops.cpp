class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        //creating the adjancency list of the given graph
        for(auto it : flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        //queue as {stops,{node,distance}}
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        // a distance array and initializing them to infinity
        vector<int> dist(n,1e9);
        dist[src]=0;

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if(stops>k)
            continue;

            for(auto iter : adj[node]){
                int adjNode = iter.first;
                int edgeWeight = iter.second;

                if(cost+edgeWeight < dist[adjNode] && stops<=k){
                    dist[adjNode]=cost+edgeWeight;
                    q.push({stops+1,{adjNode,cost+edgeWeight}});
                }
            }
        }

        if(dist[dst]==1e9)
        return -1;

        return dist[dst];
    }
};