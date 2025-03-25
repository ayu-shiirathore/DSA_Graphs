class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        //creating a distence matrix
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        for(auto it : edges){
            dist[it[0]][it[1]]=it[2];
            dist[it[1]][it[0]] = it[2];
        }

        //marking the distance of every node to itself as 0 ie pairs of {i,i}
        for(int i=0;i<n;i++){
            dist[i][i]=0;
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][k]==INT_MAX || dist[k][j]==INT_MAX)
                    continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        // Count the number of reachable cities within the distance threshold
        int resultCity = -1;
        int minReachableCities = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            int reachableCities = 0;
            for (int j = 0; j < n; j++) {
                if (dist[i][j] <= distanceThreshold) {
                    reachableCities++;
                }
            }
            
            // Update the result city based on the number of reachable cities
            if (reachableCities <= minReachableCities) {
                minReachableCities = reachableCities;
                resultCity = i;
            }
        }
        
        return resultCity;

    }
};